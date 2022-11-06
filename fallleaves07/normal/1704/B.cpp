#include<bits/stdc++.h>
using LL = long long;

void solve() {
	int n, x;
	std::cin >> n >> x;
	int l = -x, r = 1e9 + x, ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		l = std::max(l, a - x);
		r = std::min(r, a + x);
		if (l > r) {
			++ans;
			l = a - x, r = a + x;
		}
	}
	printf("%d\n", ans);
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