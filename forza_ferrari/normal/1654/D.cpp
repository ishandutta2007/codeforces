#include<iostream>
#include<cstdio>
#include<set>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
const int mod=998244353;
struct edge
{
    int nxt,to,a,b;
}e[200001<<1];
int t,n,tot,h[200001],w[200001];
map<int,int> mp,tmp;
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
inline int gcd(int x,int y)
{
    return x%y? gcd(y,x%y):y;
}
inline int pw(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=1ll*res*a%mod;
        b>>=1;
        a=1ll*a*a%mod;
    }
    return res;
}
inline void add(int x,int y,int a,int b)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].a=a;
    e[tot].b=b;
}
inline void dfs(int k,int f,int val,int a,int b)
{
    w[k]=1ll*val*pw(a,mod-2)%mod*b%mod;
    int tmpa=a,tmpb=b;
    for(int i=2;i*i<=b;++i)
        while(b%i==0)
        {
            b/=i;
            --tmp[i];
        }
    if(b^1)
        --tmp[b];
    for(int i=2;i*i<=a;++i)
        while(a%i==0)
        {
            a/=i;
            ++tmp[i];
            if(tmp[i]>0)
                mp[i]=max(mp[i],tmp[i]);
        }
    if(a^1)
    {
        ++tmp[a];
        if(tmp[a]>0)
            mp[a]=max(mp[a],tmp[a]);
    }
    for(int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,w[k],e[i].a,e[i].b);
    }
    a=tmpa,b=tmpb;
    for(int i=2;i*i<=b;++i)
        while(b%i==0)
        {
            b/=i;
            ++tmp[i];
        }
    if(b^1)
        ++tmp[b];
    for(int i=2;i*i<=a;++i)
        while(a%i==0)
        {
            a/=i;
            --tmp[i];
        }
    if(a^1)
        --tmp[a];
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        tot=0;
        for(int i=1;i<=n;++i)
            w[i]=h[i]=0;
        mp.clear();
        tmp.clear();
        for(int i=1;i<n;++i)
        {
            int x=read(),y=read(),a=read(),b=read(),g=gcd(a,b);
            a/=g;
            b/=g;
            add(x,y,a,b);
            add(y,x,b,a);
        }
        dfs(1,0,1,1,1);
        int lcm=1;
        for(auto i:mp)
            lcm=1ll*lcm*pw(i.first,i.second)%mod;
        int ans=0;
        for(int i=1;i<=n;++i)
            ans=(ans+1ll*w[i]*lcm%mod)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}