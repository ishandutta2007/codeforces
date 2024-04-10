#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), s = nxt();
	vector<vector<int>> a(n);
	vector<int> open;
	for (itn i = 0; i < n; ++i) {
		if (nxt() == 1) {
			open.push_back(i);
		}
	}
	for (int i = 0; i < (int)open.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			a[open[j]].push_back(open[i]);
		}
	}
	open.clear();
	for (itn i = 0; i < n; ++i) {
		if (nxt() == 1) {
			open.push_back(i);
		}
	}
	reverse(all(open));
	for (int i = 0; i < (int)open.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			a[open[j]].push_back(open[i]);
		}
	}

	vector<char> used(n, 0);
	vector<int> st = {0};
	used[0] = 1;
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		for (int x : a[v]) {
			if (!used[x]) {
				used[x] = 1;
				st.push_back(x);
			}
		}
	}
	cout << (used[s - 1] ? "YES" : "NO") << "\n";

	return 0;
}