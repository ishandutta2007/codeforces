#include<bits/stdc++.h>
using LL = long long;

bool solve() {
	int n, m;
	std::cin >> n >> m;
	std::string s, t;
	std::cin >> s >> t;
	for (int i = 1; i < m; i++) {
		if (s[n - (m - i)] != t[i]) {
			return false;
		}
	}
	for (int i = 0; i <= n - m; i++) {
		if (s[i] == t[0]) {
			return true;
		}
	}
	return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		puts(solve() ? "YES" : "NO");
	}
    return 0;
}