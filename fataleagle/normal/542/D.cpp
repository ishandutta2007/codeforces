#include <bits/stdc++.h>

using namespace std;

long long N;
bool prime[100];

long long fastpow(long long a, long long b)
{
    long long ret=1;
    while(b)
    {
        if(b&1)
            ret*=a;
        a*=a;
        b/=2;
    }
    return ret;
}

bool isprime(long long x)
{
    for(long long i=2; i*i<=x; i++) if(x%i==0)
        return false;
    return true;
}

long long get_prime_power(long long x)
{
    if(x<2)
        return -1;
    for(int i=1; i<=40; i++)
    {
        long long y=pow(x, 1.0/i);
        while(fastpow(y, i)<x)
            y++;
        while(fastpow(y, i)>x)
            y--;
        if(fastpow(y, i)==x && isprime(y))
            return y;
    }
    return -1;
}

int main()
{
    scanf("%lld", &N);
    if(N==1)
    {
        printf("1\n");
        return 0;
    }
    int good=0;
    unordered_map<long long, vector<long long>> factors;
    for(long long i=1; i*i<=N; i++) if(N%i==0)
    {
        long long tmp=get_prime_power(i-1);
        if(tmp!=-1)
            factors[tmp].push_back(i), good++;
        if(i!=N/i)
        {
            tmp=get_prime_power(N/i-1);
            if(tmp!=-1)
                factors[tmp].push_back(N/i), good++;
        }
    }
    if(!good)
    {
        printf("0\n");
        return 0;
    }
    unordered_map<long long, long long> dp, ndp;
    for(auto& it: factors)
    {
        dp=ndp;
        dp[1]=1;
        for(auto& it2: it.second)
            for(auto& it3: dp)
                if((long double)it3.first*it2<=N && N%(it3.first*it2)==0)
                    ndp[it3.first*it2]+=it3.second;
    }
    printf("%lld\n", ndp[N]);
    return 0;
}