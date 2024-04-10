#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
int A[501];
int dp[501][501];

int solve(int l, int r)
{
    int& ret=dp[l][r];
    if(ret!=-1)
        return ret;
    if(l>=r)
        return ret=1;
    ret=solve(l+1, r);
    for(int i=l+1; i<=r; i++)
        if(A[l]<A[i])
            ret=(ret+1LL*solve(l+1, i-1)*solve(i, r))%MOD;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    printf("%d\n", solve(2, N));
    return 0;
}