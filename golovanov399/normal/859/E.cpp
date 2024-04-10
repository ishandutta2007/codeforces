#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

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

const int mod = 1000000007;

int main() {
	int n = nxt();
	vector<int> to(n + n, -1);
	vector<vector<int>> a(n + n);
	for (int i = 0; i < n; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		to[u] = v;
		a[v].push_back(u);
	}

	int ans = 1;
	vector<char> used(n + n, 0);
	for (int i = 0; i < n + n; ++i) {
		if (to[i] > -1 || used[i] || a[i].empty()) {
			continue;
		}

		vector<int> st = {i};
		int k = 0;
		while (!st.empty()) {
			int v = st.back();
			st.pop_back();
			used[v] += 1;
			k += 1;
			for (int x : a[v]) {
				st.push_back(x);
			}
		}
		ans = 1ll * ans * k % mod;
	}

	vector<int> num(n + n, -1);
	for (int i = 0; i < n + n; ++i) {
		if (used[i] || to[i] == -1) {
			continue;
		}

		int v = i;
		int cur = 0;
		bool ok = true;
		vector<int> tmp;
		while (num[v] == -1) {
			tmp.push_back(v);
			num[v] = cur++;
			v = to[v];
			if (used[v]) {
				ok = false;
				break;
			}
		}
		if (ok && cur > num[v] + 1) {
			ans = ans * 2 % mod;
		}
		for (int v : tmp) {
			used[v] = 1;
		}
	}

	printf("%d\n", ans);

	return 0;
}