#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

int main()
{
    Int i,j;
    Int n=5;
    Int a;
    Int answer;
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%I64d",&a);
            
            if (a==1)
            {
                answer=ABS(3-i)+ABS(3-j);
            }
        }
    }
    printf("%I64d\n",answer);
    return 0;
}