#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		string s;
		cin >> s;
		ll ans = 0;
		ll last = 0, lc = '?';
		ll u1 = 0, u2 = 0;
		while (u2 < s.size()) {
			if ((s[u2] == '?') || (lc == '?')) {
				if (s[u2] != '?') {
					last = u2;
					lc = s[u2];
				}
				u2++;
				ans += u2-u1;
			} else {
				if ((u2-last) % 2 == 1) {
					if (lc != s[u2]) {
						last = u2;
						lc = s[u2];
						u2++;
						ans += u2-u1;
					} else {
						lc = '?';
						u1 = last + 1;
					}
				} else {
					if (lc == s[u2]) {
						last = u2;
						lc = s[u2];
						u2++;
						ans += u2-u1;
					} else {
						lc = '?';
						u1 = last + 1;
					}
				}
			}
		}
		cout << ans << '\n';
	}
}