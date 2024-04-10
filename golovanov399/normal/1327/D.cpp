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

void solve() {
	int n = nxt();
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[i] = nxt() - 1;
	}
	vector<int> c(n);
	generate(all(c), nxt);
	vector<char> used(n);
	vector<vector<vector<int>>> cycles(n + 1);
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector<int> cycle;
		for (int j = i; !used[j]; j = p[j]) {
			used[j] = 1;
			cycle.push_back(c[j]);
		}
		cycles[cycle.size()].push_back(cycle);
	}
	for (int d = 1; d <= n; ++d) {
		for (int i = d; i <= n; i += d) {
			for (const auto& cycle : cycles[i]) {
				vector<int> reprs(d, -1);
				for (int j = 0; j < i; ++j) {
					if (reprs[j % d] == -1) {
						reprs[j % d] = cycle[j];
					} else if (reprs[j % d] != cycle[j]) {
						reprs[j % d] = -2;
					}
				}
				if (*max_element(all(reprs)) >= 0) {
					cout << d << "\n";
					return;
				}
			}
		}
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}