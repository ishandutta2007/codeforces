#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct rule
{
    Int a,b,orgind;
};

Int marks[100001];
Int n,p,k;
rule rules[100001];

bool Sort1(rule a,rule b)
{
    if (a.b<b.b)
    return true;
    else if (a.b>b.b)
    return false;
    else
    {
        if (a.a>b.a)
        return true;
        else if (a.a<b.a)
        return false;
        else
        {
            return a.orgind<b.orgind;
        }
    }
}

bool Sort2(rule a,rule b)
{
    if (a.a>b.a)
    return true;
    else if (a.a<b.a)
    return false;
    else
    {
        if (a.b>b.b)
        return true;
        else if (a.b<b.b)
        return false;
        else
        {
            return a.orgind<b.orgind;
        }
    }
}

int main()
{
    Int i;
    Int ctr=0;
    Int firstind;

    for (i=0;i<=100000;i++)
    {
        marks[i]=0;
    }

    scanf("%I64d %I64d %I64d",&n,&p,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&rules[i].a,&rules[i].b);

        rules[i].orgind=i;
    }

    sort(rules+1,rules+1+n,Sort1);

    for (i=1;i<=p-k;i++)
    {
        marks[ rules[i].orgind ]=1; ///Discarded
    }

    sort(rules+1,rules+1+n,Sort2);

    for (i=1;i<=n;i++)
    {
        if (marks[ rules[i].orgind ]==0)
        {
            marks[ rules[i].orgind ]=2; ///Added

            ctr++;
            if (ctr==k)
            break;
        }
    }

    sort(rules+1,rules+1+n,Sort1);

    for (i=1;i<=n;i++)
    {
        if (marks[ rules[i].orgind ]==2)
        {
            firstind=i;
            break;
        }
    }

    ctr=0;
    for (i=firstind-1;i>=firstind-(p-k);i--)
    {
        if (i<1)
        {
            printf("WTF?");
            return 0;
        }
        ctr++;
        printf("%I64d",rules[i].orgind);

        if (ctr!=p)
        {
            printf(" ");
        }
    }

    for (i=firstind;i<=n;i++)
    {
        if (marks[ rules[i].orgind ]==2)
        {
            ctr++;
            printf("%I64d",rules[i].orgind);
            if (ctr!=p)
            {
                printf(" ");
            }
        }
    }

    printf("\n");

    return 0;
}