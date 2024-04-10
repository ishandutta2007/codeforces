#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int A[18];
long long adj[19][19];
long long dp[19][1<<18];

long long rec(int pos, int mask)
{
    if(mask==0)
        return 0;
    long long& ret=dp[pos][mask];
    if(ret!=-1)
        return ret;
    for(int i=0; i<N; i++) if((mask>>i)&1)
        ret=max(ret, rec(i, mask&~(1<<i))+adj[pos][i]+A[i]);
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    int a, b, c;
    for(int i=0; i<K; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a-1][b-1]+=c;
    }
    long long ans=0;
    for(int i=0; i<(1<<N); i++) if(__builtin_popcount(i)==M)
        ans=max(ans, rec(N, i));
    printf("%lld\n", ans);
    return 0;
}