#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;

const ll INF = 1e16;

ll cnt = 0, k;
vector <ll> ans;
vector <vector <pair <ll, ll>>> gg;

void dfs(ll u) {
	for (auto to : gg[u]) {
		if (cnt < k) {
			cnt++;
			ans.push_back(to.first);
		}
		dfs(to.second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m >> k;
	vector <vector <pair <ll, pair <ll, ll>>>> g(n);
	for (ll i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({ i, { v, w } });
		g[v].push_back({ i, { u, w } });
	}
	vector <ll> d(n, INF);
	vector <pair <ll, ll>> p(n, { -1, -1 });
	set <pair <ll, ll>> q;
	d[0] = 0;
	q.insert({ 0, 0 });
	while (!q.empty()) {
		pair <ll, ll> hm = *q.begin();
		q.erase(hm);
		ll v = hm.second;
		ll len = hm.first;
		for (auto to : g[v]) {
			if (to.second.second + len < d[to.second.first]) {
				q.erase({ d[to.second.first], to.second.first });
				d[to.second.first] = to.second.second + len;
				p[to.second.first].second = v;
				p[to.second.first].first = to.first;
				q.insert({ d[to.second.first], to.second.first });
			}
		}
	}
	gg.resize(n);
	for (ll i = 1; i < n; i++) 
		gg[p[i].second].push_back({ p[i].first, i });
	dfs(0);
	cout << ans.size() << endl;
	for (ll v : ans)
		cout << v + 1 << " ";
	return 0;
}