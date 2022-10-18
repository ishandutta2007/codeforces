#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,a[100001];
vector<int> v[100001<<2];
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
    v[k].resize(v[ls(k)].size()+v[rs(k)].size());
    merge(v[ls(k)].begin(),v[ls(k)].end(),v[rs(k)].begin(),v[rs(k)].end(),v[k].begin());
    while(v[k].size()>31)
        v[k].pop_back();
}
inline void build(int k,int l,int r)
{
    v[k].clear();
    if(l==r)
    {
        v[k].emplace_back(a[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void query(int nl,int nr,int l,int r,int k,vector<int> &res)
{
    if(l>=nl&&r<=nr)
    {
        res=v[k];
        return;
    }
    int mid=(l+r)>>1;
    vector<int> ql,qr;
    if(nl<=mid)
        query(nl,nr,l,mid,ls(k),ql);
    if(nr>mid)
        query(nl,nr,mid+1,r,rs(k),qr);
    res.resize(ql.size()+qr.size());
    merge(ql.begin(),ql.end(),qr.begin(),qr.end(),res.begin());
    while(res.size()>31)
        res.pop_back();
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        build(1,1,n);
        m=read();
        while(m--)
        {
            int l=read(),r=read(),ans=1<<30;
            vector<int> res;
            query(l,r,1,n,1,res);
            for(int i=0;i<(int)res.size();++i)
                for(int j=i+1;j<(int)res.size();++j)
                    ans=min(ans,res[i]|res[j]);
            cout<<ans<<'\n';
        }
    }
    return 0;
}