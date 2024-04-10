#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[300005];
int num[5005];
long long dp[5005][5005];

long long rec(int l, int r, int pos)
{
    if(l>r)
        return 0;
    long long& ret=dp[l][r];
    if(ret!=-1)
        return ret;
    if(num[l]==0)
        return ret=rec(l+1, r, pos);
    if(num[r]==0)
        return ret=rec(l, r-1, pos);
    ret=min(rec(l+1, r, pos+num[l])+(long long)A[pos+num[l]-1]-A[pos],
            rec(l, r-1, pos+num[r])+(long long)A[pos+num[r]-1]-A[pos]);
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), num[i%K]++;
    sort(A, A+N);
    printf("%lld\n", rec(0, K-1, 0));
    return 0;
}