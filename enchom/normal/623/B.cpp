#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
typedef long long Int;

int n,a,b;
int nums[1000111];

int carr[1000111];

Int bestcost=-1;
Int offset=0;

void Solve(int div)
{
    int i;
    int first2=-1,last2=-1;
    int r;
    Int curcost=0;
    Int save,bestsave;

    //cout<<"Testing with "<<div<<endl;

    for (i=1;i<=n;i++)
    {
        r=nums[i]%div;

        if (r==0)
        carr[i]=0;
        else if (r==1 || r==div-1)
        carr[i]=1;
        else
        {
            carr[i]=2;
            if (first2==-1)
            first2=i;

            last2=i;
        }
    }

    if (first2==-1)
    {
        //cout<<"
        for (i=1;i<=n;i++)
        {
            curcost+=(Int)carr[i]*(Int)b;
        }

        save=0;
        bestsave=0;
        for (i=1;i<=n;i++)
        {
            if (carr[i]==0)
            save-=a;
            else
            save+=(b-a);

            if (save<0)
            save=0;

            if (save>bestsave)
            bestsave=save;
        }

        curcost-=bestsave;
    }
    else
    {
        for (i=1;i<=first2-1;i++)
        {
            curcost+=(Int)carr[i]*(Int)b;
        }

        for (i=last2+1;i<=n;i++)
        {
            curcost+=(Int)carr[i]*(Int)b;
        }

        curcost+=(Int)(last2-first2+1)*(Int)a;

        save=0;
        bestsave=0;
        for (i=first2-1;i>=1;i--)
        {
            if (carr[i]==1)
            save+=(b-a);
            else
            save-=a;

            if (save>bestsave)
            bestsave=save;
        }

        curcost-=bestsave;

        save=0;
        bestsave=0;
        for (i=last2+1;i<=n;i++)
        {
            if (carr[i]==1)
            save+=(b-a);
            else
            save-=a;

            if (save>bestsave)
            bestsave=save;
        }

        curcost-=bestsave;
    }

    //cout<<curcost<<endl;

    curcost+=offset;

    if (curcost<bestcost || bestcost==-1)
    bestcost=curcost;

    return;
}

void GS(int num)
{
    int i;

    for (i=2;i*i<=num;i++)
    {
        if (num%i==0)
        {
            Solve(i);
            while(num%i==0)
            num/=i;
        }
    }

    if (num>1)
    {
        Solve(num);
    }

    return;
}

int main()
{
    int i,j;

    scanf("%d %d %d",&n,&a,&b);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);
    }

    GS(nums[1]);
    nums[1]--;
    offset=b;
    GS(nums[1]);
    nums[1]+=2;
    GS(nums[1]);
    nums[1]--;
    offset=0;

    ///

    GS(nums[n]);
    nums[n]--;
    offset=b;
    GS(nums[n]);
    nums[n]+=2;
    GS(nums[n]);

    printf("%lld\n",bestcost);

    return 0;
}