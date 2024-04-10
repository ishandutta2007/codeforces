#include <iostream>
#include <vector>
#include <queue>
#include <set>

typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector <ll> &sz, vector <vector <pair <ll, pair <ll, ll>>>> &g, vector <pair <pair <ll, ll>, ll>> &edges) {
	ll cnt = 0;
	for (auto e : g[v]) {
		if (e.first == p) continue;
		cnt++;
		dfs(e.first, v, sz, g, edges);
		sz[v] += sz[e.first];
		edges.push_back({ { sz[e.first], e.second.first }, e.second.second });
	}
	if (!cnt) sz[v] = 1;
}

void doo(multiset <pair <ll, pair <ll, ll>>> &se, ll &sum) {
	if (se.empty()) return;
	auto x = *se.rbegin();
	se.erase(se.find(x));
	sum += x.first;
	x.second.second /= 2;
	se.insert({ x.second.first * (x.second.second - x.second.second / 2), x.second });
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll s;
		cin >> s;
		vector <vector <pair <ll, pair <ll, ll>>>> g(n);
		for (ll i = 1; i < n; i++) {
			ll u, v, w, c;
			cin >> u >> v >> w >> c;
			u--, v--;
			g[u].push_back({ v, {w, c} });
			g[v].push_back({ u, {w, c} });
		}
		vector <ll> sz(n);
		vector <pair <pair <ll, ll>, ll>> edges;
		dfs(0, -1, sz, g, edges);
		ll cnt = 0;
		multiset <pair <ll, pair <ll, ll>>> se1, se2;
		ll sum = 0;
		for (ll i = 0; i < edges.size(); i++) {
			while (edges[i].first.first * edges[i].first.second > s) {
				cnt += edges[i].second;
				edges[i].first.second /= 2;
			}
			if (edges[i].second == 1) se1.insert({ edges[i].first.first * (edges[i].first.second - edges[i].first.second / 2), {edges[i].first.first, edges[i].first.second} });
			if (edges[i].second == 2) se2.insert({ edges[i].first.first * (edges[i].first.second - edges[i].first.second / 2), {edges[i].first.first, edges[i].first.second} });
			sum += edges[i].first.first * edges[i].first.second;
		}
		vector <ll> hm1, hm2;
		hm1.push_back(0), hm2.push_back(0);
		ll x = sum - s;
		ll sum0 = 0, sum1 = 0;
		for (int i = 0; i < 20 * n; i++) {
			doo(se1, sum0), doo(se2, sum1);
			hm1.push_back(sum0), hm2.push_back(sum1);
		}
		ll ans = 1e9;
		for (int i = 0; i < 20 * n; i++)
			ans = min(ans, (ll)i + 2 * (lower_bound(hm2.begin(), hm2.end(), x - hm1[i]) - hm2.begin()));
		cout << ans + cnt << '\n';
	}
	return 0;
}