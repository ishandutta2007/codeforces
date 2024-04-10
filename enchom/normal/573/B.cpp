#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int nums[100111];
int val1[100111];
int val2[100111];
int longest[100111];

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    int i;
    int minval;
    int ans=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&nums[i]);

        val1[i]=nums[i]-i;
        val2[i]=nums[i]+i;

        longest[i]=MIN(nums[i],MIN(i,n-i+1));
    }

    minval=val1[1];
    for (i=2;i<=n;i++)
    {
        longest[i]=MIN(longest[i],minval+i);

        minval=MIN(minval,val1[i]);
    }

    minval=val2[n];
    for (i=n-1;i>=1;i--)
    {
        longest[i]=MIN(longest[i],minval-i);

        minval=MIN(minval,val2[i]);
    }

    for (i=1;i<=n;i++)
    {
        ans=MAX(ans,longest[i]);
    }

    printf("%d\n",ans);

    return 0;
}