#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int n,m,x[300001],w[300001],ans[300001],sum[300001<<2];
stack<int> t;
vector<pair<int,int> > v[300001],q[300001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
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
    sum[k]=min(sum[ls(k)],sum[rs(k)]);
}
inline void build(int k,int l,int r)
{
    sum[k]=4e18+7;
    if(l==r)
        return;
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
}
inline void update(int node,int l,int r,int k,int p)
{
    if(l==r)
    {
        sum[k]=min(sum[k],p);
        return;
    }
    int mid=(l+r)>>1;
    if(node<=mid)
        update(node,l,mid,ls(k),p);
    else
        update(node,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return sum[k];
    int mid=(l+r)>>1,res=4e18+7;
    if(nl<=mid)
        res=min(res,query(nl,nr,l,mid,ls(k)));
    if(nr>mid)
        res=min(res,query(nl,nr,mid+1,r,rs(k)));
    return res;
}
signed main()
{
    n=read(),m=read();
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        x[i]=read(),w[i]=read();
        while(!t.empty()&&w[t.top()]>w[i])
            t.pop();
        if(!t.empty())
            v[i].push_back({t.top(),(x[i]-x[t.top()])*(w[i]+w[t.top()])});
        t.push(i);
    }
    while(!t.empty())
        t.pop();
    for(int i=n;i>=1;--i)
    {
        while(!t.empty()&&w[t.top()]>w[i])
            t.pop();
        if(!t.empty())
            v[t.top()].push_back({i,(x[t.top()]-x[i])*(w[t.top()]+w[i])});
        t.push(i);
    }
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        q[r].push_back({l,i});
    }
    for(int i=1;i<=n;++i)
    {
        for(auto j:v[i])
            update(j.first,1,n,1,j.second);
        for(auto j:q[i])
            ans[j.second]=query(j.first,i,1,n,1);
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
    return 0;
}