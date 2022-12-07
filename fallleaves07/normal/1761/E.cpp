#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> mp(n);
	vector<int> deg(n);
	for (int i = 0; i < n; i++) {
		cin >> mp[i];
		for (int j = 0; j < n; j++) {
			deg[i] += mp[i][j] - '1';
		}
	}
	vector<int> col(n, -1);
	vector<vector<int>> pts;
	int idc = -1;
	for (int i = 0; i < n; i++) {
		if (col[i] == -1) {
			col[i] = ++idc, pts.emplace_back();
			queue<int> que;
			que.push(i), pts.back().emplace_back(i);
			while (!que.empty()) {
				int v = que.front();
				que.pop();
				for (int j = 0; j < n; j++) {
					if (mp[v][j] == '1' && col[j] == -1) {
						col[j] = idc, que.push(j), pts.back().emplace_back(j);
					}
				}
			}
		}
	}
	if ((int)pts.size() == 1) {
		puts("0");
		return;
	}
	auto check = [&](vector<int> &vec) -> int {
		int r = -1;
		for (auto v : vec) {
			for (auto u : vec) {
				if (u != v && mp[u][v] != '1') {
					if (r == -1 || deg[r] > deg[u]) {
						r = u;
					}
					if (r == -1 || deg[r] > deg[v]) {
						r = v;
					}
				}
			}
		}
		return r;
	};
	int ans = n, ansid = -1;
	for (int i = 0; i < (int)pts.size(); i++) {
		int r = check(pts[i]);
		if (r != -1) {
			printf("1\n%d\n", r + 1);
			return;
		}
		if ((int)pts[i].size() <= ans) {
			ans = pts[i].size(), ansid = i;
		}
	}
	swap(pts[ansid], pts[0]);
	if ((int)pts.size() > 2 && ans > 2) {
		printf("2\n%d %d\n", pts[0].front() + 1, pts[1].front() + 1);
		return;
	}

	printf("%d\n", ans);
	for (auto v : pts[0]) {
		printf("%d ", v + 1);
	}
	puts("");
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}