#include <iostream>
#include <stdio.h>
using namespace std;

typedef int Int;

Int MOD=1000000007;
Int F,LastF;
Int LastPowerOf3;
Int rem;

int main()
{
    Int n;
    Int i;

    scanf("%d",&n);

    if (n==1)
    {
        printf("0\n");
        return 0;
    }

    LastF=0;
    LastPowerOf3=1;

    for (i=2;i<=n;i++)
    {
        rem=LastPowerOf3;

        LastPowerOf3=LastPowerOf3+rem;
        if (LastPowerOf3>=MOD)
        {
            LastPowerOf3=LastPowerOf3-MOD;
        }
        LastPowerOf3=LastPowerOf3+rem;
        if (LastPowerOf3>=MOD)
        {
            LastPowerOf3=LastPowerOf3-MOD;
        }

        F=LastPowerOf3-LastF;

        if (F<0)
        {
            F=F+MOD;
        }

        LastF=F;
    }

    printf("%d\n",LastF);

    return 0;
}