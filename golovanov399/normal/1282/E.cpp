#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	map<pair<int, int>, vector<int>> M;
	int n = nxt();
	vector<array<int, 3>> tr(n - 2);
	for (int i = 0; i < n - 2; ++i) {
		int q[3];
		generate(q, q + 3, nxt);
		for (int j = 0; j < 3; ++j) {
			int x = q[j];
			int y = q[(j + 1) % 3];
			if (x > y) {
				swap(x, y);
			}
			M[{x, y}].push_back(i);
		}
		tr[i] = {q[0]-1, q[1]-1, q[2]-1};
	}

	vector<vector<int>> ed(n - 2);
	for (auto it : M) {
		if (it.second.size() < 2) {
			continue;
		}
		int x = it.second[0];
		int y = it.second[1];
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	vector<int> deg(n - 2);
	set<pair<int, int>> S;
	for (int i = 0; i < n - 2; ++i) {
		deg[i] = ed[i].size();
		S.insert({deg[i], i});
	}

	vector<char> used(n - 2, 0);
	vector<int> order;

	while (!S.empty()) {
		int idx = S.begin()->second;
		S.erase(S.begin());
		order.push_back(idx + 1);
		for (int j : ed[idx]) {
			if (!used[j]) {
				S.erase({deg[j], j});
				--deg[j];
				S.insert({deg[j], j});
			}
		}
		used[idx] = 1;
	}
	reverse(all(order));

	vector<int> nx(n, -1);
	for (int i = 0; i < 3; ++i) {
		nx[tr[order[0] - 1][i]] = tr[order[0] - 1][(i + 1) % 3];
	}
	for (int i = 1; i < n - 2; ++i) {
		int idx = order[i] - 1;
		int xx = -1, yy = -1;
		for (int x : tr[idx]) {
			for (int y : tr[idx]) {
				if (nx[x] == y) {
					xx = x;
					yy = y;
					break;
				}
			}
		}
		int zz = -1;
		for (int x : tr[idx]) {
			if (x != xx && x != yy) {
				zz = x;
			}
		}
		nx[xx] = zz;
		nx[zz] = yy;
	}

	reverse(all(order));
	for (int i = 0, j = 0; i < n; ++i, j = nx[j]) {
		printf("%d ", j + 1);
	}
	printf("\n");
	for (int x : order) {
		printf("%d ", x);
	}
	printf("\n");
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}