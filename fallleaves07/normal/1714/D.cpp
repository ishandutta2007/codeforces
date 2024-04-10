#include<bits/stdc++.h>
using LL = long long;

void solve() {
	std::string t;
	int n;
	std::cin >> t >> n;
	std::vector<std::string> s(n);
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	auto check = [&](int loc, const std::string &s) {
		int sl = s.length() - 1;
		for (int i = sl, j = loc; i >= 0; i--, j--) {
			if (j < 0 || s[i] != t[j]) {
				return false;
			}
		}
		return true;
	};
	const int inf = 0x3f3f3f3f;
	int m = t.length();
	std::vector<int> f(m + 1, inf), g(m + 1, inf), frg(m + 1), frf(m + 1), idf(m + 1);
	f[0] = g[0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i - 1, s[j])) {
				int id = i - (int)s[j].length();
				if (g[id] + 1 < f[i]) {
					f[i] = g[id] + 1;
					frf[i] = frg[id];
					idf[i] = j;
				}
			}
		}
		for (int j = i; j >= 0; j--) {
			if (f[i] < g[j]) {
				g[j] = f[i];
				frg[j] = i;
			}
		}
	}
	if (f[m] > m) {
		puts("-1");
	} else {
		printf("%d\n", f[m]);
		for (int v = m; v; v = frf[v]) {
			printf("%d %d\n", idf[v] + 1, v - (int)s[idf[v]].length() + 1);
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