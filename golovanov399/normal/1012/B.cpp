#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt(), m = nxt(), q = nxt();
	vector<vector<int>> a(m);
	for (int i = 0; i < q; ++i) {
		int x = nxt() - 1, y = nxt() - 1;
		a[y].push_back(x);
	}

	vector<vector<int>> to(n);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < (int)a[i].size() - 1; ++j) {
			to[a[i][j]].push_back(a[i][j + 1]);
			to[a[i][j + 1]].push_back(a[i][j]);
		}
	}

	int comps = 0;
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector<int> st = {i};
		used[i] = 1;
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			for (int x : to[v]) {
				if (used[x]) {
					continue;
				}
				st.push_back(x);
				used[x] = 1;
			}
		}
		++comps;
	}

	int ans = comps - 1;
	for (int i = 0; i < m; ++i) {
		if (a[i].empty()) {
			ans += 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}