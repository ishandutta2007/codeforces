#include <bits/stdc++.h>

using namespace std;

long long m;
int k;
int num[66], len;
long long dp[66][2][66];

void init(long long x)
{
    if(x)
        init(x>>1);
    num[len++]=x&1;
}

long long work(int pos, bool small, int one)
{
    long long& ret=dp[pos][small][one];
    if(ret!=-1)
        return ret;
    if(pos==len)
        return ret=one==k;
    ret=0;
    int limit=small?num[pos]:1;
    for(int i=0; i<=limit; i++)
        ret+=work(pos+1, small && i==limit, one+i);
    return ret;
}

long long solve(long long x)
{
    memset(dp, -1, sizeof dp);
    len=0;
    init(x);
    long long a=work(0, true, 0);
    memset(dp, -1, sizeof dp);
    len=0;
    init(x*2);
    long long b=work(0, true, 0);
    return b-a;
}

int main()
{
    cin>>m>>k;
    long long lo=1, mid, hi=1000000000000000000LL;
    while(lo<hi)
    {
        mid=(lo+hi)>>1LL;
        long long ans=solve(mid);
        if(ans<m)
            lo=mid+1;
        else
            hi=mid;
    }
    printf("%lld\n", lo);
    return 0;
}