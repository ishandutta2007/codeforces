#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,a[100001],minn,node;
int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        minn=1<<30;
        node=0;
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            if(minn>a[i])
            {
               minn=a[i];
               node=i;
            }
        }
        printf("%lld\n",n-1);
        for(register int i=1;i<=n;++i)
            if(node^i)
                printf("%lld %lld %lld %lld\n",node,i,minn,i&1? (int)1e9+7:(int)1e9+9);
    }
    return 0;
}