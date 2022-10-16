#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	map<int, int> mp;
	int l = 0, r = 0;
	int q; cin >> q;
	while (q--) {
		char c;
		int x;
		cin >> c >> x;
		if (c == 'L') {
			mp[x] = --l;
		} else if (c == 'R') {
			mp[x] = r++;
		} else {
			cout << min(mp[x] - l, r - 1 - mp[x]) << "\n";
		}
	}	
	return 0;
}