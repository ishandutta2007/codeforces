#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, K;
long long M;
int C[101][101];
int dp[101][10001];
int pw[101][101];

int powmod(int a, int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1LL*ret*a%MOD;
        a=1LL*a*a%MOD;
        b/=2;
    }
    return ret;
}

int solve(int pos, int k)
{
    if(pos==N)
        return k==0;
    int& ret=dp[pos][k];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0; i<=min(N, k); i++)
        ret=(ret+1LL*pw[pos][i]*solve(pos+1, k-i))%MOD;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    for(int i=0; i<=100; i++)
    {
        C[i][0]=1;
        for(int j=1; j<=i; j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    cin>>N>>M>>K;
    for(int i=0; i<N; i++)
        for(int j=0; j<=N; j++)
            pw[i][j]=powmod(C[N][j], ((M-i+N-1)/N)%(MOD-1));
    printf("%d\n", solve(0, K));
    return 0;
}