#include<bits/stdc++.h>
using LL = long long;

bool solve() {
	int n, d12, d23, d31;
	std::cin >> n >> d12 >> d23 >> d31;
	int tot = (d12 + d23 + d31);
	if (tot % 2 != 0) {
		return false;
	}
	tot /= 2;
	int d1 = tot - d23, d2 = tot - d31, d3 = tot - d12, w = 4, cnt = 4;
	if (d1 == 0) {
		w = 1, cnt = 3;
	}
	if (d2 == 0) {
		w = 2, cnt = 3;
	}
	if (d3 == 0) {
		w = 3, cnt = 3;
	}
	std::vector<std::pair<int, int>> e;
	e.reserve(n - 1);
	auto work = [&](int u, int v, int len) {
		if (len < 0) {
			return false;
		}
		if (len == 0) {
			return u == v;
		}
		for (int i = 1; i < len; i++) {
			++cnt;
			e.emplace_back(u, cnt);
			u = cnt;
		}
		e.emplace_back(u, v);
		return true;
	};
	if (!work(w, 1, d1)) {
		return false;
	}
	if (!work(w, 2, d2)) {
		return false;
	}
	if (!work(w, 3, d3)) {
		return false;
	}
	if (cnt > n) {
		return false;
	}
	while (cnt < n) {
		e.emplace_back(1, ++cnt);
	}
	if ((int)e.size() != n - 1) {
		return false;
	}
	puts("YES");
	for (auto [u, v] : e) {
		printf("%d %d\n", u, v);
	}
	return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		if (!solve()) {
			puts("NO");
		}
	}
    return 0;
}