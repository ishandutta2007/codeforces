 #include<stdio.h>
 
 int arr[466]={0};
  int main( void)
 {
     FILE *fin=fopen("input.txt", "r");
     FILE *fout=fopen("output.txt", "w");
     int amount, mon, day, peo, time, sum, ans=0;
     int i, j;
     fscanf(fin,"%d", &amount);
     for( i=0; i<amount; i++)
     {         sum=0;
         fscanf(fin,"%d %d %d %d", &mon, &day, &peo, &time);
         switch( mon)
         {
         case 12:sum+=30;
         case 11:sum+=31;
         case 10:sum+=30;
         case 9:sum+=31;
         case 8:sum+=31;
         case 7:sum+=30;
         case 6:sum+=31;
         case 5:sum+=30;
         case 4:sum+=31;
         case 3:sum+=28;
         case 2:sum+=31;
         case 1:sum+=day;break;
         }
         sum+=100;
         for( j=1; j<=time; j++)
             arr[sum-j]+=peo;
     }
     for( i=0; i<466; i++)
         ans=ans>=arr[i]?ans:arr[i];
     fprintf(fout,"%d", ans);
     return 0;
}