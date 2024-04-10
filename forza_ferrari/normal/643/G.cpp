#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,m,lim,a[150001],tag[150001<<2];
vector<pair<int,int> > v[150001<<2];
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
inline void merge(vector<pair<int,int> > &res,vector<pair<int,int> > &x,vector<pair<int,int> > &y)
{
    res.clear();
    for(auto i:x)
    {
        bool flag=0;
        for(auto &j:res)
            if(j.first==i.first)
            {
                j.second+=i.second;
                flag=1;
                break;
            }
        if(!flag)
            if(res.size()<lim)
                res.emplace_back(i);
            else
            {
                int minn=i.second;
                for(auto j:res)
                    minn=min(minn,j.second);
                for(auto it=res.begin();it!=res.end();)
                    if((it->second-=minn)<=0)
                        it=res.erase(it);
                    else
                        ++it;
                if(i.second-minn>0)
                    res.emplace_back(i.first,i.second-minn);
            }
    }
    for(auto i:y)
    {
        bool flag=0;
        for(auto &j:res)
            if(j.first==i.first)
            {
                j.second+=i.second;
                flag=1;
                break;
            }
        if(!flag)
            if(res.size()<lim)
                res.emplace_back(i);
            else
            {
                int minn=i.second;
                for(auto j:res)
                    minn=min(minn,j.second);
                for(auto it=res.begin();it!=res.end();)
                    if((it->second-=minn)<=0)
                        it=res.erase(it);
                    else
                        ++it;
                if(i.second-minn>0)
                    res.emplace_back(i.first,i.second-minn);
            }
    }
}
inline void push_up(int k)
{
    merge(v[k],v[ls(k)],v[rs(k)]);
}
inline void push_down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    if(tag[k])
    {
        v[ls(k)].clear();
        v[rs(k)].clear();
        v[ls(k)].emplace_back(tag[k],mid-l+1);
        v[rs(k)].emplace_back(tag[k],r-mid);
        tag[ls(k)]=tag[rs(k)]=tag[k];
        tag[k]=0;
    }
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        v[k].emplace_back(a[l],1);
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        v[k].clear();
        v[k].emplace_back(p,r-l+1);
        tag[k]=p;
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline void query(int nl,int nr,int l,int r,int k,vector<pair<int,int> > &res)
{
    if(l>=nl&&r<=nr)
    {
        res=v[k];
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nr<=mid)
    {
        query(nl,nr,l,mid,ls(k),res);
        return;
    }
    if(nl>mid)
    {
        query(nl,nr,mid+1,r,rs(k),res);
        return;
    }
    vector<pair<int,int> > ql,qr;
    query(nl,nr,l,mid,ls(k),ql);
    query(nl,nr,mid+1,r,rs(k),qr);
    merge(res,ql,qr);
}
int main()
{
    n=read(),m=read(),lim=100/read();
    for(int i=1;i<=n;++i)
        a[i]=read();
    build(1,1,n);
    while(m--)
    {
        int opt=read(),l=read(),r=read();
        if(opt==1)
            update(l,r,1,n,1,read());
        if(opt==2)
        {
            vector<pair<int,int> > res;
            query(l,r,1,n,1,res);
            cout<<res.size()<<" ";
            for(auto i:res)
                cout<<i.first<<" ";
            cout<<'\n';
        }
    }
    return 0;
}