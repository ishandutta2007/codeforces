#include<bits/stdc++.h>
using LL = long long;

void solve() {
	int n, H, M, ts;
	std::cin >> n >> H >> M;
	ts = H * 60 + M;
	int ans = 24 * 60 + 1;
	for (int i = 0; i < n; i++) {
		int h, m, t;
		std::cin >> h >> m;
		t = h * 60 + m;
		ans = std::min(ans, (t - ts + 24 * 60) % (24 * 60));
	}
	printf("%d %d\n", ans / 60, ans % 60);
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