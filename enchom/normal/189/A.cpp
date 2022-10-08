#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int F[4001];
Int a,b,c,n;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    Int i;
    Int themax;
    Int chosen;

    scanf("%I64d %I64d %I64d %I64d",&n,&a,&b,&c);

    F[0]=0;
    for (i=1;i<MIN(a,MIN(b,c));i++)
    {
        F[i]=-1;
    }

    for (i=MIN(a,MIN(b,c));i<=n;i++)
    {
        themax=-1;

        if (i>=a)
        {
            if (F[i-a]!=-1 && themax<F[i-a]+1)
            {
                themax=F[i-a]+1;
            }
        }
        if (i>=b)
        {
            if (F[i-b]!=-1 && themax<F[i-b]+1)
            {
                themax=F[i-b]+1;
            }
        }
        if (i>=c)
        {
            if (F[i-c]!=-1 && themax<F[i-c]+1)
            {
                themax=F[i-c]+1;
            }
        }

        F[i]=themax;
    }

    printf("%I64d\n",F[n]);

    return 0;
}