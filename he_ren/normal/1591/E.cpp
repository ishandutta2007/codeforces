#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int MAXQ = 1e6 + 5;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

int n,Q;
int a[MAXN];
vector<int> g[MAXN];
vector< array<int,3> > qs[MAXN];

int res[MAXQ];

int cnt[MAXN];
int seq[MAXN], pos[MAXN], rig[MAXN];

void dfs_res(int u)
{
	int x = a[u];
	int p1 = pos[x], p2 = rig[cnt[x]];
	swap(seq[p1], seq[p2]); pos[seq[p1]] = p1; pos[seq[p2]] = p2;
	--rig[cnt[x]]; ++cnt[x];
	
	for(auto it: qs[u])
	{
		int id = it[0], l = it[1], k = it[2];
		k = rig[l-1] + k;
		res[id] = k <= n? seq[k]: -1;
	}
	
	for(int v: g[u]) dfs_res(v);
	
	swap(seq[p1], seq[p2]); pos[seq[p1]] = p1; pos[seq[p2]] = p2;
	--cnt[x]; ++rig[cnt[x]];
}

void solve(void)
{
	n = read(); Q = read();
	for(int i=1; i<=n; ++i)
	{
		g[i].clear();
		qs[i].clear();
	}
	for(int i=1; i<=n; ++i) a[i] = read();
	for(int i=2; i<=n; ++i)
	{
		int x = read();
		g[x].push_back(i);
	}
	for(int i=1; i<=Q; ++i)
	{
		int v = read(), l = read(), k = read();
		qs[v].push_back({i, l, k});
	}
	
	for(int i=1; i<=n; ++i) seq[i] = pos[i] = i, cnt[i] = 0;
	for(int i=0; i<=n; ++i) rig[i] = n;
	
	dfs_res(1);
	
	for(int i=1; i<=Q; ++i) printf("%d ",res[i]);
	printf("\n");
}

int main(void)
{
	int T = read();
	while(T--) solve();
	return 0;
}