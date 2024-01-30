#include<stdio.h>

#include<string.h>

#include<ctype.h>

#include<windows.h>



void registration();

void login();

void main_menu();

void add_result();

void view_results();

void delete_account();

float cgpa_counter(float rr);

float work_day, assessment, markof_assessment, class_test, markof_class_test;





int main()

{

	int trace=fopen("Course_Code","r");

	if(!trace) registration();

	else login();

}

//main ends





void registration ()

{

	printf("\n");

	for(int i=0; i<40; i++)

	{

    	printf("-");

    	static int initial_sleep = 160;

    	sleep(initial_sleep);

    	initial_sleep -= 4;

	}



	printf("\n\t\tTHIS PROGRAM HAS BEEN FIRST TIME EXECUTED\n");

	sleep(1500);

	printf("\t\tPLEASE TAKE A FEW MINUTES TO COMPLETE REGISTRATION\n");

	sleep(1700);

	printf("\n\t\t\t(REGISTRATION)\n");

	sleep(400);



	int course_code;



step_course_code_retake:

	printf(" YOUR COURSE CODE : ");

	scanf("%i",&course_code);



	switch(course_code)

	{

	case 1101:

    	printf("\t\t\tINFORMATION TECHNOLOGY FUNDAMENTALS\n\n");

    	break;

	case 1103:

    	printf("\t\t\tINTRODUCTION TO PROGRAMMING ENVIROMENT\n\n");

    	break;

	case 1105:

    	printf("\t\t\tELECTRIC CIRCUITS\n\n");

    	break;

	case 1107:

    	printf("\t\t\tDIFFERENTIAL AND INTEGRAL CALCULUS\n\n");

    	break;

	case 1109:

    	printf("\t\t\tCOMMUNICATIVE ENGLISH\n\n");

    	break;

	default:

	{

    	printf("\t\t\tINVALID COURSE CODE\n");

    	goto step_course_code_retake;

	}

	}// course code input completed



	FILE *pt;

	pt=fopen("Course_Code","w");

	fprintf(pt,"%i",course_code);

	fclose(pt);



step_enter_pass:

	printf("   CHOOSE YOUR PASSWORD (AlphaNumeric) : ");

	char password[30];

	char re_password[30];

	scanf("%s",password);

	printf("  CONFIRM YOUR PASSWORD            	: ");

	scanf("%s",re_password);

	if(strcmp(password, re_password) == 0)

	{

    	printf("\nPASSWORD MATCHED.\nREMEMBER THIS FOR LOGIN.\n\n\n");



    	//encrypting the password

    	int random = (rand())%14;

    	for(int i=0; (int)(password[i])>32 && (int)(password[i])<127; i++)

    	{

        	password[i] = (char)(password[i]-random);

    	}



    	pt = fopen("Random","w");

    	fprintf(pt,"%i",random);

    	fclose(pt);

    	//encrypting the password ends



    	pt=fopen("Identifier_Key","w");

    	fprintf(pt,"%s", password);

    	fclose(pt);



    	system("pause");

    	printf("\n");

    	printf("%60s","HOW MANY CLASSES DID YOU TAKE IN THIS SEMESTER ?  : ");

    	scanf("%f",&work_day);

    	printf("%60s","NUMBER OF CLASS ASSESSMENT TAKEN : ");

    	scanf("%f",&assessment);

        printf("%60s","TOTAL MARK ON EACH CLASS ASSESSMENT  : ");

    	scanf("%f",&markof_assessment);

    	printf("%60s","NUMBER OF CLASS TEST TAKEN : ");

    	scanf("%f",&class_test);

    	printf("%60s","TOTAL MARK ON EACH CLASS TEST : ");

    	scanf("%f",&markof_class_test);



    	pt=fopen("Teacher_Details","w");

    	fprintf(pt,"%2.2f  %2.2f  %2.2f %2.2f %2.2f",work_day,class_test,markof_class_test,assessment,markof_assessment);

    	fclose(pt);

    	main_menu();

	}

	else

	{

    	printf("PASSWORD HAS NOT MATCHED.\n");

    	sleep(500);

    	printf("ENTER SAME PASSWORD TWICE TO CONFIRM.\n\n");

    	sleep(1000);

    	goto step_enter_pass;

	}

}

//registration ends





void login()

{

	printf("\t\t\t\t(LOG IN)\n	\t\t\tYOUR COURSE CODE IS : ");

	char input_password[30];

	FILE *pt;

	pt=fopen("Course_Code","r");

	char course_code[30];

	fscanf(pt,"%s",course_code);

	fprintf(stdout,"%s",course_code);

	fclose(pt);



	pt=fopen("Identifier_Key","r");

	char retrieved_password[30];

	fscanf(pt,"%[^\n]",retrieved_password);

	fclose(pt);



	//decrypting the password

	int random;

	pt=fopen("Random","r");

	fscanf(pt,"%i",&random);

	fclose(pt);



	for(int i=0; (int)(retrieved_password[i])>32 && (int)(retrieved_password[i])<127; i++)

	{

    	retrieved_password[i] = (char)(retrieved_password[i]+random);

	}

	//decrypting the password ends



stepinvalidpassword:

	printf("\n\t\t\tENTER YOUR PASSWORD : ");

	scanf("%s",input_password);

	if(strcmp(input_password,retrieved_password)==0)

	{

    	printf("\n SUCCESFULLY LOGGED IN.\n");

	}

	else

	{

    	printf("WRONG PASSWORD");


	}

	main_menu();



}

//login ends





void main_menu()

{

	printf("\t\t\t\t");

	system("pause");



	printf("%80s","_________________________________");

	sleep(500);

	printf("%80s","_________________________________");

	sleep(250);

	printf("%80s","_________________________________");

	sleep(50);

	printf("%75s","ADD A RESULT [1]\n");

	sleep(120);

	printf("%75s","VIEW RESULTS [2]\n");

	sleep(100);

	printf("%75s","DELETE MY ACCOUNT [3]\n");

	sleep(75);

	printf("%75s","EXIT [4]\n");

	sleep(45);

	printf("%72s","ENTER YOUR CHOICE : ");

	int choice;

	scanf("%i",&choice);

	printf("%80s","_________________________________");

	sleep(150);

	printf("%80s","_________________________________");

	sleep(150);

	printf("%80s","_________________________________");



	switch(choice)

	{

	case 1 :

    	add_result();

    	main_menu();

    	break;



	case 2:

    	view_results();

    	main_menu();

    	break;

	case 3:

    	delete_account();

    	break;

	case  4:

    	break;

	default:

    	printf("\t\t\t\tError: Validate your choice\n");

    	main_menu();

	}

}

//main menu ends





void add_result()

{

	printf(     "\n%30.30s","ENTER ENLISTED ROLL : ");

	int roll;

	scanf("%i",&roll);



	if(roll>=1671 && roll<=1730)

	{

    	FILE *pt;

    	pt =fopen("Teacher_Details","r");

    	fscanf(pt,"%f %f %f %f %f",&work_day,&class_test,&markof_class_test,&assessment,&markof_assessment);

    	fclose(pt);



    	char first_name[25], last_name[25];

    	printf("%30.30s","ENTER FIRST NAME : ");

    	scanf("%s",first_name);

    	printf("%30.30s","ENTER LAST NAME : ");

    	scanf("%s",last_name);



    	//calculating attendance mark starts

    	float present_day;

    	for(int i=0; i<1; i++)

    	{

        	printf("%30.30s","TOTAL DAYS ATTENDED : ");

        	scanf("%f",&present_day);

        	if(present_day>work_day)

        	{

            	i--;

            	printf("%3.0f classes hadn't held on this semester.\n",present_day);

        	}

    	}

    	float attendance_mark = ((present_day/work_day)*10);





    	float score;

    	//calculating assesment mark starts

    	static float marks_scored_in_assesment=0;



    	for(int i=0; i<assessment; i++)

    	{

        	printf("%30.30s","     	ASSESMENT NO : ");

        	printf("[%i]   	MARKS OBTAINED : ",i+1);

        	scanf("%f",&score);

        	if(score>markof_assessment)

        	{

            	printf("%3.0f %-s\n",score," is greater than total marks.");

            	i--;

        	}

        	else marks_scored_in_assesment = marks_scored_in_assesment + score;

    	}



    	float total_marks_in_assesment=(assessment* markof_assessment);

    	float assessment_mark;

    	assessment_mark=((marks_scored_in_assesment/total_marks_in_assesment)*10);



    	sleep(50);

    	printf("\t\t\t\t\t-------------------\n");



    	//calculating ct marks starts

    	static float marks_scored_in_ct=0;



    	for(int i=0; i<class_test; i++)

    	{

        	printf("%30.30s","   	CLASS TEST NO : ");

        	printf("[%i]   	MARKS OBTAINED : ",i+2);

        	scanf("%f",&score);

        	if(score>markof_class_test)

        	{

            	printf("%3.0f %-s\n",score," is greater than total marks.");

            	i--;

        	}

        	else marks_scored_in_ct = marks_scored_in_ct + score;

    	}



    	float total_marks_in_ct=(class_test*markof_class_test);

    	float ct_mark;

    	ct_mark=((marks_scored_in_ct/total_marks_in_ct)*100);



    	//calculating semester end exam starts

    	for(int i=0; i<1; i++)

    	{

        	printf("\n\tSEMESTER END EXAM   : ");

        	scanf("%f", &score);

        	if(score>100)

        	{

            	printf("%-s","TOTAL MARKS ON SEMESTER EXAM WAS 100.");

            	i--;

        	}

    	}



    	float semester_end_exam_mark;

    	semester_end_exam_mark = (60*score/100);



    	float obtained_mark = attendance_mark + assessment_mark + ct_mark + semester_end_exam_mark;

    	float CGPA = cgpa_counter(obtained_mark);

    	printline();

    	printline();



    	sleep(100);

    	printf("%50.50s%s %s\n", "NAME : ", first_name, last_name);

    	sleep(200);

    	printf("%50.50s%i\n","ROLL : ", roll);

    	sleep(190);

    	printf("%50.50s%2.2f\n","CGPA : ", CGPA);

    	sleep(175);

    	printf("%50.50s%2.2f /(60%)\n","SEMESTER END EXAM : ", semester_end_exam_mark);

    	sleep(155);

    	printf("%50.50s%2.2f /(20%)\n","CLASS TEST : ", ct_mark);

    	sleep(130);

    	printf("%50.50s%2.2f /(10%)\n","ASSESSMENT MARK : ", assessment_mark);

    	sleep(100);

    	printf("%50.50s%2.2f /(10%)\n","ATTENDANCE : ", attendance_mark);



    	char  roll_string[6];

    	itoa(roll,roll_string,10);

    	remove(roll_string);

    	pt=fopen(roll_string,"w");



    	char name_concatenated[100];

    	strcpy(name_concatenated," ");

    	strcat(strcat(strcat(name_concatenated,first_name)," "),last_name);



    	fprintf(pt,"%i  %-18.18s  CGPA:%2.2f  SE:%2.2f  Tuto:%2.2f  Asse:%2.2f  Att:%2.2f",roll, name_concatenated, CGPA, semester_end_exam_mark, ct_mark,assessment_mark, attendance_mark);

    	fclose(pt);

    	printf("\t\t\t");

    	printline();

    	printf("\n 	%50.50s\n","File Saved Successfully.");

	}

	else

	{

    	printf("Students were enlisted between roll 1671 and 1730.\n");

    	add_result();

	}

}

//add result ends





void view_results()

{

	int data_found=0;

	int i, sleep_time = 200;



	printf("ROLL\t NAME\t\t");

	printf("\n");



	for(int roll = 1671; roll<1731; roll++)

	{

    	char roll_string[5];

    	itoa(roll,roll_string,10);

    	FILE *pt;

    	int trace=pt=fopen(roll_string,"r");



    	if(!trace)

    	{

        	printf("%i   INSERT DATA \n",roll);

        	fclose(pt);

    	}

    	else

    	{

        	data_found++;

        	char stream_from_file[80];

        	fscanf(pt,"%[^\n]",&stream_from_file);

        	fprintf(stdout,"%s\n",stream_from_file);

        	fclose(pt);

    	}



    	sleep(sleep_time);

    	sleep_time -= 3;

	}



	sleep(300);

	printf("\t\t\t	End of Results\n\n");

	sleep(200);

	printf(" \t\t\t %i  STUDENTS DATA ENTERED\n",data_found);

	sleep(50);

	printf("\t\t\t %i  STUDENTS STILL NEED TO BE ENTERED\n\n",60-data_found);

}

// view results end





void delete_account()

{

	int i;

	remove("Course_Code");

	remove("Identifier_Key");

	remove("Teacher_Details");

	remove("Random");



	for(i=1671; i<1731; i++)

	{

    	char roll_string[5];

    	itoa(i,roll_string,10);

    	remove(roll_string);

	}



	printf("Account Deletion Successful.\nLaunch this program again to re-use it.\nExiting within 5 seconds");



	printf("\n");

	for(i=5; i>-1; i--)

	{

    	printf("%i\n",i);

    	sleep(1000);

	}

}

//delete account ends





float cgpa_counter(float rr)

{

	if(rr>=80) return(4.00);

	else if(rr>=75) return(3.75);

	else if(rr>=70) return(3.50);

	else if(rr>=65) return(3.25);

	else if(rr>=60) return(3.00);

	else if(rr>=55) return(2.75);

	else if(rr>=50) return(2.50);

	else if(rr>=45) return(2.25);

	else if(rr>=40) return(2.00);

	else return(0.00);

}





void sleep(unsigned miliseconds)

{

	Sleep(miliseconds);

}





void printline()

{

	int i;

	for(i=0; i<40; i++)

    	printf("_");

}
