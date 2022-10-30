#include <bits/stdc++.h>

using namespace std;

int N;
int A[501];
int cache[501][501];
int dp[501][501][2];

int ispalin(int l, int r)
{
    if(l>=r)
        return 1;
    int& ret=cache[l][r];
    if(ret!=-1)
        return ret;
    if(A[l]!=A[r])
        return ret=0;
    return ret=ispalin(l+1, r-1);
}

int solve(int l, int r, int canRemove)
{
    if(l>r)
        return 0;
    int& ret=dp[l][r][canRemove];
    if(ret!=-1)
        return ret;
    if(ispalin(l, r))
    {
        if(canRemove)
            return ret=0;
        return ret=1;
    }
    ret=0x3f3f3f3f;
    if(canRemove)
    {
        if(A[l]==A[r])
            ret=min(ret, solve(l+1, r-1, 1));
        for(int i=l; i<r; i++)
        {
            ret=min(ret, solve(l, i, 0)+solve(i+1, r, 1));
            ret=min(ret, solve(l, i, 1)+solve(i+1, r, 0));
        }
    }
    if(A[l]==A[r])
        ret=min(ret, solve(l+1, r-1, 1)+1);
    for(int i=l; i<r; i++)
        ret=min(ret, solve(l, i, 0)+solve(i+1, r, 0));
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    memset(cache, -1, sizeof cache);
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(1, N, 0));
    return 0;
}