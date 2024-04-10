#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
typedef int Int;

struct group
{
    Int a,b,c;
};

vector<group> groups;
Int nums[8];

int main()
{
    Int i;
    Int n,k;
    Int pre;
    group h;

    memset(nums,0,sizeof(nums));

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);

        nums[k]++;
    }

    if (nums[5]>0 || nums[7]>0)
    {
        printf("-1\n");
        return 0;
    }

    if (nums[2]<nums[4] || nums[1]<nums[4])
    {
        printf("-1\n");
        return 0;
    }

    pre=nums[4];
    for (i=1;i<=pre;i++)
    {
        nums[1]--;
        nums[2]--;
        nums[4]--;

        h.a=1;
        h.b=2;
        h.c=4;

        groups.push_back(h);
    }

    if (nums[6]<nums[3] || nums[1]<nums[3])
    {
        printf("-1\n");
        return 0;
    }

    pre=nums[3];
    for (i=1;i<=pre;i++)
    {
        nums[1]--;
        nums[3]--;
        nums[6]--;

        h.a=1;
        h.b=3;
        h.c=6;

        groups.push_back(h);
    }

    if (nums[1]!=nums[2] || nums[2]!=nums[6])
    {
        printf("-1\n");
        return 0;
    }

    pre=nums[1];
    for (i=1;i<=pre;i++)
    {
        nums[1]--;
        nums[2]--;
        nums[6]--;

        h.a=1;
        h.b=2;
        h.c=6;

        groups.push_back(h);
    }

    for (i=0;i<groups.size();i++)
    {
        printf("%d %d %d\n",groups[i].a,groups[i].b,groups[i].c);
    }

    return 0;
}