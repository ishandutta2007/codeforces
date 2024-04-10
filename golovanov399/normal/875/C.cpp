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
	int n = nxt(), m = nxt();
	vector<vector<int>> a(n);
	int maxlen = 0;
	for (int i = 0; i < n; ++i) {
		int k = nxt();
		maxlen = max(maxlen, k);
		a[i].resize(k);
		for (int& x : a[i]) {
			x = nxt() - 1;
		}
	}

	vector<vector<int>> impl(m);
	vector<char> nec(m);
	vector<char> forb(m);

	vector<char> eq_to_nx(n - 1, 1);

	vector<vector<int>> ids(maxlen);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)a[i].size(); ++j) {
			ids[j].push_back(i);
		}
	}

	for (int j = 0; j < maxlen; ++j) {
		for (int i : ids[j]) {
			if (i == n - 1) {
				continue;
			}

			if (!eq_to_nx[i]) {
				continue;
			}
			if (a[i + 1].size() <= j) {
				puts("No");
				return 0;
			}
			if (a[i][j] < a[i + 1][j]) {
				impl[a[i + 1][j]].push_back(a[i][j]);
				eq_to_nx[i] = 0;
			} else if (a[i][j] == a[i + 1][j]) {
				impl[a[i + 1][j]].push_back(a[i][j]);
			} else {
				nec[a[i][j]] = 1;
				forb[a[i + 1][j]] = 1;
				eq_to_nx[i] = 0;
			}
		}
	}

	vector<int> st;
	for (int i = 0; i < m; ++i) {
		if (nec[i]) {
			st.push_back(i);
		}
		make_unique(impl[i]);
	}

	while (!st.empty()) {
		int v = st.back();
		st.pop_back();
		for (int x : impl[v]) {
			if (!nec[x]) {
				nec[x] = 1;
				st.push_back(x);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; ++i) {
		if (nec[i] && forb[i]) {
			puts("No");
			return 0;
		}
		if (nec[i]) {
			cnt += 1;
		}
	}

	puts("Yes");
	printf("%d\n", cnt);
	for (int i = 0; i < m; ++i) {
		if (nec[i]) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");

	return 0;
}