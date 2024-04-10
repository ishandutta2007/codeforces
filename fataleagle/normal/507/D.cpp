#include <bits/stdc++.h>

using namespace std;

int N, K, MOD;
int dp[1001][2][100];
int p10[1001];
int p10k[1001];

int solve(int pos, bool zero, int m)
{
    int& ret=dp[pos][zero][m];
    if(ret!=-1)
        return ret;
    if(m==0 && !zero)
    {
        if(pos==1)
            return ret=1;
        return ret=9LL*p10[pos-2]%MOD;
    }
    ret=0;
    if(pos>1)
        for(int i=0; i<=9; i++)
            ret=(ret+solve(pos-1, zero && i==0, (m+1LL*i*p10k[N-pos+1])%K))%MOD;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d%d%d", &N, &K, &MOD);
    p10[0]=1;
    p10k[0]=1%K;
    for(int i=1; i<=1000; i++)
    {
        p10[i]=(p10[i-1]*10LL)%MOD;
        p10k[i]=(p10k[i-1]*10LL)%K;
    }
    int ans=0;
    for(int i=0; i<=9; i++)
        ans=(ans+solve(N, i==0, i%K))%MOD;
    printf("%d\n", ans);
    return 0;
}