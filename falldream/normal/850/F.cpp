#include<bits/stdc++.h>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[2505],tot,f[MN+5],ans;
inline int pw(int x,int k)
{
    int res=1;
    for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) res=1LL*res*x%mod;
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) tot+=(a[i]=read());
    f[1]=1LL*(tot-1)*(tot-1)%mod*pw(tot,mod-2)%mod;
    for(int i=2;i<=MN;++i) f[i]=(2LL*f[i-1]-f[i-2]+mod-1LL*(tot-1)*pw(tot-i+1,mod-2)%mod+mod)%mod;
    for(int i=1;i<=n;++i) ans=(ans+f[a[i]])%mod;
    cout<<ans;
    return 0;
}