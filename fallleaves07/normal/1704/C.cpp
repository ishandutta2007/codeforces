#include<bits/stdc++.h>
using LL = long long;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> loc(m), val(m);
	for (int i = 0; i < m; i++) {
		std::cin >> loc[i];
	}
	std::sort(loc.begin(), loc.end());
	for (int i = 0; i < m; i++) {
		val[i] = (loc[(i + 1) % m] - loc[i] - 1 + n) % n;
	}
	std::sort(val.begin(), val.end(), std::greater<int>());
	int ans = 0;
	for (int i = 0, t = 0; i < m; i++) {
		val[i] -= t * 2;
		if (val[i] > 1) {
			--val[i];
		}
		t += 2;
		ans += std::max(val[i], 0);
	}
	printf("%d\n", n - ans);
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