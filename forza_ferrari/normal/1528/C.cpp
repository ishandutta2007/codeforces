#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
struct edge
{
    int nxt,to;
}e[300001<<1];
int t,n,tot,a[300001],b[300001],h[300001],pos[300001][2],cnt,ans,sum;
struct element
{
    int l,r;
    bool operator <(const element &other) const
    {
        return l<other.l;
    }
};
set<element> s;
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void dfs1(int k)
{
    pos[k][0]=++cnt;
    for(int i=h[k];i;i=e[i].nxt)
        dfs1(e[i].to);
    pos[k][1]=++cnt;
}
inline void dfs2(int k)
{
    bool flag=1,tag=0;
    auto it=s.lower_bound({pos[k][0],0});
    element tmp={0,0};
    if(it!=s.end())
    {
        if(it->r<pos[k][1])
            flag=0;
    }
    if(it!=s.begin())
    {
        --it;
        if(it->r>pos[k][1])
        {
            tmp=*it;
            s.erase(it);
            flag=0;
            tag=1;
            s.insert({pos[k][0],pos[k][1]});
        }
    }
    sum+=flag;
    ans=max(ans,sum);
    if(flag)
    {
        tag=1;
        s.insert({pos[k][0],pos[k][1]});
    }
    for(int i=h[k];i;i=e[i].nxt)
        dfs2(e[i].to);
    sum-=flag;
    if(tag)
        s.erase({pos[k][0],pos[k][1]});
    if(tmp.l)
        s.emplace(tmp);
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        ans=0;
        sum=0;
        s.clear();
        cnt=0;
        tot=0;
        for(int i=1;i<=n;++i)
            h[i]=0;
        for(int i=2;i<=n;++i)
            a[i]=read();
        for(int i=2;i<=n;++i)
        {
            b[i]=read();
            add(b[i],i);
        }
        dfs1(1);
        tot=0;
        for(int i=1;i<=n;++i)
            h[i]=0;
        for(int i=2;i<=n;++i)
            add(a[i],i);
        dfs2(1);
        cout<<ans<<'\n';
    }
    return 0;
}