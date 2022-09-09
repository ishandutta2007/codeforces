#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN * 2];
int head[MAXN * 2], etot=0, deg[MAXN * 2];
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
	++deg[v];
}

int a[MAXN];

inline int idx(int i,int x){ return i*2 - x;}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=2; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=2; i<=n; ++i)
	{
		if(i + a[i] <= n) add(idx(i + a[i], 1), idx(i, 0));
		if(i - a[i] >= 1) add(idx(i - a[i], 0), idx(i, 1));
	}
	
	static ll ans[MAXN * 2];
	
	for(int i=1; i<=n*2; ++i)
		ans[i] = a[(i+1)/2];
	
	queue<int> q;
	for(int i=3; i<=n*2; ++i)
		if(!deg[i])
			q.push(i);
	
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			--deg[v];
			ans[v] += ans[u];
			if(!deg[v]) q.push(v);
		}
	}
	
	for(int i=2; i<=n; ++i)
	{
		if(deg[idx(i,1)]) printf("-1\n");
		else printf("%lld\n",ans[idx(i,1)] + i-1);
	}
	return 0;
}