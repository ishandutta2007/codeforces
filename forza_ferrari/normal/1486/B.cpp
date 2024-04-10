#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int t,n,x[1001],y[1001];
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(register int i=1;i<=n;++i)
            scanf("%lld%lld",&x[i],&y[i]);
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        if(n&1)
            puts("1");
        else
            printf("%lld\n",(x[(n>>1)+1]-x[n>>1]+1)*(y[(n>>1)+1]-y[n>>1]+1));
    }
    return 0;
}