#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct num
{
    Int bonus,val;
};

num nums[500001];
Int nL=0;

int main()
{
    Int n;
    Int i;
    Int command;
    Int k,a,x;
    double average;
    Int sum=0;

    scanf("%I64d",&n);

    nL=1;
    nums[1].bonus=0;
    nums[1].val=0;

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&command);

        if (command==1)
        {
            scanf("%I64d %I64d",&a,&x);

            nums[a].bonus+=x;

            sum=sum+x*a;
        }
        else if (command==2)
        {
            scanf("%I64d",&k);
            nL++;
            nums[nL].bonus=0;
            nums[nL].val=k;

            sum+=k;
        }
        else
        {
            sum-=nums[nL].bonus;
            sum-=nums[nL].val;

            nums[nL-1].bonus+=nums[nL].bonus;

            nL--;
        }

        average=(double)sum / (double)nL;

        printf("%.6f\n",average);
    }

    return 0;
}