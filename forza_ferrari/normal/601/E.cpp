#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
const int p=1e7+19,mod=1e9+7;
struct element
{
    int l,r,c,w;
}a[40001];
int n,m,q,cnt,c[40001],w[40001],t[40001],f[1001],tot;
bool vis[40001];
vector<pair<int,int> > v[40001<<2];
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
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
void update(int nl,int nr,int l,int r,int k,pair<int,int> p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        v[k].push_back(p);
        return;
    }
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
}
void query(int l,int r,int k,int dp[])
{
    for(auto i:v[k])
        for(int j=m;j>=i.second;--j)
            dp[j]=max(dp[j],dp[j-i.second]+i.first);
    if(l==r)
    {
        int ans=0;
        for(int i=2;i<=m;++i)
            dp[i]=max(dp[i],dp[i-1]);
        for(int i=m;i;--i)
            ans=(ans*p%mod+dp[i])%mod;
        printf("%lld\n",ans);
        return;
    }
    int mid=(l+r)>>1,tmp[1001];
    memcpy(tmp,dp,sizeof tmp);
    query(l,mid,ls(k),tmp);
    memcpy(tmp,dp,sizeof tmp);
    query(mid+1,r,rs(k),tmp);
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        c[i]=read(),w[i]=read();
        t[i]=1;
    }
    q=read();
    while(q--)
    {
        int opt=read();
        if(opt==1)
        {
            ++n;
            c[n]=read(),w[n]=read();
            t[n]=cnt+1;
        }
        if(opt==2)
        {
            int x=read();
            vis[x]=1;
            a[++tot]={t[x],cnt,c[x],w[x]};
        }
        if(opt==3)
            ++cnt;
    }
    for(int i=1;i<=n;++i)
        if(!vis[i])
            a[++tot]={t[i],cnt,c[i],w[i]};
    for(int i=1;i<=tot;++i)
        update(a[i].l,a[i].r,1,cnt,1,{a[i].c,a[i].w});
    query(1,cnt,1,f);
    return 0;
}