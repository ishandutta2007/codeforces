#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int months[13];

int main()
{
    Int i;
    Int k;
    Int sum=0;
    Int month=0;
    
    scanf("%I64d",&k);
    
    for (i=1;i<=12;i++)
    {
        scanf("%I64d",&months[i]);
    }
    sort(months+1,months+1+12);
    if (k==0)
    {
        printf("0\n");
        return 0;
    }
    for (i=12;i>=1;i--)
    {
        month++;
        sum=sum+months[i];
        
        if (sum>=k)
        {
            printf("%I64d\n",month);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}