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
		ll n;
		cin >> n;
		string s;
		cin >> s;
		string s2 = s;
		sort(s2.begin(), s2.end());
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			if (s[i] != s2[i]) {
				ans++;
			}
		}
		cout << ans << '\n';
	}
}