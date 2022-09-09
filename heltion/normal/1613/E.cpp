#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 998244353;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	for (cin >> t; t; t -= 1) {
		int n, m;
		cin >> n >> m;
		vector<string> vs(n);
		vector d(n, vector<int>(m));
		for (auto& s : vs) cin >> s;
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i += 1)
			for (int j = 0; j < m; j += 1) {
				if (vs[i][j] == '.') {
					if (i and vs[i - 1][j] != '#') d[i][j] += 1;
					if (i + 1 < n and vs[i + 1][j] != '#') d[i][j] += 1;
					if (j and vs[i][j - 1] != '#') d[i][j] += 1;
					if (j + 1 < m and vs[i][j + 1] != '#') d[i][j] += 1;
				}
				if (vs[i][j] == 'L')
					q.emplace(i, j);
			}
		while (not q.empty()) {
			auto [i, j] = q.front();
			q.pop();
			vector<int> di = {-1, 1, 0, 0}, dj = {0, 0, -1, 1};
			for (int k = 0; k < 4; k += 1) {
				int ni = i + di[k], nj = j + dj[k];
				if (ni < 0 or ni >= n or nj < 0 or nj >= m) continue;
				if (vs[ni][nj] == '.') {
					d[ni][nj] -= 1;
					if (d[ni][nj] <= 1) {
						vs[ni][nj] = '+';
						q.emplace(ni, nj);
					}
				}
			}
		}
		for (auto& s : vs) cout << s << "\n";
	}
	return 0;
}