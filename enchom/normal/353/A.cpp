#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int sum1,sum2;
bool different=false;
Int n;
Int a,b;

int main()
{
    Int i;

    sum1=0;
    sum2=0;

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&a,&b);

        sum1+=a;
        sum2+=b;

        if (a%2!=b%2)
        {
            different=true;
        }
    }

    if (sum1%2==0 && sum2%2==0)
    {
        printf("0\n");
    }
    else if (sum1%2==1 && sum2%2==1)
    {
        if (different)
        printf("1\n");
        else
        printf("-1\n");
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}