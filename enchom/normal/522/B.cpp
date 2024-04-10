#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long Int;

int w[200011];
int h[200011];
int n;
Int sum=0;
int prefixmax[200011];
int suffixmax[200011];

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
    Int ans;

    scanf("%d",&n);

    prefixmax[0]=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&w[i],&h[i]);

        sum+=(Int)w[i];

        prefixmax[i]=MAX(prefixmax[i-1],h[i]);
    }

    suffixmax[n+1]=0;
    for (i=n;i>=1;i--)
    {
        suffixmax[i]=MAX(suffixmax[i+1],h[i]);
    }

    for (i=1;i<=n;i++)
    {
        ans=(Int)MAX(prefixmax[i-1],suffixmax[i+1])*(sum-(Int)w[i]);

        printf("%lld",ans);

        if (i!=n)
        printf(" ");
    }
    printf("\n");

    return 0;
}