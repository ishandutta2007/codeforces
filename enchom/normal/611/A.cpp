 #include <iostream>
 #include <stdio.h>
 using namespace std;

 int wday=5;
 int day=1;
 int month=1;
 int x;
 char ch[11];

 int main()
 {
     int i;
     int ans=0;
     bool weekday=false;

     scanf("%d",&x);

     scanf("%s",ch);
     scanf("%s",ch);

     if (ch[0]=='w')
     {
         weekday=true;
     }

     while(month<=12)
     {
         if (weekday)
         {
             if (wday==x)
             ans++;
         }
         else
         {
             if (day==x)
             ans++;
         }

         day++;

         wday++;
         if (wday==8)
         wday=1;

         if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
         {
             if (day==32)
             {
                 day=1;
                 month++;
             }
         }
         else if (month==2)
         {
             if (day==30)
             {
                 day=1;
                 month++;
             }
         }
         else
         {
             if (day==31)
             {
                 day=1;
                 month++;
             }
         }
     }

     printf("%d\n",ans);

     return 0;
 }