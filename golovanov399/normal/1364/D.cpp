#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 111111;
vector<int> a[N];

int main() {
	int n = nxt(), m = nxt(), k = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> cycle;
	vector<char> used(n);
	vector<char> color(n);
	function<bool(int, int)> dfs = [&](int v, int p) {
		used[v] = 1;
		cycle.push_back(v);
		for (int x : a[v]) {
			if (x == p || used[x] == 2) {
				continue;
			}
			if (!used[x]) {
				color[x] = color[v] ^ 1;
				if (dfs(x, v)) {
					return true;
				}
			} else {
				cycle.erase(cycle.begin(), find(all(cycle), x));
				return true;
			}
		}
		used[v] = 2;
		cycle.pop_back();
		return false;
	};

	dfs(0, -1);
	if (cycle.empty()) {
		vector<int> by_c[2];
		for (int i = 0; i < n; ++i) {
			by_c[(int)color[i]].push_back(i);
		}
		int idx = (int)by_c[1].size() >= (k + 1) / 2;
		by_c[idx].resize((k + 1) / 2);
		cout << 1 << "\n";
		for (int x : by_c[idx]) {
			cout << x + 1 << " ";
		}
		cout << "\n";
		return 0;
	}

	vector<char> in_cycle(n, false);
	for (int x : cycle) {
		in_cycle[x] = true;
	}
	vector<int> nx(n), pr(n);
	for (int i = 0; i < (int)cycle.size(); ++i) {
		int x = cycle[i];
		int y = cycle[(i + 1) % (int)cycle.size()];
		nx[x] = y;
		pr[y] = x;
	}
	int cnt = (int)cycle.size();
	for (int i = 0; i < n && cnt > k; ++i) {
		if (!in_cycle[i]) {
			continue;
		}
		for (int j : a[i]) {
			if (!in_cycle[j] || nx[i] == j || nx[j] == i) {
				continue;
			}
			int x = i, y = i;
			int cn = 0;
			while (y != j) {
				y = nx[y];
				cn += 1;
			}
			if (cn * 2 > cnt) {
				cn = cnt - cn;
				swap(x, y);
			}
			cnt = cn + 1;
			for (int z = nx[y]; z != x; z = nx[z]) {
				in_cycle[z] = 0;
			}
			nx[y] = x;
		}
	}
	{
		cycle.clear();
		int i = max_element(all(in_cycle)) - in_cycle.begin();
		int x = i;
		do {
			cycle.push_back(x);
			x = nx[x];
		} while (x != i);
	}
	if ((int)cycle.size() <= k) {
		cout << 2 << "\n";
		cout << cycle.size() << "\n";
		for (int x : cycle) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	} else {
		cout << 1 << "\n";
		for (int i = 0; i < (k + 1) / 2; ++i) {
			cout << cycle[2 * i] + 1 << " ";
		}
		cout << "\n";
	}

	return 0;
}