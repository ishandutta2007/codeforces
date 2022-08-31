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

const int mod = 998244353;

void solve() {
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vector<char> used(n);
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		if (used[i]) {
			continue;
		}
		vector<int> st = {i};
		used[i] = 1;
		int cnt[2] = {0, 0};
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			cnt[used[v] - 1] += 1;
			for (int x : a[v]) {
				if (used[x]) {
					if (used[x] == used[v]) {
						printf("0\n");
						return;
					}
					continue;
				}
				used[x] = used[v] ^ 3;
				st.push_back(x);
			}
		}
		long long tmp = 0;
		for (int x : cnt) {
			int y = 1;
			for (int j = 0; j < x; ++j) {
				y *= 2;
				if (y >= mod) {
					y -= mod;
				}
			}
			tmp += y;
		}
		ans = ans * tmp % mod;
	}
	printf("%lld\n", ans);
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}