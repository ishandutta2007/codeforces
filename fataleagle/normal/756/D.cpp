#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
char S[5005];
int dp[5001][5001];
int sum[5001];
int only[5001][26];
int sum2[5001][26];
int last[26];
int fact[20001];
int ifact[20001];

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

int C(int n, int k)
{
    return 1LL*fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;
}

int main()
{
    fact[0]=1;
    for(int i=1; i<=20000; i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    for(int i=0; i<=20000; i++)
        ifact[i]=powmod(fact[i], MOD-2);
    scanf("%d%s", &N, S+1);
    dp[0][0]=1;
    sum[0]=1;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=i; j++)
        {
            dp[i][j]=sum[j-1]-only[j-1][S[i]-'a'];
            if(dp[i][j]<0)
                dp[i][j]+=MOD;
            dp[i][j]-=sum2[j][S[i]-'a'];
            if(dp[i][j]<0)
                dp[i][j]+=MOD;
        }
        for(int j=1; j<=i; j++)
        {
            sum[j]+=dp[i][j];
            if(sum[j]>=MOD)
                sum[j]-=MOD;
            sum2[j][S[i]-'a']+=dp[i][j];
            if(sum2[j][S[i]-'a']>=MOD)
                sum2[j][S[i]-'a']-=MOD;
            only[j][S[i]-'a']+=dp[i][j];
            if(only[j][S[i]-'a']>=MOD)
                only[j][S[i]-'a']-=MOD;
        }
    }
    int ans=0;
    for(int i=1; i<=N; i++)
    {
        int s=0;
        for(int j=i; j<=N; j++)
        {
            s+=dp[j][i];
            if(s>=MOD)
                s-=MOD;
        }
        ans=(ans+1LL*s*C(N-1, i-1))%MOD;
    }
    printf("%d\n", ans);
    return 0;
}