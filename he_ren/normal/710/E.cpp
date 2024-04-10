#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
typedef long long ll;
const int MAXN = 1e7 + 5;
using namespace std;

ll dis[MAXN];
bool vis[MAXN];
struct Node
{
	int id;
	ll dis;
	inline friend bool operator < (const Node &a,const Node &b){ return a.dis>b.dis;}
};
priority_queue<Node> q;

inline void chk(int u,int v,ll w)
{
	if(v<0 || v>=MAXN) return;
	if(dis[v]>dis[u]+w)
	{
		dis[v]=dis[u]+w;
		q.push((Node){ v,dis[v]});
	}
}

int main(void)
{
	memset(dis,0x3f,sizeof(dis));
	
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	
	dis[0]=0;
	q.push((Node){0,0});
	while(!q.empty())
	{
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(u==n) break;
		
		chk(u,u<<1,y);
		chk(u,u+1,x); chk(u,u-1,x);
	}
	
	cout<<dis[n];
	return 0;
}