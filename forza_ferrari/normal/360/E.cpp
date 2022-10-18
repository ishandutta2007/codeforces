#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
struct edge
{
    int nxt,to,l,r,w;
}e[1000001];
int n,m,p,dis[1000001][2],tot,h[1000001],s1,s2,t;
bool vis[1000001][2];
struct element
{
    int val,node;
    bool tag;
    element(int val_,int node_,bool tag_):
        val(val_),node(node_),tag(tag_){}
    bool operator <(const element &other) const
    {
        return val^other.val? val>other.val:node^other.node? node>other.node:tag<other.tag;
    }
};
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
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline void add(int x,int y,int l,int r)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].l=l;
    e[tot].r=r;
    e[tot].w=r;
}
inline void dijkstra(bool opt)
{
    for(register int i=1;i<=n;++i)
    {
        dis[i][0]=dis[i][1]=1ll<<60;
        vis[i][0]=vis[i][1]=0;
    }
    for(register int i=1;i<=tot;++i)
        e[i].w=e[i].r;
    priority_queue<element> q;
    q.push(element(0,s1,0));
    q.push(element(0,s2,1));
    while(!q.empty())
    {
        element k=q.top();
        q.pop();
        if(vis[k.node][k.tag])
            continue;
        vis[k.node][k.tag]=1;
        dis[k.node][k.tag]=k.val;
        for(register int i=h[k.node];i;i=e[i].nxt)
        {
            if((!k.tag&&!vis[k.node][1]))
            {
                e[i].w=e[i].l;
                q.push(element(k.val+e[i].w,e[i].to,k.tag));
                continue;
            }
            if(opt&&dis[k.node][0]==dis[k.node][1])
            {
                e[i].w=e[i].l;
                q.push(element(k.val+e[i].w,e[i].to,0));
                q.push(element(k.val+e[i].w,e[i].to,1));
                continue;
            }
            q.push(element(k.val+e[i].w,e[i].to,k.tag));
        }
    }
}
signed main()
{
    n=read(),m=read(),p=read(),s1=read(),s2=read(),t=read();
    for(register int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        add(x,y,w,w);
    }
    for(register int i=1;i<=p;++i)
    {
        int x=read(),y=read(),l=read(),r=read();
        add(x,y,l,r);
    }
    dijkstra(0);
    if(dis[t][0]<dis[t][1])
    {
        puts("WIN");
        for(register int i=m+1;i<=tot;++i)
        {
            print(e[i].w);
            putchar(' ');
        }
        puts("");
        return 0;
    }
    dijkstra(1);
    if(dis[t][0]>dis[t][1])
    {
        puts("LOSE");
        return 0;
    }
    puts("DRAW");
    for(register int i=m+1;i<=tot;++i)
    {
        print(e[i].w);
        putchar(' ');
    }
    puts("");
    return 0;
}