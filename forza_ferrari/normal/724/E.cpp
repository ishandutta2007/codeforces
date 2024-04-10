#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int n,c,a[500001],b[500001],s[500001],sum,ans;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
signed main()
{
    n=read(),c=read();
    for(int i=1;i<=n;++i)
        sum+=a[i]=read();
    for(int i=1;i<=n;++i)
        s[i]=(b[i]=read())-a[i]+(n-i)*c;
    ans=sum;
    sort(s+1,s+n+1);
    for(int i=1;i<=n;++i)
    {
        sum+=s[i];
        ans=min(ans,sum-i*(i-1)/2*c);
    }
    cout<<ans<<'\n';
    return 0;
}