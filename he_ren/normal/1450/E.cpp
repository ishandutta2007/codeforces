#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e2 + 5;
const int MAXM = 2e3 + 5;
const int inf = 0x3f3f3f3f;

struct Edge
{
	int next,to,w;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot] = (Edge){ head[u],v,w};
	head[u] = etot;
}

int n,m;
pair<pii,int> es[MAXM];

int dis[MAXN];
int get_dis(int s)
{
	static bool inq[MAXN];
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	dis[s] = 0; q.push(s); inq[s] = 1;
	while(q.size())
	{
		int u = q.front(); q.pop();
		inq[u] = 0;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w)
			{
				dis[v] = dis[u] + e[i].w;
				if(dis[v] < 0) return -inf;
				if(!inq[v]) q.push(v), inq[v] = 1;
			}
		}
	}
	
	for(int i=1; i<=m; ++i)
	{
		int u = es[i].first.first, v = es[i].first.second;
		if(es[i].second && dis[v] != dis[u] + 1) return -inf;
		if(!es[i].second && abs(dis[v] - dis[u]) != 1) return -inf;
	}
	
	return *max_element(dis+1, dis+n+1);
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		es[i] = make_pair(make_pair(u,v), w);
		if(w) add(u,v,1), add(v,u,-1);
		else add(u,v,1), add(v,u,1);
	}
	
	int ans = -inf, ansi = -1;
	for(int i=1; i<=n; ++i)
	{
		int res = get_dis(i);
		if(res > ans)
			ans = res, ansi = i;
	}
	
	if(ans < 0) printf("NO");
	else
	{
		get_dis(ansi);
		printf("YES\n%d\n",ans);
		for(int i=1; i<=n; ++i)
			printf("%d ",dis[i]);
	}
	return 0;
}