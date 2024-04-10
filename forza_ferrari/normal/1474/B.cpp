#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,p[1000001],cnt;
bool prime[1000001];
inline void init()
{
    prime[1]=1;
    for(int i=2;i<=1000000;++i)
    {
        if(!prime[i])
            p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=1000000;++j)
        {
            prime[i*p[j]]=1;
            if(i%p[j]==0)
                break;
        }
    }
}
signed main()
{
    init();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        int a=p[lower_bound(p+1,p+cnt+1,n+1)-p];
        int b=p[lower_bound(p+1,p+cnt+1,a+n)-p];
        printf("%lld\n",a*b);
    }
    return 0;
}