#include<bits/stdc++.h>
using LL = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::set<int> num;
	int ans = n;
	for (int i = n - 1; i >= 0; i--) {
		if (!num.count(a[i])) {
			num.insert(a[i]);
		} else {
			break;
		}
		ans = std::min(ans, i);
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