#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int n;
Int seq[100001];

Int FastPow(Int k,Int p)
{
    if (p==0)
    return 1LL;

    Int POWER=FastPow(k,p/2);

    POWER=POWER*POWER;
    POWER%=n;

    if (p%2==1)
    {
        POWER=POWER*k;
        POWER%=n;
    }

    return POWER;
}

Int Divide(Int a,Int b)
{
    return (a*FastPow(b,n-2))%n;
}

//bool seen[100001];
//bool seen2[100001];

int main()
{
    int i;
    Int cur;

    scanf("%I64d",&n);

    if (n==1)
    {
        printf("YES\n1\n");
        return 0;
    }

    if (n==4)
    {
        printf("YES\n1\n3\n2\n4\n");
        return 0;
    }

    for (i=2;i<=n-1;i++)
    {
        if (n%i==0)
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    seq[1]=1;
    seq[2]=2;

    for (i=3;i<=n-1;i++)
    {
        seq[i]=Divide(i,i-1);
    }

    seq[n]=n;

    for (i=1;i<=n;i++)
    {
        /*
        if (seen[ seq[i] ])
        {
            printf("ERROR\n");
            return 0;
        }

        seen[ seq[i] ]=true;

        if (i==1)
        cur=seq[i];
        else
        cur*=seq[i];

        cur%=n;

        if (seen2[cur])
        {
            printf("ERROR2\n");
            return 0;
        }

        seen2[cur]=true;
        */

        printf("%d\n",seq[i]);
    }

    return 0;
}