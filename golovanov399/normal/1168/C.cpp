#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int L = 20;

struct Query {
	int id;
	int l, r;

	bool operator <(const Query& ot) const {
		return l < ot.l;
	}
};

int dp[L][L];
const int N = 333333;
int nx[N][L];
int pr[N][L];

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), q = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			nx[i][j] = n;
			pr[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			if (a[i] & (1 << j)) {
				pr[i][j] = i;
			} else {
				pr[i][j] = i ? pr[i - 1][j] : -1;
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < L; ++j) {
			if (a[i] & (1 << j)) {
				nx[i][j] = i;
			} else {
				nx[i][j] = i < n - 1 ? nx[i + 1][j] : n;
			}
		}
	}

	vector<Query> qrs(q);
	for (int i = 0; i < q; ++i) {
		qrs[i].id = i;
		qrs[i].l = nxt() - 1;
		qrs[i].r = nxt() - 1;
	}

	sort(all(qrs));
	vector<char> ans(q);

	vector<int> mask_right(n), mask_left(n);
	for (int i = 0; i < n; ++i) {
		mask_left[i] = mask_right[i] = a[i];
	}
	for (int len = 1; len < n; len *= 2) {
		for (const auto& q : qrs) {
			int ql = q.l / len, qr = q.r / len;
			if (ql + 1 == qr && ql % 2 == 0) {
				ans[q.id] = !!(mask_right[q.l] & mask_left[q.r]);
			}
		}

		for (int start = 0; start + len < n; start += 2 * len) {
			for (int i = start; i < start + len && i < n; ++i) {
				int newmask = mask_right[i];
				for (int j = 0; j < L; ++j) {
					if (!(mask_right[i] & (1 << j))) {
						continue;
					}
					int pos = nx[start + len][j];
					if (pos < start + 2 * len && pos < n) {
						newmask |= mask_right[pos];
					}
				}
				mask_right[i] = newmask;
			}

			for (int i = start + len; i < start + 2 * len && i < n; ++i) {
				int newmask = mask_left[i];
				for (int j = 0; j < L; ++j) {
					if (!(mask_left[i] & (1 << j))) {
						continue;
					}
					int pos = pr[start + len - 1][j];
					if (pos >= start) {
						newmask |= mask_left[pos];
					}
				}
				mask_left[i] = newmask;
			}
		}
	}

	cout.sync_with_stdio(0);
	for (auto c : ans) {
		cout << (c ? "Shi" : "Fou") << "\n";
	}

	return 0;
}