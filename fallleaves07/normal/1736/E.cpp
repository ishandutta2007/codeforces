#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const LL lnf = 4.5e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	vector f(n + 1, array<array<LL, 501>, 501>{});
	for (int i = 0; i < n; i++) {
		for (auto &j : f[i]) {
			j.fill(-lnf);
		}
	}
	f[1][1][1] = a[1], f[1][2][0] = a[2];
	auto upd = [](LL &v, LL x) {
		if (v < x) {
			v = x;
		}
	};
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= i; k++) {
				if (f[i][j][k] >= 0) {
					upd(f[i + 1][j][k], f[i][j][k] + a[j]);
					if (j < i + 1) {
						upd(f[i + 1][i + 1][k + 1], f[i][j][k] + a[i + 1]);
					}
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= i; k++) {
				upd(f[i][j][k], f[i][j - 1][k]);
			}
		}
		for (int j = i; j < n; j++) {
			for (int k = max(0, j - i - 1); k <= i; k++) {
				if (f[i][j][k] >= 0) {
					upd(f[i + 1][j + 1][k + 1 - (j - i)], f[i][j][k] + a[j + 1]);
				}
			}
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			ans = max(ans, f[n][i][j]);
		}
	}
	printf("%lld\n", ans);
    return 0;
}