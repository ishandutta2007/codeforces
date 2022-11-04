#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void dfs(ll v1, ll v2, vector<vector<multiset<pair<ll, ll>>>>& arr, vector<pair<ll, ll>>& ans) {
	while (!arr[v1][v2].empty()) {
		auto[u1, u2] = *arr[v1][v2].begin();
		arr[v1][v2].erase(arr[v1][v2].find({u1, u2}));
		dfs(u1, u2, arr, ans);
	}
	ans.push_back({v1, v2});
}

const ll ci = 10, cmc = 26;
const ll ca = cmc * 2 + ci;

ll to_ll(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + ci;
	}
	return c - 'A' + cmc + ci;
}

char to_char(ll x) {
	if (x < ci) {
		return (char)(x + '0');
	}
	if (x < cmc + ci) {
		return (char)(x + 'a' - ci);
	}
	return (char)(x + 'A' - cmc - ci);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<multiset<pair<ll, ll>>>> arr(ca, vector<multiset<pair<ll, ll>>>(ca)), arr2(ca, vector<multiset<pair<ll, ll>>>(ca));
	ll n;
	cin >> n;
	ll f1, f2;
	for (ll i = 0; i < n; i++) {
		char c1, c2, c3;
		cin >> c1 >> c2 >> c3;
		f1 = to_ll(c1);
		f2 = to_ll(c2);
		arr[to_ll(c1)][to_ll(c2)].insert({to_ll(c2), to_ll(c3)});
		arr2[to_ll(c2)][to_ll(c3)].insert({to_ll(c1), to_ll(c2)});
	}
	ll col = 0;
	for (ll i = 0; i < ca; i++) {
		for (ll j = 0; j < ca; j++) {
			col += arr[i][j].size() != arr2[i][j].size();
			if (abs((ll)arr[i][j].size() - (ll)arr2[i][j].size()) > 1) {
				cout << "NO";
				return 0;
			}
			if (arr[i][j].size() > arr2[i][j].size()) {
				f1 = i;
				f2 = j;
			}
		}
	}
	vector<pair<ll, ll>> ans;
	if (col > 2) {
		cout << "NO";
		return 0;
	}
	dfs(f1, f2, arr, ans);
	for (ll i = 0; i < ca; i++) {
		for (ll j = 0; j < ca; j++) {
			if (arr[i][j].size() > 0) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES\n";
	reverse(ans.begin(), ans.end());
	cout << to_char(f1) << to_char(f2);
	for (ll i = 1; i < ans.size(); i++) {
		cout << to_char(ans[i].second);
	}
}