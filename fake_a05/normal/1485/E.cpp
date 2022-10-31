#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 2e5 + 5, inf = LLONG_MAX / 1000ll;

int N, par[maxN], a[maxN], h[maxN], dp[maxN], ndp[maxN];
vi s[maxN], G[maxN];

bool cmp (int u, int v){
	return a[u] < a[v];
}

void dfs(int u)
{
//	cout << u << sp << par[u] << endl;
	s[h[u]].eb(u);
	for(int v: G[u]){
		if(v == par[u]) continue;
		par[v] = u;
		h[v] = h[u] + 1;
		dfs(v);
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> N;
		loop(i, 1, N) 
		{
			dp[i] = ndp[i] = -inf;
			s[i].clear();
			G[i].clear();
		}
		loop(i, 2, N) 
		{
			int j; cin >> j;
			G[i].eb(j);
			G[j].eb(i);
		}
		loop(i, 2, N) cin >> a[i];
		h[1] = 0;
		dfs(1);
		ndp[1] = 0;
		loop(l, 1, N)
		{
			if(s[l].empty()) break;
			sort(all(s[l]), cmp);
			int mn = inf, mx = -inf;
			for(int u: s[l]) 
			{
				dp[u] = ndp[par[u]];
				mn = min(mn, a[u]);
				mx = max(mx, a[u]);
			}
			for(int u: s[l])
			{
				ndp[u] = max(ndp[u], dp[u] + mx - a[u]);
				ndp[u] = max(ndp[u], dp[u] + a[u] - mn);
				assert(ndp[u] >= dp[u]);
			}
			mx = -inf;
			for(int u: s[l])
			{
				mx = max(mx, dp[u] - a[u]);
				ndp[u] = max(ndp[u], mx + a[u]);	
			}
			reverse(all(s[l]));
			mx = -inf;
			for(int u: s[l])
			{
				mx = max(mx, dp[u] + a[u]);
				ndp[u] = max(ndp[u], mx - a[u]);
			}
		}
		int ans = -inf;
		loop(i, 1, N) ans = max(ans, ndp[i]);
		cout << ans << endl;
	}
}