#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s; --t;
	vector<vector<int>> adj(n);
	rep(i,0,m) {
		int u, v;
		cin >> u >> v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> min_dis(n, 1e9);
	vector<map<int, ll>> ways_for_dis(n);
	min_dis[s] = 0;
	ways_for_dis[s][0] = 1;
	priority_queue<pair<int, int>> pq;
	set<pair<int, int>> done;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		auto t = pq.top();
		pq.pop();
		if (done.count(t))
			continue;
		done.insert(t);
		int cur = t.second;
		int dis = -t.first;
		if (dis >= min_dis[cur]+2)
			continue;
		ll w = ways_for_dis[cur][dis];
		for (int to : adj[cur]) {
			ways_for_dis[to][dis+1] = (ways_for_dis[to][dis+1]+w)%MOD;
			if (dis+1 < min_dis[to]) {
				min_dis[to] = dis+1;
			}
			pq.push(make_pair(-(dis+1), to));
		}
	}
	ll ans = ways_for_dis[t][min_dis[t]];
	ans += ways_for_dis[t][min_dis[t]+1];
	ans %= MOD;
	cout << ans << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int T;
	cin >> T;
	while (T--)
		solve();
}