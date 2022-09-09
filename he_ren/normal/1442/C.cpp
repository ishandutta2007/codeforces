#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int lb = 20;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

struct Edge
{
	int next,to;
	bool rev;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,bool rev)
{
	e[++etot] = (Edge){ head[u],v,rev};
	head[u] = etot;
}

struct Node
{
	int id,dis;
};
inline bool operator < (const Node &p,const Node &q){ return p.dis > q.dis;}

int n;
int dis[MAXN];

bool take_rev;
void stage1(int more,bool take_rev)
{
	static int lst[MAXN];
	static bool vis[MAXN];
	for(int i=1; i<=n; ++i) lst[i] = dis[i], vis[i] = 0;
	
	priority_queue<Node> q;
	for(int i=1; i<=n; ++i) if(dis[i] < inf)
		q.push((Node){i,dis[i]});
	
	while(!q.empty())
	{
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		
		for(int i=head[u]; i; i=e[i].next) if(e[i].rev == take_rev)
		{
			int v = e[i].to;
			if(dis[v] > dis[u] + 1)
				dis[v] = dis[u] + 1,
				q.push((Node){v,dis[v]});
		}
	}
	
	for(int i=1; i<=n; ++i)
		dis[i] = min(lst[i], dis[i] + more);
}

bool cango[MAXN];

vector<int> lst_vis;

void stage2(bool take_rev)
{
	static bool vis[MAXN];
	for(int i=0; i<(int)lst_vis.size(); ++i)
		vis[lst_vis[i]] = 0;
	
	priority_queue<Node> q;
	for(int i=0; i<(int)lst_vis.size(); ++i)
		q.push((Node){lst_vis[i], dis[lst_vis[i]]});
	
	static bool in_lst[MAXN];
	for(int i=0; i<(int)lst_vis.size(); ++i)
		in_lst[lst_vis[i]] = 1;
	
	vector<int> cur_vis;
	
	while(!q.empty())
	{
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		
		if(!cango[u]) cur_vis.push_back(u);
		cango[u] = 1;
		
		for(int i=head[u]; i; i=e[i].next) if(e[i].rev == take_rev)
		{
			int v = e[i].to;
			if(!in_lst[v] && cango[v]) continue;
			
			if(dis[v] > dis[u] + 1)
				dis[v] = dis[u] + 1,
				q.push((Node){v,dis[v]});
		}
	}
	
	for(int i=0; i<(int)lst_vis.size(); ++i)
		in_lst[lst_vis[i]] = 0;
	
	lst_vis = cur_vis;
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,0); add(v,u,1);
	}
	
	if(n == 1) return printf("0"), 0;
	
	memset(dis,0x3f,sizeof(dis));
	
	dis[1] = 0;
	stage1(0, 0);
	
	for(int k=0; k<=lb; ++k)
		stage1(1<<k, !(k&1));
	
	for(int i=1; i<=n; ++i)
		cango[i] = (dis[i] < inf);
	
	if(cango[n])
		return printf("%d",dis[n]%mod), 0;
	
	for(int i=1; i<=n; ++i)
		if(cango[i]) lst_vis.push_back(i);
	
	int pw2 = 1<<lb;
	int more = 0;
	for(int k=lb+1; !cango[n]; ++k)
	{
		pw2 = pw2 * 2 %mod;
		add_mod(more, pw2);
		stage2(!(k&1));
	}
	
	printf("%d",(dis[n] + more) %mod);
	return 0;
}