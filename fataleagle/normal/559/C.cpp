#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int H, W, N;
int fact[300001];
int ifact[300001];

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

int C(int N, int K)
{
    if(K>N)
        return 0;
    return 1LL*fact[N]*ifact[K]%MOD*ifact[N-K]%MOD;
}

pair<int, int> A[2000];
int dp[2000];

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

int ways_to(int x0, int y0, int x1, int y1)
{
    if(x0>x1)
        swap(x0, x1);
    if(y0>y1)
        swap(y0, y1);
    x1-=x0;
    y1-=y0;
    return C(x1+y1, x1);
}

int main()
{
    fact[0]=1;
    for(int i=1; i<300001; i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    ifact[300000]=powmod(fact[300000], MOD-2);
    for(int i=299999; i>=0; i--)
        ifact[i]=1LL*ifact[i+1]*(i+1)%MOD;
    scanf("%d%d%d", &H, &W, &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    sort(A, A+N);
    for(int i=0; i<N; i++)
    {
        dp[i]=ways_to(A[i].first, A[i].second, 1, 1);
        for(int j=0; j<i; j++) if(A[j].first<=A[i].first && A[j].second<=A[i].second)
            submod(dp[i], 1LL*dp[j]*ways_to(A[i].first, A[i].second, A[j].first, A[j].second)%MOD);
    }
    int ans=ways_to(1, 1, H, W);
    for(int i=0; i<N; i++)
        submod(ans, 1LL*dp[i]*ways_to(A[i].first, A[i].second, H, W)%MOD);
    printf("%d\n", ans);
    return 0;
}