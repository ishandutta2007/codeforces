#include<stdio.h>
main()
{

    
int n,sum=1,i,a[50];
    for(i=0;i<50;i++)
    {
        a[i]=sum;
        sum=sum+i+2;
        
    }
    scanf("%d",&n);
    sum=0;
    for(i=0;i<50;i++)
    {
        if(sum>n)
        break;
        sum+=a[i];      
    }
    printf("%d",i-1);
    return 0;
}