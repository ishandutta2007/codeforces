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
		ll n;
		cin >> n;
		vector<ll> s;
		for (ll i = 0; i < n; i++) {
			ll c;
			cin >> c;
			if (c == 1) {
				s.push_back(1);
			} else {
				while ((s.size() > 0) && (c != s[s.size()-1]+1)) {
					s.pop_back();
				}
				if (s.size() == 0) {
					s.push_back(c);
				} else {
					s.pop_back();
					s.push_back(c);
				}
			}
			cout << s[0];
			for (ll j = 1; j < s.size(); j++) {
				cout << '.' << s[j];
			}
			cout << '\n';
		}
	}
}