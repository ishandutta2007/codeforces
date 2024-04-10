#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct edge
{
    int nxt,to,weight;
}e[200001<<1];
int n,m,tot,h[100001],dis[100001][51];
bool vis[100001][51];
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
inline void add(int x,int y,int w)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
    e[tot].weight=w;
}
inline void dijkstra()
{
    priority_queue<pair<int,pair<int,int> > > q;
    for(register int i=1;i<=n;++i)
        for(register int j=0;j<=50;++j)
            dis[i][j]=0x3f3f3f3f;
    dis[1][0]=0;
    q.push(make_pair(0,make_pair(1,0)));
    while(!q.empty())
    {
        pair<int,pair<int,int> > k=q.top();
        q.pop();
        if(vis[k.second.first][k.second.second])
            continue;
        vis[k.second.first][k.second.second]=1;
        for(register int i=h[k.second.first];i;i=e[i].nxt)
        {
            if(!k.second.second)
            {
                if(dis[e[i].to][e[i].weight]>dis[k.second.first][k.second.second]+e[i].weight*e[i].weight)
                {
                    dis[e[i].to][e[i].weight]=dis[k.second.first][k.second.second]+e[i].weight*e[i].weight;
                    q.push(make_pair(-dis[e[i].to][e[i].weight],make_pair(e[i].to,e[i].weight)));
                }
            }
            else
                if(dis[e[i].to][0]>dis[k.second.first][k.second.second]+e[i].weight*e[i].weight+((k.second.second*e[i].weight)<<1))
                {
                    dis[e[i].to][0]=dis[k.second.first][k.second.second]+e[i].weight*e[i].weight+((k.second.second*e[i].weight)<<1);
                    q.push(make_pair(-dis[e[i].to][0],make_pair(e[i].to,0)));
                }
        }
    }
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=m;++i)
    {
        int x=read(),y=read(),w=read();
        add(x,y,w);
        add(y,x,w);
    }
    dijkstra();
    for(register int i=1;i<=n;++i)
        printf("%d ",dis[i][0]==0x3f3f3f3f? -1:dis[i][0]);
    puts("");
    return 0;
}