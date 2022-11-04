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
		string s1, s2;
		cin >> s1 >> s2;
		ll ans = 0;
		for (ll i = 0; i < n; i++) {
			if (s2[i] == '1') {
				if (s1[i] == '0') {
					ans++;
				} else {
					if (i != 0 && s1[i-1] == '1') {
						s1[i-1] = '2';
						ans++;
					} else {
						if (i != n-1 && s1[i+1] == '1') {
							s1[i+1] = '2';
							ans++;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}
}