#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v, ll p, vector<vector<ll>>& arr, vector<ll>& k, ll col, ll& ans, ll now) {
	now = ((k[v] == 1) ? now+1 : 0);
	if (now <= col) {
		bool f = true;
		for (auto i : arr[v]) {
			if (i != p) {
				f = false;
				dfs(i, v, arr, k, col, ans, now);
			}
		}
		if (f) {
			ans++;
		}
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, col, ans = 0;
	cin >> n >> col;
	vector<ll> k(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> k[i];
	}
	vector<vector<ll>> arr(n, vector<ll>(0, 0));
	for (ll i = 0; i < n-1; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(0, -1, arr, k, col, ans, 0);
	cout << ans;
}