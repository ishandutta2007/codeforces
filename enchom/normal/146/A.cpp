#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    Int n;
    Int i;
    char ch;
    Int sum1=0,sum2=0;

    scanf("%I64d",&n);
    scanf("%c",&ch);

    for (i=1;i<=n/2;i++)
    {
        scanf("%c",&ch);
        sum1=sum1+(Int)ch-(Int)'0';

        if (ch!='4' && ch!='7')
        {
            printf("NO\n");
            return 0;
        }
    }

    for (i=1;i<=n/2;i++)
    {
        scanf("%c",&ch);
        sum2=sum2+(Int)ch-(Int)'0';

        if (ch!='4' && ch!='7')
        {
            printf("NO\n");
            return 0;
        }
    }

    if (sum1==sum2)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}