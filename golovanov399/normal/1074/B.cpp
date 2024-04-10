#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

void solve() {
	int n = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<char> used(n);
	int k1 = nxt();
	while (k1--) {
		used[nxt() - 1] = 1;
	}

	int k2 = nxt();
	vector<int> bitch(k2);
	for (int i = 0; i < k2; ++i) {
		bitch[i] = nxt() - 1;
	}

	cout << "B " << bitch[0] + 1 << endl;
	int idx = nxt() - 1;
	if (used[idx]) {
		cout << "C " << idx + 1 << endl;
		return;
	}

	vector<char> was(n, 0);
	was[idx] = 1;
	vector<int> st = {idx};
	int good = -1;
	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		for (int x : a[v]) {
			if (used[x]) {
				good = x;
				continue;
			} else if (was[x]) {
				continue;
			} else {
				was[x] = 1;
				st.push_back(x);
			}
		}
	}
	cout << "A " << good + 1 << endl;
	idx = nxt() - 1;
	for (int x : bitch) {
		if (x == idx) {
			cout << "C " << good + 1 << endl;
			return;
		}
	}
	cout << "C -1" << endl;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}