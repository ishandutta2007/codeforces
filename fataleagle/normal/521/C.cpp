#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int fact[100001];
int ifact[100001];
int p10[100001];
int ans;
int N, K;
char S[100002];
int pnum[100001];
int psum[100001];

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

int C(int n, int k)
{
    if(n<0 || k<0 || k>n)
        return 0;
    return 1LL*fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;
}

void addmod(int& a, int b)
{
    a+=b;
    if(a>=MOD)
        a-=MOD;
}

void submod(int& a, int b)
{
    a-=b;
    if(a<0)
        a+=MOD;
}

int main()
{
    fact[0]=1;
    for(int i=1; i<=100000; i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    ifact[100000]=powmod(fact[100000], MOD-2);
    for(int i=99999; i>=0; i--)
        ifact[i]=1LL*ifact[i+1]*(i+1)%MOD;
    p10[0]=1;
    for(int i=1; i<=100000; i++)
        p10[i]=1LL*p10[i-1]*10%MOD;
    scanf("%d%d%s", &N, &K, S+1);
    for(int i=1; i<=100000; i++)
    {
        psum[i]=psum[i-1]+S[i]-'0';
        pnum[i]=(1LL*pnum[i-1]*10+S[i]-'0')%MOD;
    }
    if(K==0)
    {
        printf("%d\n", pnum[N]);
        return 0;
    }
    int sum=0;
    for(int len=0; len<=N; len++)
    {
        addmod(ans, 1LL*sum*C(N-1-len-1, K-2)%MOD);
        submod(sum, pnum[len]);
        addmod(sum, 1LL*psum[N-len]*p10[len]%MOD);
    }
    for(int i=1; i<=N; i++)
    {
        submod(ans, 1LL*pnum[i]*C(N-1-i-1, K-2)%MOD);
        addmod(ans, 1LL*pnum[i]*C(N-1-i, K-1)%MOD);
    }
    int snum=0;
    for(int i=1; i<=N; i++)
    {
        addmod(snum, 1LL*(S[N-i+1]-'0')*p10[i-1]%MOD);
        submod(ans, 1LL*snum*C(N-1-i-1, K-2)%MOD);
        addmod(ans, 1LL*snum*C(N-1-i, K-1)%MOD);
    }
    printf("%d\n", ans);
    return 0;
}