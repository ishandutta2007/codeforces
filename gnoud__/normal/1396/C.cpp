#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
const int N=1e6+10;
int n,r1,r2,r3,d,a[N],b[N],s[N],f[N];
int c1(int i)
{
    return f[i-1]+r1*a[i]+r3+d;
}
int c2(int i)
{
    return f[i-1]+b[i]+r1+d*3ll;
}
int c3(int i)
{
    return d+s[i]+r1*i+(i-1)*3ll*d;
}
int m_x(int i)
{
    return f[i-1]-s[i-1]-r1*(i-1)-(i-1)*3ll*d;
}
int c4(int i)
{
    return r1*(n-i-1)+(n-i-1)*d*2+f[i]+d+r1*a[n]+r3+s[n-1]-s[i];
}
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x;
}
main()
{
    //freopen("baiCC.inp","r",stdin);
    n=read(),r1=read(),r2=read(),r3=read(),d=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        b[i]=min(r2,r1*(a[i]+1));
        s[i]=s[i-1]+b[i];
    }
    int mx=1e18;
    f[0]=-d;
    for(int i=1;i<=n;++i)
    {
        f[i]=min({c1(i),c2(i),mx+c3(i)});
        mx=min(mx,m_x(i));
    }
    for(int i=0;i<n;++i) f[n]=min(f[n],c4(i));
    cout<<f[n]<<"\n";
}