#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

int main()
{
    Int n;
    Int days[8];
    Int i;
    Int pages=0,day=1;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=7;i++)
    {
        scanf("%I64d",&days[i]);
    }
    
    while(1)
    {
        pages=pages+days[day];
        if (pages>=n)
        {
            printf("%I64d\n",day);
            break;
        }
        day++;
        if (day>7)
        day-=7;
    }
    return 0;
}