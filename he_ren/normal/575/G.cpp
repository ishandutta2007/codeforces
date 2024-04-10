#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
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

int n;

int nxt_zero[MAXN];
void bfs_zero(void)
{
	memset(nxt_zero, -1, sizeof(nxt_zero));
	queue<int> q;
	
	nxt_zero[n] = 0;
	q.push(n);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next) if(!e[i].w)
		{
			int v = e[i].to;
			if(nxt_zero[v] == -1)
				nxt_zero[v] = u,
				q.push(v);
		}
	}
}

void bfs_dis(int start,int dis[MAXN])
{
	for(int i=1; i<=n; ++i) dis[i] = inf;
	queue<int> q;
	
	dis[start] = 0;
	q.push(start);
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(dis[v] == inf)
				dis[v] = dis[u] + 1,
				q.push(v);
		}
	}
}

int dep[MAXN], nxt[MAXN], dis_n[MAXN];

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		++u; ++v;
		add(u,v,w); add(v,u,w);
	}
	
	bfs_zero();
	
	bfs_dis(1, dep);
	bfs_dis(n, dis_n);
	
	int mn_dep = inf;
	vector<int> node;
	
	memset(nxt,-1,sizeof(nxt));
	
	for(int i=1; i<=n; ++i) if(nxt_zero[i] != -1)
	{
		nxt[i] = nxt_zero[i];
		if(dep[i] < mn_dep) mn_dep = dep[i], node.clear();
		if(dep[i] == mn_dep) node.push_back(i);
	}
	
	while(node[0] != 1)
	{
		int mnw = inf;
		vector<int> nxt_node;
		
		for(int k=0; k<(int)node.size(); ++k)
		{
			int u = node[k];
			for(int i=head[u]; i; i=e[i].next)
			{
				int v = e[i].to;
				if(dep[v] != dep[u]-1) continue;
				
				if(e[i].w < mnw)
				{
					mnw = e[i].w;
					for(int j=0; j<(int)nxt_node.size(); ++j)
						nxt[nxt_node[j]] = -1;
					nxt_node.clear();
				}
				if(e[i].w == mnw)
				{
					if(nxt[v] == -1)
						nxt[v] = u, nxt_node.push_back(v);
					else if(dis_n[nxt[v]] > dis_n[u])
						nxt[v] = u;
				}
			}
		}
		
		node = nxt_node;
		
		putchar(mnw + '0');
	}
	if(nxt_zero[1] != -1) printf("0");
	putchar('\n');
	
	vector<int> ans;
	int u = 1;
	while(u != n)
		ans.push_back(u), u = nxt[u];
	ans.push_back(n);
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d ",ans[i] - 1);
	return 0;
}