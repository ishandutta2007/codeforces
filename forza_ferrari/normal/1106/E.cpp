#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int n,m,p,dp[100005][201],ans;
pair<int,int> maxn[100001<<2],tag[100001<<2];
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
inline void push_up(int k)
{
    maxn[k]=max(maxn[ls(k)],maxn[rs(k)]);
}
inline void push_down(int k)
{
    maxn[ls(k)]=max(maxn[ls(k)],tag[k]);
    maxn[rs(k)]=max(maxn[rs(k)],tag[k]);
    tag[ls(k)]=max(tag[ls(k)],tag[k]);
    tag[rs(k)]=max(tag[rs(k)],tag[k]);
    tag[k]={0,0};
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        maxn[k]={0,l};
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,pair<int,int> p)
{
    if(l>=nl&&r<=nr)
    {
        maxn[k]=max(maxn[k],p);
        tag[k]=max(tag[k],p);
        return;
    }
    push_down(k);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline pair<int,int> query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return maxn[k];
    push_down(k);
    int mid=(l+r)>>1;
    pair<int,int> res={0,0};
    if(nl<=mid)
        res=max(res,query(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=max(res,query(nl,nr,mid+1,r,rs(k)));
    return res;
}
signed main()
{
    n=read(),m=read(),p=read();
    build(1,1,n);
    for(int i=1;i<=p;++i)
    {
        int s=read(),t=read(),d=read(),w=read();
        update(s,t,1,n,1,{w,d});
    }
    for(int i=1;i<=n+1;++i)
        for(int j=0;j<=m;++j)
            dp[i][j]=1e18;
    dp[1][0]=0;
    for(int i=1;i<=n;++i)
    {
        pair<int,int> val=query(i,i,1,n,1);
        for(int j=0;j<=m;++j)
        {
            if(dp[i][j]==1e18)
                continue;
            dp[val.second+1][j]=min(dp[val.second+1][j],dp[i][j]+val.first);
            if(j<m)
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
        }
    }
    ans=1e18;
    for(int i=0;i<=m;++i)
        ans=min(ans,dp[n+1][i]);
    cout<<ans<<'\n';
    return 0;
}