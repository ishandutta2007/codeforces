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
	vector<int> b(n);
	generate(all(b), nxt);
	vector<vector<int>> where(n + 2);
	for (int i = 0; i < n; ++i) {
		where[b[i]].push_back(i);
	}
	vector<int> cands = {0, n + 1};
	vector<int> ans;
	int k = 0;
	int curcol = -1;
	while (true) {
		int opt = -1;
		for (int x : cands) {
			if (where[x].empty()) {
				continue;
			} else {
				assert(opt == -1);
				opt = x;
			}
		}
		if (opt == -1) {
			ans.insert(ans.end(), all(cands));
			assert((int)ans.size() == n);
			break;
		}
		if (curcol == -1) {
			curcol = !!opt;
		} else {
			curcol ^= 1;
		}
		if (cands[0]) {
			for (int x : cands) {
				if (x != opt) {
					ans.push_back(x);
				}
			}
			ans.push_back(opt);
		}
		cands = where[opt];
		for (auto& x : cands) {
			k += curcol;
			++x;
		}
	}
	cout << k << "\n";
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}