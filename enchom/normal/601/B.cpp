#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n,q;
int arr[100111];
int nums[100111];

int ABS(int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

int NextBigger[100111];
int PrevBigger[100111];

int s[100111];
int sL=0;

void GetValues()
{
    int i;

    sL=0;
    for (i=1;i<=n-1;i++)
    {
        while(sL!=0 && nums[ s[sL] ]<nums[i])
        {
            NextBigger[ s[sL] ]=i;
            sL--;
        }

        sL++;
        s[sL]=i;
    }

    while(sL>0)
    {
        NextBigger[ s[sL] ]=n;
        sL--;
    }

    ///

    for (i=n-1;i>=1;i--)
    {
        while(sL!=0 && nums[ s[sL] ]<=nums[i])
        {
            PrevBigger[ s[sL] ]=i;
            sL--;
        }

        sL++;
        s[sL]=i;
    }

    while(sL>0)
    {
        PrevBigger[ s[sL] ]=0;
        sL--;
    }

    return;
}

inline int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

inline int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

Int Solve(int L,int R)
{
    int i;
    int l,r;
    Int ans=0;

    for (i=L;i<=R;i++)
    {
        l=MAX(L,PrevBigger[i]+1);
        r=MIN(R,NextBigger[i]-1);

        ans+=(Int)nums[i] * (Int)(i-l+1) * (Int)(r-i+1);
    }

    return ans;
}

int main()
{
    int i,j;
    int L,R;

    scanf("%d %d",&n,&q);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (i=1;i<=n-1;i++)
    {
        nums[i]=ABS(arr[i]-arr[i+1]);
    }

    GetValues();

    for (i=1;i<=q;i++)
    {
        scanf("%d %d",&L,&R);

        R--;

        printf("%lld\n",Solve(L,R));
    }

    return 0;
}