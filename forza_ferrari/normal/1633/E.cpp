#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define int long long
struct edge
{
    int x,y,w,mid,id;
    bool operator <(edge &other) const
    {
        return abs(w-mid)<abs(other.w-other.mid);
    }
}e[301],tmp[301];
int n,m,p,a,b,c,q,now,lst,cnt,bin[51],ans;
vector<int> v[100001];
int node[100001];
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
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
inline void mst(int id)
{
    for(int i=1;i<=m;++i)
        tmp[i].id=i,tmp[i].x=e[i].x,tmp[i].y=e[i].y,tmp[i].w=e[i].w,tmp[i].mid=node[id]+1;
    sort(tmp+1,tmp+m+1);
    for(int i=1;i<=n;++i)
        bin[i]=0;
    for(int i=1;i<=m;++i)
        if(anc(tmp[i].x)^anc(tmp[i].y))
        {
            v[id].emplace_back(tmp[i].id);
            link(tmp[i].x,tmp[i].y);
        }
}
signed main()
{
    n=read(),m=read();
    node[++cnt]=0;
    for(int i=1;i<=m;++i)
    {
        e[i].x=read(),e[i].y=read(),e[i].w=read()<<2;
        for(int j=1;j<m;++j)
            if(e[i].w^e[j].w)
                node[++cnt]=(e[i].w+e[j].w)>>1;
    }
    sort(node+1,node+cnt+1);
    cnt=unique(node+1,node+cnt+1)-node-1;
    for(int i=1;i<=cnt;++i)
        mst(i);
    p=read(),q=read(),a=read(),b=read(),c=read();
    for(int i=1;i<=p;++i)
    {
        now=read();
        int pos=upper_bound(node+1,node+cnt+1,now<<2)-node-1,val=0;
        for(auto j:v[pos])
            val+=abs(now-(e[j].w>>2));
        ans^=val;
    }
    for(int i=p+1;i<=q;++i)
    {
        lst=now;
        now=(1ll*a*lst%c+b)%c;
        int pos=upper_bound(node+1,node+cnt+1,now<<2)-node-1,val=0;
        for(auto j:v[pos])
            val+=abs(now-(e[j].w>>2));
        ans^=val;
    }
    cout<<ans<<'\n';
    return 0;
}