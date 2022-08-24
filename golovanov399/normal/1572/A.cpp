#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void solve() {
	int n = nxt();
	vector<vector<int>> a(n);
	vector<int> rest(n);
	for (int i = 0; i < n; ++i) {
		int k = nxt();
		for (int j = 0; j < k; ++j) {
			int x = nxt() - 1;
			a[x].push_back(i);
			rest[i] += 1;
		}
	}

	set<int> S;
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		if (!rest[i]) {
			used[i] = true;
			S.insert(i);
		}
	}
	int ans = 1;
	int last = -1;
	while (!S.empty()) {
		auto it = S.lower_bound(last);
		if (it == S.end()) {
			++ans;
			it = S.begin();
		}
		int v = *it;
		S.erase(it);
		last = v;
		for (int x : a[v]) {
			if (--rest[x] == 0) {
				used[x] = 1;
				S.insert(x);
			}
		}
	}
	if (!*min_element(all(used))) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}