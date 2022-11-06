#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, rr = 0, cc = 0, rm = 0, cm = 0;
	vector<int> r(3), c(3);
	cin >> n;
	for (int i = 0; i < 3; i++) {
		cin >> r[i] >> c[i];
		rr ^= r[i], cc ^= c[i];
	}
	for (int i = 0; i < 3; i++) {
		if (r[i] != rr) {
			rm = r[i];
		}
		if (c[i] != cc) {
			cm = c[i];
		}
	}
	int x, y;
	cin >> x >> y;
	if ((rm == 1 || rm == n) && (cm == 1 || cm == n)) {
		if (x == rm || y == cm) {
			puts("YES");
		} else {
			puts("NO");
		}
		return;
	}
	if (x % 2 == rr % 2 && y % 2 == cc % 2) {
		puts("NO");
	} else {
		puts("YES");
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}