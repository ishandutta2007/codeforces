#include <bits/stdc++.h>

typedef unsigned long long ull;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		int n, s; std::cin >> n >> s;
		n = n - (n + 1) / 2 + 1; std::cout << s / n << '\n';
	}

	return 0;
}