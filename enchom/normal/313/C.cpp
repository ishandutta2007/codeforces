#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef int Int;

Int a[2000001];
Int n;

bool backwards(Int x,Int y)
{
    return x>y;
}

int main()
{
    Int nums;
    Int cp;
    long long sum=0;
    Int theend,thebeg;
    Int i,j;

    scanf("%d",&nums);

    for (i=1;i<=nums;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+1+nums,backwards);

    cp=nums;
    n=0;
    while(cp>1)
    {
        cp=cp/4;
        n++;
    }

    thebeg=1;
    theend=1;

    for (i=n+1;i>=1;i--)
    {
        for (j=thebeg;j<=theend;j++)
        {
            sum=sum+( (long long)a[j]*(long long)i );
        }
        thebeg=theend+1;
        theend=theend*4;
    }

    printf("%I64d\n",sum);

    return 0;
}