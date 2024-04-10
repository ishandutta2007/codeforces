#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
typedef long long Int;

const Int MOD=1000003LL;
int c;
int w,h;
Int HPows[1111];
Int C[1011];

inline int Fix(int k)
{
    while (k<1)
    k+=w+3;
    while (k>w+3)
    k-=w+3;

    return k;
}

int main()
{
    int i,j;
    int ind;
    int curind;
    Int val;

    scanf("%d %d %d",&c,&w,&h);

    HPows[0]=1;
    for (i=1;i<=1000;i++)
    {
        HPows[i]=HPows[i-1]*(Int)h;
        HPows[i]%=MOD;
    }

    C[0]=1;
    for (i=1;i<=w+3;i++)
    {
        C[i]=C[i-1];

        for (j=1;j<=w;j++)
        {
            if (i-j>=1)
            C[i]+=(C[i-j-1]*HPows[j])%MOD;
            else if (i-j==0)
            C[i]+=HPows[j];
            else
            break;
        }

        C[i]%=MOD;
    }

    if (w+3>=c)
    {
        printf("%lld\n",C[c]);
        return 0;
    }

    ///

    ind=w+3;
    for (i=w+4;i<=c;i++)
    {
        //ind=Fix(ind+1);
        ind++;
        if (ind==w+4)
        ind=1;

        C[ind]=C[Fix(ind-1)]*(Int)h+(Int)C[Fix(ind-1)]-(C[Fix(ind-w-2)]*HPows[w+1])%MOD+MOD;
        C[ind]%=MOD;
    }

    printf("%lld\n",C[ind]);

    return 0;
}