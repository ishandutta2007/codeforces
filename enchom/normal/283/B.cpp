#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct memorization
{
    bool initialadd;
    bool endless;
    Int value;
};

Int n;
Int a[200001];
memorization mem[200001][2];
Int UTFO[200001][2];
Int TFOKey=1;

void Batrak(Int ind,Int step)
{
    if (ind<1 || ind>n)
    return;

    if (UTFO[ind][step]!=0)
    return;

    UTFO[ind][step]=TFOKey;

    if (ind==1)
    {
        if (step==1)
        {
            mem[ind][step].endless=true;
            return;
        }
        else
        {
            mem[ind][step].initialadd=true;
            mem[ind][step].endless=false;
            mem[ind][step].value=0;
            return;
        }
    }
    else
    {
        Int nextind;
        Int otherstep;

        if (step==0)
        {
            nextind=ind-a[ind];
            otherstep=1;
        }
        else
        {
            nextind=ind+a[ind];
            otherstep=0;
        }

        if (nextind<1 || nextind>n)
        {
            mem[ind][step].endless=false;
            mem[ind][step].initialadd=false;
            mem[ind][step].value=a[ind];
            return;
        }

        if (UTFO[nextind][otherstep]==TFOKey)
        {
            mem[ind][step].endless=true;
            return;
        }

        Batrak(nextind,otherstep);

        if (mem[nextind][otherstep].endless)
        {
            mem[ind][step].endless=true;
            return;
        }
        else
        {
            mem[ind][step].initialadd=mem[nextind][otherstep].initialadd;
            mem[ind][step].value=a[ind]+mem[nextind][otherstep].value;
            mem[ind][step].endless=false;
            return;
        }
    }

    return;
}

int main()
{
    Int i;
    Int goneto;
    Int y=0;

    for (i=0;i<=200000;i++)
    {
        mem[i][0].value=0;
        mem[i][0].endless=false;
        mem[i][0].initialadd=false;

        mem[i][1].value=0;
        mem[i][1].endless=false;
        mem[i][1].initialadd=false;

        UTFO[i][0]=0;
        UTFO[i][1]=0;
    }

    scanf("%I64d",&n);

    for (i=2;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }

    for (i=2;i<=n;i++)
    {
        Batrak(i,0);
        TFOKey++;

        Batrak(i,1);
        TFOKey++;
    }

    for (i=1;i<=n-1;i++)
    {
        goneto=i+1;

        if (mem[goneto][0].endless)
        {
            printf("-1\n");
            continue;
        }

        y=mem[goneto][0].value;
        if (mem[goneto][0].initialadd)
        {
            y+=i;
        }
        y+=i;

        printf("%I64d\n",y);
    }
    return 0;
}