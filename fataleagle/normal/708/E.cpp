#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, M, K, p, q;
int f[1501];
int dp[1501][1501];
int dpL[1501][1501];
int dpR[1501][1501];

int powmod(int a, int b)
{
    int ret=1;
    for(; b>0; b/=2)
    {
        if(b&1)
            ret=1LL*ret*a%MOD;
        a=1LL*a*a%MOD;
    }
    return ret;
}

int main()
{
    cin>>N>>M>>p>>q>>K;
    int prob=1LL*p*powmod(q, MOD-2)%MOD;
    int qrob=(1-prob+MOD)%MOD;
    f[0]=1;
    for(int t=0; t<K; t++)
    {
        for(int i=M-1; i>=0; i--)
        {
            f[i+1]=(f[i+1]+1LL*f[i]*prob)%MOD;
            f[i]=1LL*f[i]*qrob%MOD;
        }
    }
    int s=0;
    for(int i=0; i<=M; i++)
        for(int j=i+1; j<=M; j++)
        {
            int v=dp[i][j]=1LL*f[i]*f[M-j]%MOD;
            s=(s+v)%MOD;
            dpL[0][i]=(dpL[0][i]+v)%MOD;
            dpR[0][j]=(dpR[0][j]+v)%MOD;
        }
    for(int i=1; i<=M; i++)
        dpR[0][i]=(dpR[0][i-1]+dpR[0][i])%MOD;
    for(int i=M-1; i>=0; i--)
        dpL[0][i]=(dpL[0][i+1]+dpL[0][i])%MOD;
    for(int k=1; k<N; k++)
    {
        if(k==N-1)
        {
            for(int i=0; i<=M; i++)
            {
                for(int j=i+1; j<=M; j++)
                {
                    int z=(dpR[k-1][i]+dpL[k-1][j])%MOD;
                    dp[i][j]=(s-z+MOD)%MOD;
                    dp[i][j]=1LL*dp[i][j]*f[i]%MOD*f[M-j]%MOD;
                }
            }
        }
        int ns=0;
        int sfMj=0, sum=0;
        for(int i=M; i>=0; i--)
        {
            dpL[k][i]=1LL*s*f[i]%MOD*sfMj%MOD;
            dpL[k][i]=(dpL[k][i]-1LL*dpR[k-1][i]*f[i]%MOD*sfMj%MOD+MOD)%MOD;
            dpL[k][i]=(dpL[k][i]-1LL*f[i]*sum%MOD+MOD)%MOD;
            sfMj=(sfMj+f[M-i])%MOD;
            sum=(sum+1LL*dpL[k-1][i]*f[M-i])%MOD;
            ns=(ns+dpL[k][i])%MOD;
        }
        int sfi=0, sum2=0;
        for(int j=0; j<=M; j++)
        {
            dpR[k][j]=1LL*s*f[M-j]%MOD*sfi%MOD;
            dpR[k][j]=(dpR[k][j]-1LL*dpL[k-1][j]*f[M-j]%MOD*sfi%MOD+MOD)%MOD;
            dpR[k][j]=(dpR[k][j]-1LL*f[M-j]*sum2%MOD+MOD)%MOD;
            sfi=(sfi+f[j])%MOD;
            sum2=(sum2+1LL*dpR[k-1][j]*f[j])%MOD;
        }
        s=ns;
        for(int i=1; i<=M; i++)
            dpR[k][i]=(dpR[k][i-1]+dpR[k][i])%MOD;
        for(int i=M-1; i>=0; i--)
            dpL[k][i]=(dpL[k][i+1]+dpL[k][i])%MOD;
    }
    int ans=0;
    for(int i=0; i<=M; i++)
        for(int j=i+1; j<=M; j++)
            ans=(ans+dp[i][j])%MOD;
    printf("%d\n", ans);
    return 0;
}