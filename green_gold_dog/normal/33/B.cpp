#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll to_ll(char c) {
	return c-'a';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000, col = 'z'-'a'+1;
	string s1, s2;
	cin >> s1 >> s2;
	ll m;
	cin >> m;
	vector<vector<ll>> arr(col, vector<ll>(col, INF));
	for (ll i = 0; i < col; i++) {
		arr[i][i] = 0;
	}
	for (ll i = 0; i < m; i++) {
		char c1, c2;
		ll c;
		cin >> c1 >> c2 >> c;
		arr[to_ll(c1)][to_ll(c2)] = min(arr[to_ll(c1)][to_ll(c2)], c);
	}
	for (ll k = 0; k < col; k++) {
		for (ll i = 0; i < col; i++) {
			for (ll j = 0; j < col; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j]);
			}
		}
	}
	ll ans = 0;
	if (s1.size() != s2.size()) {
		cout << -1;
		return 0;
	}
	vector<ll> a;
	for (ll i = 0; i < s1.size(); i++) {
		a.push_back(-1);
		ll now = INF;
		for (ll j = 0; j < col; j++) {
			if (now > arr[to_ll(s1[i])][j]+arr[to_ll(s2[i])][j]) {
				now = arr[to_ll(s1[i])][j]+arr[to_ll(s2[i])][j];
				a.back() = j;
			}
		}
		ans += now;
		if (now == INF) {
			cout << -1;
			return 0;
		}
	}
	cout << ans << '\n';
	for (auto i : a) {
		cout << (char)(i+'a');
	}
}