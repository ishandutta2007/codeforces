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
		ll n, m;
		cin >> n >> m;
		ll bz = 0;
		string s;
		cin >> s;
		vector<ll> ones(1, -1000000000000);
		for (ll i = 0; i < n; i++) {
			if (s[i] == '1') {
				ones.push_back(i);
			}
		}
		ones.push_back(1000000000000);
		for (ll i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (i-ones[bz] != ones[bz+1]-i) {
					if ((i-ones[bz] <= m) || (ones[bz+1]-i <= m)) {
						cout << 1;
						continue;
					}
				}
			} else {
				bz++;
			}
			cout << s[i];
		}
		cout << '\n';
	}
}