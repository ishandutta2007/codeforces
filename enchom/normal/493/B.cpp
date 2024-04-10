#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int p1[200001];
int L1=0;
int p2[200001];
int L2=0;

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int n;

int main()
{
    int i;
    int k;
    Int sum=0;
    int last;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);

        sum+=(Int)k;

        if (k>0)
        {
            L1++;
            p1[L1]=k;

            last=1;
        }
        else
        {
            L2++;
            p2[L2]=-k;

            last=-1;
        }
    }

    if (sum>0)
    {
        printf("first\n");
        return 0;
    }
    else if (sum<0)
    {
        printf("second\n");
        return 0;
    }

    for (i=1;i<=MIN(L1,L2);i++)
    {
        if (p1[i]>p2[i])
        {
            printf("first\n");
            return 0;
        }
        else if (p1[i]<p2[i])
        {
            printf("second\n");
            return 0;
        }
    }

    if (L1<L2)
    {
        printf("second\n");
        return 0;
    }
    else if (L1>L2)
    {
        printf("first\n");
        return 0;
    }

    if (last==1)
    printf("first\n");
    else
    printf("second\n");

    return 0;
}