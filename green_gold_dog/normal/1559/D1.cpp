#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

void dfs(ll v, vector<ll>& color, vector<vector<ll>>& arr, ll now) {
	color[v] = now;
	for (auto u : arr[v]) {
		if (color[u] == -1) {
			dfs(u, color, arr, now);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m1, m2;
	cin >> n >> m1 >> m2;
	vector<vector<ll>> arr1(n), arr2(n);
	for (ll i = 0; i < m1; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		arr1[u].push_back(v);
		arr1[v].push_back(u);
	}
	for (ll i = 0; i < m2; i++) {
		ll u, v;
		cin >> u >> v;
		u--;
		v--;
		arr2[u].push_back(v);
		arr2[v].push_back(u);
	}
	vector<ll> color1(n, -1), color2(n, -1);
	ll cnt1 = 0, cnt2 = 0;
	for (ll i = 0; i < n; i++) {
		if (color1[i] == -1) {
			dfs(i, color1, arr1, cnt1);
			cnt1++;
		}
		if (color2[i] == -1) {
			dfs(i, color2, arr2, cnt2);
			cnt2++;
		}
	}
	vector<pair<ll, ll>> ans;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (color1[i] != color1[j] && color2[i] != color2[j]) {
				ans.push_back({i + 1, j + 1});
				ll m1 = color1[j], m2 = color2[j];
				for (ll k = 0; k < n; k++) {
					if (color1[k] == m1) {
						color1[k] = color1[i];
					}
				}
				for (ll k = 0; k < n; k++) {
					if (color2[k] == m2) {
						color2[k] = color2[i];
					}
				}
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto[u, v] : ans) {
		cout << u << ' ' << v << '\n';
	}
}

/*
















*/