#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,sum[2];
signed main()
{
    scanf("%lld",&n);
    for(register int i=1;i<=n;++i)
    {
        int x;
        scanf("%lld",&x);
        sum[i&1]+=x>>1;
        sum[i&1^1]+=x-(x>>1);
    }
    printf("%lld\n",min(sum[0],sum[1]));
    return 0;
}