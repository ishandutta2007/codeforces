#include <iostream>
#define MOD 1000000007LL

using namespace std;

long long n, m, k;

long long powerMod(int base, long long ex){
    long long p[62];
    p[0]=base;
    for(int i=1; i < 62; ++i)
        p[i]=(p[i-1]*p[i-1])%MOD;
    long long ans=1;
    for(int i=0; i < 62; ++i)
        if(ex&(1LL<<i))
            ans=(ans*p[i])%MOD;
    return ans;
}

bool isPrime[101];
int multBin[101];

void addMultBin(int factor, int add){
    for(int i=2; factor > 1; ++i){
        if(factor%i == 0){
            multBin[i] += add;
            factor /= i;
            --i;
        }
    }
}

long long binom(int N, int K){
    for(int i=0; i < 101; ++i)
        multBin[i]=0;
    for(int i=1; i <= K; ++i)
        addMultBin(i, -1);
    for(int i=N-K+1; i <= N; ++i)
        addMultBin(i, 1);
    long long ans=1;
    for(int i=2; i < 100; ++i){
        for(int j=0; j < multBin[i]; ++j)
            ans=(ans*i)%MOD;
    }
    return ans;
}

long long dp[102][10001], bin[101];

int main()
{
    cin >> n >> m >> k;
    for(int i=0; i <= n; ++i)
        bin[i]=binom(n, i);
    for(int j=0; j <= n; ++j)
        for(int i=0; i <= k; ++i)
            dp[j][i]=0;
    dp[0][0]=1;
    for(int i=0; i < n; ++i){
        for(int j=0; j <= k && j <= n; ++j){
            long long c=powerMod(bin[j], (m-i+n-1)/n);
            for(int q=0; q+j <= k; ++q)
                dp[i+1][q+j]=(dp[i+1][q+j]+dp[i][q]*c)%MOD;
        }
    }
    long long answer=dp[n][k];
    cout << answer;
    return 0;
}