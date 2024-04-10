#include<stdio.h>
main()
{
    int a[10]={2,7,2,3,3,4,2,5,1,2},sum=1;
    char n[99];
    scanf("%s",n);
    for(int i=0;n[i]!=0;i++)
    sum*=a[n[i]-48];
    printf("%d",sum);
    return 0;
}