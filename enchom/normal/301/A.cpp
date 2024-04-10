#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int totalsum=0;
Int minnum=999999999;
Int minuses=0;

Int ABS(Int a)
{
    if (a<0)
    {
        return a*-1;
    }
    else
    {
        return a;
    }
}

int main()
{
    Int n;
    Int i;
    Int a;

    scanf("%I64d",&n);

    for (i=1;i<=2*n-1;i++)
    {
        scanf("%I64d",&a);

        if (ABS(a)<minnum)
        {
            minnum=ABS(a);
        }

        totalsum=totalsum+ABS(a);

        if (a<0)
        {
            minuses++;
        }
    }

    if (minuses%2==0)
    {
        printf("%I64d\n",totalsum);
    }
    else
    {
        if (n%2==1)
        {
            printf("%I64d\n",totalsum);
        }
        else
        {
            printf("%I64d\n",totalsum-2*minnum);
        }
    }

    return 0;
}