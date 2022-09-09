#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXN = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int pre[MAXN], a[MAXN];

int size[MAXN], son[MAXN];
void dfs_son(int u)
{
	size[u] = 1; son[u] = -1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		dfs_son(v);
		size[u] += size[v];
		if(son[u] == -1 || size[son[u]] < size[v])
			son[u] = v;
	}
}

map<ll,int> t[MAXN];

void merge(map<ll,int> &p,map<ll,int> &q)// merge p to q
{
	for(map<ll,int>::iterator it = p.begin(); it != p.end(); ++it)
		q[it -> first] += it -> second;
	p.clear();
}

void dfs_t(int u,map<ll,int> &mp)
{
	if(size[u] == 1){ ++mp[a[u]]; return;}
	
	dfs_t(son[u],mp);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == son[u]) continue;
		
		dfs_t(v,t[v]);
		merge(t[v], mp);
	}
	
	ll mx = mp.rbegin() -> first;
	while(a[u] && mp.size() > 1)
	{
		ll cur = mp.begin() -> first;
		int cnt = mp.begin() -> second;
		
		int use = min(a[u] / (mx - cur), (ll)cnt);
		
		mp[mx] += use;
		cnt -= use; mp[cur] -= use;
		a[u] -= use * (mx - cur);
		
		if(cnt && a[u])
		{
			++mp[cur + a[u]];
			--cnt; --mp[cur];
			a[u] = 0;
		}
		
		if(!cnt) mp.erase(mp.begin());
	}
	
	if(a[u])
	{
		int cnt = mp.begin() -> second;
		mp.erase(mp.begin());
		
		int inc = a[u]/cnt, more = a[u]%cnt;
		mp[mx + inc] = cnt - more;
		if(more) mp[mx + inc + 1] = more;
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=2; i<=n; ++i)
		scanf("%d",&pre[i]),
		add(pre[i],i);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	dfs_son(1);
	
	dfs_t(1,t[1]);
	printf("%lld",t[1].rbegin() -> first);
	return 0;
}