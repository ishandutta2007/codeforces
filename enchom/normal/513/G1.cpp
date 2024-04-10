#include <iostream>
#include <stdio.h>
using namespace std;
typedef long double Double;

int n,k;
int arr[101];
Double Chance;
Double C;

Double Sum=0.0;
Double Ways=0.0;

void Evaluate()
{
    int inv=0;
    int i,j;

    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            if (arr[i]>arr[j])
            {
                inv++;
            }
        }
    }

    Ways=Ways+1.0;
    Sum=Sum+(Double)inv;

    return;
}

void Reverse(int l,int r)
{
    int i;
    int swp;

    for (i=l;i<=(l+r)/2;i++)
    {
        swp=arr[i];
        arr[i]=arr[r-(i-l)];
        arr[r-(i-l)]=swp;
    }

    return;
}

void Solve(int step)
{
    if (step==k+1)
    {
        Evaluate();
        return;
    }

    int i,j;

    for (i=1;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            Reverse(i,j);

            Solve(step+1);

            Reverse(i,j);
        }
    }

    return;
}

int main()
{
    int i;
    Double Ans;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    Solve(1);

    Ans=Sum/Ways;

    printf("%.10f\n",(double)Ans);

    return 0;
}