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

const int L = 20;
const int N = 333333;
int sparse[L][N];

int get(int l, int r) {
	int b = 31 - __builtin_clz(r - l);
	return min(sparse[b][l], sparse[b][r - (1 << b)]);
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	for (int i = 0; i < 2 * n; ++i) {
		int x = a[i];
		a.push_back(x);
	}

	for (int i = 0; i < (int)a.size(); ++i) {
		sparse[0][i] = a[i];
	}
	for (int l = 1; l < L; ++l) {
		int len = 1 << l;
		for (int i = 0; i + len <= (int)a.size(); ++i) {
			sparse[l][i] = min(sparse[l - 1][i], sparse[l - 1][i + len / 2]);
		}
	}

	set<int> S;
	vector<pair<int, int>> ar;
	for (int i = 0; i < (int)a.size(); ++i) {
		ar.push_back({-a[i], i});
	}
	sort(all(ar));
	vector<int> next_gr(a.size());
	for (const auto& p : ar) {
		int pos = p.second;
		auto it = S.lower_bound(pos);
		if (it == S.end()) {
			next_gr[pos] = (int)a.size();
		} else {
			next_gr[pos] = *it;
		}
		S.insert(pos);
	}

	vector<int> dp(a.size() + 1);
	dp.back() = (int)a.size();
	for (int i = (int)a.size() - 1; i >= 0; --i) {
		int nx = next_gr[i];
		if (get(i, nx) * 2 >= a[i]) {
			dp[i] = dp[nx];
			continue;
		}
		int l = i + 1, r = nx;
		while (r > l + 1) {
			int m = (l + r) / 2;
			if (get(i, m) * 2 >= a[i]) {
				l = m;
			} else {
				r = m;
			}
		}
		dp[i] = l;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", dp[i] == (int)a.size() ? -1 : dp[i] - i);
	}
	printf("\n");

	return 0;
}