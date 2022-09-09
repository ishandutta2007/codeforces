#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int inf = 0x3f3f3f3f;

vector<int> ga[MAXN], gb[MAXN];

int siz[MAXN], dfn[MAXN], cur_dfn = 0;
void dfs_tree_b(int u)
{
	siz[u] = 1;
	dfn[u] = ++cur_dfn;
	for(int i=0; i<(int)gb[u].size(); ++i)
	{
		int v = gb[u][i];
		dfs_tree_b(v);
		siz[u] += siz[v];
	}
}

int res = 0;
set<pii> t;
void dfs_res(int u)
{
	int sav = -1;
	set<pii>::iterator it = t.upper_bound(make_pair(dfn[u], inf));
	if(it != t.begin())
	{
		--it;
		int tmp = it -> second;
		if(dfn[tmp] + siz[tmp] - 1 >= dfn[u])
			sav = tmp, t.erase(it);
	}
	t.insert(make_pair(dfn[u], u));
	
	res = max(res, (int)t.size());
	for(int i=0; i<(int)ga[u].size(); ++i)
		dfs_res(ga[u][i]);
	
	t.erase(make_pair(dfn[u], u));
	if(sav != -1) t.insert(make_pair(dfn[sav], sav));
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		ga[i].clear(), gb[i].clear();
	for(int i=2; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		ga[x].push_back(i);
	}
	for(int i=2; i<=n; ++i)
	{
		int x;
		scanf("%d",&x);
		gb[x].push_back(i);
	}
	
	cur_dfn = 0;
	dfs_tree_b(1);
	
	res = 1;
	t.clear();
	dfs_res(1);
	
	printf("%d\n",res);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}