#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,p,a[300001],b[300001],c[300001],x,y,z,d,e,f;
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&p);
    x=y=z=1ll<<60;
    for(register int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        d+=a[i];
        x=min(x,a[i]);
    }
    for(register int i=1;i<=m;++i)
    {
        scanf("%lld",&b[i]);
        e+=b[i];
        y=min(y,b[i]);
    }
    for(register int i=1;i<=p;++i)
    {
        scanf("%lld",&c[i]);
        f+=c[i];
        z=min(z,c[i]);
    }
    if(min(d,min(e,f))<x+y+z-max(x,max(y,z)))
        printf("%lld\n",d+e+f-2*min(d,min(e,f)));
    else
        printf("%lld\n",d+e+f-2*(x+y+z-max(x,max(y,z))));
    return 0;
}