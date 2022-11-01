#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, D;
long long A[100001];
long long X[100001];
int dp[100001];
int path[100001];
int seg[262144];

void update(int idx, int begin, int end, int x, int v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
    {
        if(dp[v]>dp[seg[idx]])
            seg[idx]=v;
    }
    else
    {
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x, v);
        update(idx*2+1, mid+1, end, x, v);
        if(dp[seg[idx*2]]>dp[seg[idx*2+1]])
            seg[idx]=seg[idx*2];
        else
            seg[idx]=seg[idx*2+1];
    }
}

int query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return 0;
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    int r1=query(idx*2, begin, mid, i, j);
    int r2=query(idx*2+1, mid+1, end, i, j);
    if(dp[r1]>dp[r2])
        return r1;
    return r2;
}

void trace(int x)
{
    if(x==0)
        return;
    trace(path[x]);
    printf("%d ", x);
}

int main()
{
    scanf("%d%d", &N, &D);
    for(int i=1; i<=N; i++)
        scanf("%lld", A+i), X[i]=A[i];
    sort(X+1, X+1+N);
    for(int i=1; i<=N; i++)
    {
        dp[i]=1;
        path[i]=0;
        int pos=lower_bound(X+1, X+1+N, A[i]-D+1)-X-1;
        if(pos>=1)
        {
            int ret=query(1, 1, N, 1, pos);
            if(dp[ret]+1>dp[i])
            {
                dp[i]=dp[ret]+1;
                path[i]=ret;
            }
        }
        pos=lower_bound(X+1, X+1+N, A[i]+D)-X;
        if(pos<=N)
        {
            int ret=query(1, 1, N, pos, N);
            if(dp[ret]+1>dp[i])
            {
                dp[i]=dp[ret]+1;
                path[i]=ret;
            }
        }
        update(1, 1, N, lower_bound(X+1, X+1+N, A[i])-X, i);
        continue;
        for(int j=1; j<i; j++)
            if(A[j]<=A[i]-D)
                dp[i]=max(dp[i], dp[j]+1);
        for(int j=1; j<i; j++)
            if(A[j]>=A[i]+D)
                dp[i]=max(dp[i], dp[j]+1);
    }
    int maxi=0;
    for(int i=1; i<=N; i++)
        if(dp[i]>dp[maxi])
            maxi=i;
    printf("%d\n", dp[maxi]);
    trace(maxi);
    printf("\n");
    return 0;
}