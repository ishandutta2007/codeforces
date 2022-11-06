#include<bits/stdc++.h>
using LL = long long;
using HL = __int128;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<HL> val(n);
	for (int i = 0; i < n; i++) {
		std::vector<LL> a(m);
		for (int j = 0; j < m; j++) {
			std::cin >> a[j];
			if (j > 0) {
				a[j] += a[j - 1];
			}
			val[i] += a[j];
		}
	}
	HL mx = 0;
	for (auto v : val) {
		mx = std::max(mx, v);
	}
	for (int i = 0; i < n; i++) {
		if (val[i] < mx) {
			std::cout << i + 1 << ' ' << (LL)(mx - val[i]) << '\n';
		}
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}