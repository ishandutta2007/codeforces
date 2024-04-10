#include <bits/stdc++.h>

typedef unsigned long long ull;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		std::string s; std::cin >> s;
		std::vector<int> vec(3);
		for (char c : s) ++vec[c - '0'];
		int ans = 0; while (vec[ans]) ++ans;
		if (ans == 2) {
			int l = 0, r = s.length() - 1;
			while (s[l] != '0') ++l;
			while (s[r] != '0') --r;
			if (!std::count(s.begin() + l, s.begin() + r, '1')) ans = 1;
		}
		std::cout << ans << '\n';
	}

	return 0;
}