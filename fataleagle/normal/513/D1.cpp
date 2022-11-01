#include <bits/stdc++.h>

using namespace std;

int N, C;
int L[1000001], R[1000001];
bool child[1000001];
int maxc[1000001];
int dp[105][105];
int path[105][105];
int flag[105][105];
int lc[105];
int rc[105];
// maximum position left subtree can end at
// minimum position right subtree can start at

void fail()
{
    printf("IMPOSSIBLE\n");
    exit(0);
}

int solve(int idx, int r)
{
    int& ret=dp[idx][r];
    if(ret!=-1)
        return ret;
    if(idx==r)
        return ret=!child[idx];
    if(r<idx || (child[idx] && maxc[idx]>r))
        return ret=0;
    for(int i=idx+1; i<r; i++)
    {
        // left is [idx+1, i]
        // right is[i+1, r]
        if(i>L[idx] || i+1<R[idx])
            continue;
        if(solve(idx+1, i) &&
           solve(i+1, r))
        {
            flag[idx][r]=2;
            path[idx][r]=i;
            return ret=1;
        }
    }
    if(!rc[idx] && solve(idx+1, r))
    {
        flag[idx][r]=0;
        return ret=1;
    }
    if(!lc[idx] && solve(idx+1, r))
    {
        flag[idx][r]=1;
        return ret=1;
    }
    return ret=0;
}

void trace(int idx, int r)
{
    if(idx==r)
    {
        printf("%d ", idx);
        return;
    }
    int i=path[idx][r];
    if(flag[idx][r]==0)
        i=r;
    if(flag[idx][r]==1)
        i=idx;
    if(flag[idx][r]==0 || flag[idx][r]==2)
        trace(idx+1, i);
    printf("%d ", idx);
    if(flag[idx][r]==1 || flag[idx][r]==2)
        trace(i+1, r);
}

int main()
{
    memset(dp, -1, sizeof dp);
    memset(flag, -1, sizeof flag);
    scanf("%d%d", &N, &C);
    for(int i=1; i<=N; i++)
        L[i]=N, R[i]=i+1;
    int a, b;
    char buf[10];
    for(int i=0; i<C; i++)
    {
        scanf("%d%d%s", &a, &b, buf);
        child[a]=true;
        maxc[a]=max(maxc[a], b);
        if(b<=a)
            fail();
        if(buf[0]=='R')
            rc[a]=true, L[a]=min(L[a], b-1);
        else
            lc[a]=true, R[a]=max(R[a], b+1);
    }
    if(!solve(1, N))
        fail();
    trace(1, N);
    printf("\n");
    return 0;
}