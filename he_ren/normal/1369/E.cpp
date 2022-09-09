#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXM<<1];
int head[MAXN], etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u] = etot;
}

int w[MAXN];
vector<int> a[MAXN];
int b[MAXN];

int x[MAXM], y[MAXM];

queue<int> q;
bool vis[MAXN];

vector<int> ans;
bool inans[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&w[i]);
	for(int i=1; i<=m; ++i) scanf("%d%d",&x[i],&y[i]);
	
	for(int i=1; i<=m; ++i)
		a[x[i]].push_back(i),
		a[y[i]].push_back(i);
	
	for(int i=1; i<=n; ++i)
	{
		b[i] = a[i].size();
		if(b[i] <= w[i]) q.push(i), vis[i]=1;
	}
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0; i<(int)a[u].size(); ++i)
		{
			int p = a[u][i];
			if(inans[p]) continue;
			inans[p] = 1;
			ans.push_back(p);
			
			if(x[p] == u) swap(x[p], y[p]);
			if(vis[x[p]]) continue;
			
			--b[x[p]];
			if(b[x[p]] <= w[x[p]]) q.push(x[p]), vis[x[p]] = 1;
		}
	}
	
	if((int)ans.size() < m){ printf("DEAD\n"); return 0;}
	
	printf("ALIVE\n");
	reverse(ans.begin(),ans.end());
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	return 0;
}