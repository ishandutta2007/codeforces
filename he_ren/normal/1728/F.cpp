#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

ll a[MAXN * 2], b[MAXN * 2];

int main(void)
{
	int n;
	scanf("%d",&n);
	vector<int> val(n);
	for(int &t: val)
		scanf("%d",&t);
	
	map<ll,int> id;
	static vector<int> g[MAXN * 2];
	
	static int vis[MAXN * 2];
	auto bfs = [&] (int beg)
	{
		memset(vis, 0, (n*2+1)<<2);
		vector<int> q;
		vis[beg] = -1; q.emplace_back(beg);
		for(int hd=0; hd<(int)q.size(); ++hd)
		{
			int u = q[hd];
			for(int v: g[u]) if(vis[v] == 0)
				vis[v] = u, q.emplace_back(v);
		}
	};
	auto fl = [&] (int u)
	{
		while(id.count(b[u]))
		{
			g[u].emplace_back(id[b[u]]);
			b[u] += a[u];
		}
	};
	
	int X = 0, Y = n;
	sort(val.begin(), val.end());
	for(int t: val)
	{
		if(X == 0 || a[X] != t) ++X, a[X] = b[X] = t;
		for(int i=1; i<=X; ++i)
			fl(i);
		
		bfs(X);
		
		pair<ll,int> mn = {b[X], X};
		for(int i=1; i<=X; ++i) if(vis[i])
			mn = min(mn, make_pair(b[i], i));
		
		id[mn.first] = ++Y;
		g[Y] = {mn.second};
		
		int u = mn.second;
		while(vis[u] != -1)
		{
			u = vis[u];
			g[u][0] = vis[u];
			u = vis[u];
		}
	}
	
	ll ans = 0;
	for(auto t: id)
		ans += t.first;
	printf("%lld\n",ans);
	return 0;
}