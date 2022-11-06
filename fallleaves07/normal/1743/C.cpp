#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector f(n + 1, array<LL, 2>{-1, -1});
	f[n][0] = 0;
	auto upd = [](LL &v, LL val) {
		if (val > v) {
			v = val;
		}
	};
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 2; j++) {
			if (f[i + 1][j] >= 0) {
				if (j == 1) {
					upd(f[i][s[i] - '0'], f[i + 1][j] + a[i]);
				} else {
					if (s[i] == '1') {
						upd(f[i][0], f[i + 1][j] + a[i]);
						upd(f[i][1], f[i + 1][j]);
					} else {
						upd(f[i][0], f[i + 1][j]);
					}
				}
			}
		}
	}
	printf("%lld\n", f[0][0]);
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