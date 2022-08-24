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
	vector<vector<int>> where(n + 1);
	for (int i = 0; i < n; ++i) {
		where[nxt()].push_back(i);
	}
	for (int i = 0; i <= n; ++i) {
		reverse(all(where[i]));
	}
	vector<int> ans;
	for (int pos = 0; pos < n;) {
		if (where[0].empty()) {
			ans.push_back(0);
			++pos;
			continue;
		}
		int next_pos = pos;
		int i = 0;
		for (; i <= n && !where[i].empty(); ++i) {
			next_pos = max(next_pos, where[i].back());
		}
		ans.push_back(i);
		pos = next_pos + 1;
		while (i) {
			--i;
			while (!where[i].empty() && where[i].back() < pos) {
				where[i].pop_back();
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for (int x : ans) {
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