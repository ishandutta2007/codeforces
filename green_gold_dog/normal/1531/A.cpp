#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll l = 0, n = 0;
	string ans = "blue";
	cin >> n;
	for (ll i = 0; i < n; i++) {
		string c;
		cin >> c;
		if (c == "lock") {
			l = 1;
		} else {
			if (c == "unlock") {
				l = 0;
			} else {
				if (!l) {
					ans = c;
				}
			}
		}
	}
	cout << ans;
}