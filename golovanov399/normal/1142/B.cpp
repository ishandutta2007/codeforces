#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

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
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(), q = nxt();
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[nxt() - 1] = i;
	}
	vector<int> a(m);
	for (int i = 0; i < m; ++i) {
		a[i] = p[nxt() - 1];
	}

	vector<vector<int>> ptr(1, vector<int>(m));

	vector<int> last(n, -1);
	for (int i = m - 1; i >= 0; --i) {
		int nx = (a[i] + 1) % n;
		ptr[0][i] = last[nx];
		last[a[i]] = i;
	}

	for (int t = 0;; ++t) {
		ptr.emplace_back(m, -1);
		bool changed = false;
		for (int i = 0; i < m; ++i) {
			if (ptr[t][i] == -1 || ptr[t][ptr[t][i]] == -1) {
				continue;
			}
			ptr[t + 1][i] = ptr[t][ptr[t][i]];
			changed = true;
		}
		if (!changed) {
			break;
		}
	}

	vector<vector<int>> sparse(1, vector<int>(m, m));

	for (int i = 0; i < m; ++i) {
		int cur = i;
		for (int j = 0; cur > -1 && (1 << j) < n; ++j) {
			if (j >= (int)ptr.size()) {
				cur = -1;
				break;
			}
			if ((n - 1) & (1 << j)) {
				cur = ptr[j][cur];
			}
		}
		if (cur == -1) {
			continue;
		}
		sparse[0][i] = cur;
	}

	for (int i = 0; (2 << i) <= m; ++i) {
		sparse.push_back({});
		for (int j = 0; j + (2 << i) <= m; ++j) {
			sparse.back().push_back(min(sparse[i][j], sparse[i][j + (1 << i)]));
		}
	}

	auto get = [&](int l, int r) {
		int d = 31 - __builtin_clz(r - l);
		// cerr << l << " " << r << " " << (1 << d) << "\n";
		return min(sparse[d][l], sparse[d][r - (1 << d)]);
	};

	string ans(q, '0');
	for (int i = 0; i < q; ++i) {
		int l = nxt() - 1, r = nxt();
		// cerr << l << " " << r << " " << get(l, r) << "\n";
		if (get(l, r) < r) {
			ans[i] = '1';
		}
	}

	puts(ans.c_str());

	return 0;
}