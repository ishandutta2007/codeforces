#include <bits/stdc++.h>

using namespace std;

const long long MAX=6000000000LL;
int N;
long long X[100002];
long long D[100001];
long long dpL[100001]; // dpL[i] = with i as anchor, dpL[i] is the farthest right the next can be at
long long dpR[100001];

struct dynamic_BIT
{
    unordered_map<long long, long long> bit;
    void upd(long long x, long long v)
    {
        for(x++; x<=MAX; x+=x&-x)
        {
            auto it=bit.find(x);
            if(it==bit.end())
                bit[x]=v;
            else
                it->second=max(it->second, v);
        }
    }
    long long ask(long long x)
    {
        long long ret=-0x3f3f3f3f3f3f3f3fLL;
        for(x++; x>0; x-=x&-x)
        {
            auto it=bit.find(x);
            if(it!=bit.end())
                ret=max(ret, it->second);
        }
        return ret;
    }
} bit1, bit2, bit3;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<=N+1; i++)
        scanf("%lld", X+i);
    for(int i=1; i<=N; i++)
        scanf("%lld", D+i);
    dpL[0]=X[N+1];
    for(int i=1; i<=N; i++)
    {
        dpL[i]=max(X[0], bit1.ask(MAX-X[i]))+D[i]*2;
        bit1.upd(MAX-dpL[i], X[i]);
    }
    for(int i=1; i<=N; i++) if(dpL[i]>=X[N+1])
        return printf("0\n"), 0;
    dpR[N+1]=X[0];
    for(int i=N; i>=1; i--)
    {
        dpR[i]=min(X[N+1], MAX-bit2.ask(X[i]))-D[i]*2;
        bit2.upd(dpR[i], MAX-X[i]);
    }
    long long ans=0x3f3f3f3f3f3f3f3fLL;
    for(int i=0; i<=N+1; i++)
    {
        if(dpR[i]<X[i])
            ans=min(ans, X[i]-bit3.ask(MAX-dpR[i]));
        if(dpL[i]>X[i])
            bit3.upd(MAX-dpL[i], X[i]);
    }
    printf("%lld.%lld\n", ans/2, ans%2*5);
    return 0;
}