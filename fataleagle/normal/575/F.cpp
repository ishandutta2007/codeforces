#include <bits/stdc++.h>

using namespace std;

struct interval
{
    int l, r, cl, cr;
} A[5001];

int N, pos;
int X[20100], NX;
long long dp[20100];
long long ndp[20100];

int main()
{
    scanf("%d%d", &N, &pos);
    X[NX++]=pos;
    int a, b;
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d", &a, &b);
        A[i].l=a;
        A[i].r=b;
        X[NX++]=a;
        X[NX++]=b;
    }
    sort(X, X+NX);
    NX=unique(X, X+NX)-X;
    for(int i=1; i<=N; i++)
    {
        A[i].cl=lower_bound(X, X+NX, A[i].l)-X;
        A[i].cr=lower_bound(X, X+NX, A[i].r)-X;
    }
    int cpos=lower_bound(X, X+NX, pos)-X;
    for(int i=0; i<NX; i++)
        dp[i]=abs(X[cpos]-X[i]);
    for(int i=1; i<=N; i++)
    {
        int l=A[i].l, r=A[i].r;
        int cl=A[i].cl, cr=A[i].cr;
        for(int j=0; j<NX; j++)
            ndp[j]=0x3f3f3f3f3f3f3f3fLL;
        for(int j=0; j<=cl; j++)
        {
            ndp[j]=min(ndp[j], dp[j]+l-X[j]);
            if(j>0)
                ndp[j]=min(ndp[j], ndp[j-1]);
        }
        for(int j=cl+1; j<cr; j++)
            ndp[j]=min(ndp[j], dp[j]);
        for(int j=NX-1; j>=cr; j--)
        {
            ndp[j]=min(ndp[j], dp[j]+X[j]-r);
            if(j<NX-1)
                ndp[j]=min(ndp[j], ndp[j+1]);
        }
        for(int j=0; j<NX; j++)
            dp[j]=ndp[j];
    }
    long long ans=0x3f3f3f3f3f3f3f3fLL;
    for(int i=0; i<NX; i++)
        ans=min(ans, dp[i]);
    printf("%lld\n", ans);
    return 0;
}