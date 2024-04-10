#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int F[511][4][6];
int n;

Int Batrak(int num,int p1,int p2)
{
    if (num==n+1)
    {
        if (p1+p2==0)
        return 1LL;
        else
        return 0LL;
    }
    if (F[num][p1][p2]!=-1)
    return F[num][p1][p2];

    int i,j;
    Int ans=0;

    for (i=0;i<=p1;i++)
    {
        for (j=0;j<=p2;j++)
        {
            ans+=Batrak(num+1,p1-i,p2-j);
        }
    }

    F[num][p1][p2]=ans;

    return ans;
}

void EnchomSolve()
{
    memset(F,-1,sizeof(F));

    scanf("%d",&n);

    printf("%lld\n",Batrak(1,3,5));

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}