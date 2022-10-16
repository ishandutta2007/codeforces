#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, q;
	cin >> n >> q;
	while (q--) {
		int u;
		cin >> u;
		int level = 0;
		for (int start = 1; start < n + 1; start <<= 1) {
			if ((u - start) % (start << 1) == 0) {
				level = start;
				break;
			}
		}
		int delta = (level << 1);
		string s;
		cin >> s;
		for (char &c: s) {
			bool left = (u % (delta << 1)) < ((u + delta) % (delta << 1));
			if (c == 'U') {
				int v = u + (delta >> 1) * (left ? 1 : -1);
				if (v > n || v < 1) continue;
				u = v;
				delta <<= 1;
			} else {
				if (u % 2 == 1) continue;
				u += (delta >> 2) * (c == 'R' ? 1 : -1);
				delta >>= 1;
			}
		}
		cout << u << "\n";
	}
	return 0;	
}