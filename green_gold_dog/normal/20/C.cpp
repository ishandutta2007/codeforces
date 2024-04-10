#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<vector<pair<ll, ll>>> arr(n, vector<pair<ll, ll>>(0, {0, 0}));
	for (ll i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr[a].push_back({b, c});
		arr[b].push_back({a, c});
	}
	vector<ll> dist(n, INF), pred(n, -1);
	dist[0] = 0;
	set<pair<ll, ll>> s;
	for (ll i = 0; i < n; i++) {
		s.insert({dist[i], i});
	}
	while (!s.empty()) {
		ll now = s.begin()->second;
		s.erase(s.begin());
		for (auto[v, c] : arr[now]) {
			if (dist[v] > dist[now] + c) {
				s.erase(s.find({dist[v], v}));
				dist[v] = dist[now] + c;
				pred[v] = now;
				s.insert({dist[v], v});
			}
		}
	}
	if (dist[n - 1] == INF) {
		cout << -1;
		return 0;
	}
	vector<ll> ans;
	ll now = n - 1;
	while (now != -1) {
		ans.push_back(now);
		now = pred[now];
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i + 1<< ' ';
	}
}

/*
















*/