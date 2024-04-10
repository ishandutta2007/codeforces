#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define ll long long

using namespace std;

const ll INF = 1000000000000000000;

vector <vector <pair <ll, ll>>> g;

int main() {
	ll n, m;
	cin >> n >> m;
	g.resize(n);
	for (ll i = 0; i < m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({ w, v });
		g[v].push_back({ w, u });
	}
	ll s = 0;
	vector <ll> d(n, INF), p(n);
	d[s] = 0;
	set <pair <ll, ll>> q;
	q.insert({ d[s], s });
	while (!q.empty()) {
		ll v = q.begin()->second;
		q.erase(q.begin());
		for (auto to : g[v])
			if (d[v] + to.first < d[to.second]) {
				q.erase({ d[to.second], to.second });
				d[to.second] = d[v] + to.first;
				p[to.second] = v;
				q.insert({ d[to.second], to.second });
			}
	}
	if (d[n - 1] != INF) {
		vector <ll> path;
		for (ll i = n - 1; i > 0; i = p[i])
			path.push_back(i);
		path.push_back(0);
		reverse(path.begin(), path.end());
		for (auto now : path)
			cout << now + 1 << " ";
	}
	else
		cout << "-1";
	return 0;
}