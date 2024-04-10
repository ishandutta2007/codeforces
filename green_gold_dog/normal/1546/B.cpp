#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		ll n, m;
		cin >> n >> m;
		vector<vector<ll>> arr(m, vector<ll>(30, 0));
		for (ll i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (ll j = 0; j < m; j++) {
				arr[j][s[j]-'a']++;
			}
		}
		for (ll i = 1; i < n; i++) {
			string s;
			cin >> s;
			for (ll j = 0; j < m; j++) {
				arr[j][s[j]-'a']--;
			}
		}
		for (ll i = 0; i < m; i++) {
			for (ll j = 0; j < 30; j++) {
				if (arr[i][j] == 1) {
					cout << (char)('a'+j);
				}
			}
		}
		cout << '\n';
	}
}