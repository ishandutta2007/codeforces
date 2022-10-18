#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
int t,n,m,a[100001],sum[100001<<2],ans[100001<<4],cnt;
double node[100001<<2];
vector<int> v[100001];
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
    ans[k]=min(ans[ls(k)],ans[rs(k)]);
}
inline void build(int k,int l,int r)
{
    if(l==r)
    {
        ans[k]=sum[l];
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        ans[k]+=p;
        return;
    }
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
signed main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        cnt=0;
        for(int i=1;i<=m;++i)
            v[i].clear();
        for(int i=1;i<=n;++i)
            node[++cnt]=a[i]=read();
        sort(a+1,a+n+1);
        for(int i=1;i<=m;++i)
        {
            int p=read(),s=0;
            v[i].resize(p);
            for(int j=0;j<p;++j)
            {
                v[i][j]=read();
                s+=v[i][j];
            }
            node[++cnt]=1.0*s/p;
            if(p^1)
                for(int j=0;j<p;++j)
                    node[++cnt]=1.0*(s-v[i][j])/(p-1);
        }
        sort(node+1,node+cnt+1);
        cnt=unique(node+1,node+cnt+1)-node-1;
        for(int i=1;i<=cnt;++i)
            sum[i]=0;
        for(int i=1;i<=n;++i)
            ++sum[lower_bound(node+1,node+cnt+1,a[i])-node];
        for(int i=1;i<=m;++i)
        {
            int s=0;
            for(auto j:v[i])
                s+=j;
            --sum[lower_bound(node+1,node+cnt+1,1.0*s/v[i].size())-node];
        }
        for(int i=cnt-1;i>=1;--i)
            sum[i]+=sum[i+1];
        build(1,1,cnt);
        for(int i=1;i<=m;++i)
        {
            int s=0;
            for(auto j:v[i])
                s+=j;
            int pos=lower_bound(node+1,node+cnt+1,1.0*s/v[i].size())-node;
            if(v[i].size()==1)
            {
                update(1,pos,1,cnt,1,1);
                cout<<(ans[1]>=0);
                update(1,pos,1,cnt,1,-1);
                continue;
            }
            for(int j=0;j<(int)v[i].size();++j)
            {
                int tmp=lower_bound(node+1,node+cnt+1,1.0*(s-v[i][j])/(v[i].size()-1))-node;
                if(tmp<=pos)
                    update(tmp+1,pos,1,cnt,1,1);
                else
                    update(pos+1,tmp,1,cnt,1,-1);
                cout<<(ans[1]>=0);
                if(tmp<=pos)
                    update(tmp+1,pos,1,cnt,1,-1);
                else
                    update(pos+1,tmp,1,cnt,1,1);
            }
        }
        cout<<'\n';
    }
    return 0;
}