#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
struct element
{
    int x,y,w;
}q[300001];
int n,m,dep[300001],ch[300001][2],dis[300001],root[300001],val[300001],tag[300001],minn[300001],tot,ans;
vector<int> v[300001],a[300001];
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
inline int newnode(int k)
{
    val[++tot]=q[k].w;
    minn[tot]=dep[q[k].x];
    return tot;
}
inline void push_down(int k)
{
    if(ch[k][0])
    {
        val[ch[k][0]]-=tag[k];
        tag[ch[k][0]]+=tag[k];
    }
    if(ch[k][1])
    {
        val[ch[k][1]]-=tag[k];
        tag[ch[k][1]]+=tag[k];
    }
    tag[k]=0;
}
inline int merge(int x,int y)
{
    if(!x||!y)
        return x|y;
    if(val[x]>val[y])
        swap(x,y);
    push_down(x);
    ch[x][1]=merge(ch[x][1],y);
    if(dis[ch[x][0]]<dis[ch[x][1]])
        swap(ch[x][0],ch[x][1]);
    dis[x]=dis[ch[x][1]]+1;
    return x;
}
inline int pop(int k)
{
    push_down(k);
    return merge(ch[k][0],ch[k][1]);
}
inline void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs1(i,k,deep+1);
    }
}
inline void dfs2(int k,int f)
{
    for(int i:v[k])
    {
        if(i==f)
            continue;
        dfs2(i,k);
        root[k]=merge(root[k],root[i]);
    }
    for(int i:a[k])
        root[k]=merge(root[k],newnode(i));
    while(root[k]&&minn[root[k]]>=dep[k])
        root[k]=pop(root[k]);
    if(k^1)
    {
        if(!root[k])
        {
            cout<<"-1\n";
            exit(0);
        }
        ans+=val[root[k]];
        tag[root[k]]+=val[root[k]];
        val[root[k]]=0;
    }
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    dfs1(1,0,1);
    for(int i=1;i<=m;++i)
    {
        q[i].x=read(),q[i].y=read(),q[i].w=read();
        if(dep[q[i].x]>dep[q[i].y])
            swap(q[i].x,q[i].y);
        a[q[i].y].emplace_back(i);
    }
    dfs2(1,0);
    cout<<ans<<'\n';
    return 0;
}