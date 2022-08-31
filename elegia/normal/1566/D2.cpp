#include <bits/stdc++.h>

typedef unsigned long long ull;

const int N = 100010;
int fw[N];
void ch(int k, int x) { for (; k < N; k += k & -k) fw[k] += x; }
int qry(int k) { int ret = 0; for (; k; k &= k - 1) ret += fw[k]; return ret; }

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

	int T; std::cin >> T;
	while (T--) {
		int n, m; std::cin >> n >> m;
		std::map<int, std::vector<int>> mp;
		for (int i = 0; i != n * m; ++i) {
			int t; std::cin >> t;
			mp[t].push_back(i);
		}
		std::vector<std::vector<int>> id(n, std::vector<int>(m));
		int tot = 0;
		for (const auto& pr : mp) {
			std::vector<std::pair<int, int>> good;
			int sz = pr.second.size();
			for (int rep = 0; rep != sz; ++rep, ++tot) good.emplace_back(tot / m, -(tot % m));
			std::sort(good.begin(), good.end());
			for (int i = 0; i != sz; ++i) {
				int x, y; std::tie(x, y) = good[i];
				id[x][-y] = pr.second[i] + 1;
			}
		}
		int ans = 0;
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != m; ++j) ans += qry(id[i][j]), ch(id[i][j], 1);
			for (int j = 0; j != m; ++j) ch(id[i][j], -1);
		}
		std::cout << ans << '\n';
	}
	return 0;
}