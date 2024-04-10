#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int nums[101];
int L=0;
int s;

int main()
{
    int i,j;
    int k;
    int p1=0,p2=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&s);

        for (j=1;j<=s;j++)
        {
            scanf("%d",&k);

            if (s%2==0)
            {
                if (j<=s/2)
                p1+=k;
                else
                p2+=k;
            }
            else
            {
                if (j<=s/2)
                p1+=k;
                else if (j==(s+1)/2)
                {
                    L++;
                    nums[L]=k;
                }
                else
                p2+=k;
            }
        }
    }

    sort(nums+1,nums+1+L);
    reverse(nums+1,nums+1+L);

    for (i=1;i<=L;i++)
    {
        if (i%2==1)
        p1+=nums[i];
        else
        p2+=nums[i];
    }

    printf("%d %d\n",p1,p2);

    return 0;
}