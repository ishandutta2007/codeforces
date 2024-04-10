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

const int L = 30;

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<vector<int>> nx(n, vector<int>(L, 0));
	vector<vector<int>> pr(n, vector<int>(L, 0));
	vector<int> glpr(n);

	map<int, int> lst;
	for (int i = 0; i < n; ++i) {
		if (lst.count(a[i])) {
			glpr[i] = lst[a[i]];
		} else {
			glpr[i] = -1;
		}
		lst[a[i]] = i;
	}

	map<int, int> M;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			if (M.count(j)) {
				pr[i][j] = M[j];
			} else {
				pr[i][j] = -1;
			}
			if (a[i] & (1 << j)) {
				M[j] = i;
			}
		}
	}

	M.clear();
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < L; ++j) {
			if (M.count(j)) {
				nx[i][j] = M[j];
			} else {
				nx[i][j] = n;
			}
			if (a[i] & (1 << j)) {
				M[j] = i;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int l = glpr[i], r = n;
		for (int j = 0; j < L; ++j) {
			if (a[i] & (1 << j)) {
				continue;
			}
			l = max(l, pr[i][j]);
			r = min(r, nx[i][j]);
		}
		long long tmp = 1ll * (i - l) * (r - i) - 1;
		ans += tmp;
	}

	cout << 1ll * n * (n - 1) / 2 - ans << "\n";

	return 0;
}