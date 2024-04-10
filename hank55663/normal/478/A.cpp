#include<stdio.h>
main()
{
int sum=0,a,i=5;
while(i--)
{
scanf("%d",&a);
sum+=a;
}
if(sum%5==0&&sum!=0)
printf("%d",sum/5);
else
printf("-1");
return 0;
}