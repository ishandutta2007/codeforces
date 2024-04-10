#include <stdio.h>

int main()
{
    int sum=0,ms=-1,i,ts=0,lisho;
    
    scanf("%d",&i);
    while(i--)
    {
              scanf("%d",&lisho);
              ts+=lisho;
              if(lisho==0) sum++;
              else sum--;
              if (ms<sum) ms=sum;
              if(sum<0) sum=0;
    }
    printf("%d\n",ts+ms);
    return 0;
}