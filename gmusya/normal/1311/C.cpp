#include <iostream>
#include <vector>
#include <string>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		vector <vector <ll>> pre(n + 1, vector <ll>(26));
		vector <ll> ans(26);
		for (ll i = 1; i <= n; i++) {
			pre[i] = pre[i - 1];
			pre[i][s[i - 1] - 'a']++;
		}
		while (m--) {
			ll pos;
			cin >> pos;
			for (ll i = 0; i < 26; i++)
				ans[i] += pre[pos][i];
		}
		for (ll i = 0; i < n; i++)
			ans[s[i] - 'a']++;
		for (ll i = 0; i < 26; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}