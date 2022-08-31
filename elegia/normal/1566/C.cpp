#include <bits/stdc++.h>

typedef unsigned long long ull;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		int n; std::string s, t; std::cin >> n >> s >> t;
		std::vector<int> red(n);
		for (int i = 0; i != n; ++i) {
			red[i] |= 1 << (s[i] - '0');
			red[i] |= 1 << (t[i] - '0');
		}
		int ans = 0;
		for (int i = 0; i != n; ++i) {
			if (red[i] == 3) ans += 2;
			if (red[i] == 1) {
				if (i > 0 && red[i - 1] == 2) ans += 2;
				else if (i + 1 < n && red[i + 1] == 2) { ans += 2; red[i + 1] = 0; }
				else ++ans;
			}
		}
		std::cout << ans << '\n';
	}

	return 0;
}