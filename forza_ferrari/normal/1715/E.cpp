#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define int long long
struct edge
{
	int nxt,to,weight,tag;
}e[200001*30];
struct edges
{
	int x,y,w;
}g[200001];
int n,m,p,dis[21][100001],tot,h[100001],q[200001],head,tail;
bool vis[200001];
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
inline void add(int x,int y,int w,int tag)
{
	e[++tot].nxt=h[x];
	h[x]=tot;
	e[tot].to=y;
	e[tot].weight=w;
    e[tot].tag=tag;
}
inline void dijkstra(int w)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	for(int i=1;i<=n;++i)
	{
		vis[i]=0;
        if(!w)
		    dis[w][i]=1ll<<50;
	}
    if(!w)
    {
	    dis[w][1]=0;
        q.emplace(0,1);
    }
    else
        for(int i=1;i<=n;++i)
            q.emplace(dis[w][i],i);
	while(!q.empty())
	{
		pair<int,int> k=q.top();
		q.pop();
		if(vis[k.second])
			continue;
		vis[k.second]=1;
		dis[w][k.second]=k.first;
		for(int i=h[k.second];i;i=e[i].nxt)
			if(!vis[e[i].to])
				q.emplace(k.first+e[i].weight,e[i].to);
	}
}
inline double slope(int k,int x,int y)
{
	return (dis[k][y]-dis[k][x]+y*y-x*x)*1.0/(y-x);
}
signed main()
{
	n=read(),m=read(),p=read();
	for(int i=1;i<=m;++i)
	{
		g[i].x=read(),g[i].y=read(),g[i].w=read();
		add(g[i].x,g[i].y,g[i].w,0);
        add(g[i].y,g[i].x,g[i].w,0);
	}
	dijkstra(0);
	for(int k=1;k<=p;++k)
    {
        head=1;
        tail=0;
        for(int i=1;i<=n;++i)
        {
            while(head<tail&&slope(k-1,q[tail-1],q[tail])>slope(k-1,q[tail],i))
                --tail;
            q[++tail]=i;
        }
        for(int i=1;i<=n;++i)
        {
            while(head<tail&&slope(k-1,q[head],q[head+1])<2*i)
                ++head;
            dis[k][i]=min(dis[k-1][i],dis[k-1][q[head]]+(q[head]-i)*(q[head]-i));
        }
        dijkstra(k);
    }
    for(int i=1;i<=n;++i)
        cout<<dis[p][i]<<" ";
    cout<<'\n';
	return 0;
}