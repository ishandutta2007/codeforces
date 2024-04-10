#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int K = 19;
const int N = 1 << K;
int ans[N];

struct Node {
	int mn, mx, df;
} def = {-1, -1, -1};

ostream& operator <<(ostream& ostr, const Node& nd) {
	return ostr << "(mn=" << nd.mn << ", mx=" << nd.mx << ", df=" << nd.df << ")";
}

Node tree[K][N];

void relax(int& x, int y) {
	if (x == -1 || (y > -1 && y < x)) {
		x = y;
	}
}

Node merge(const Node& a, const Node& b) {
	int df = -1;
	if (a.mx > -1 && b.mn > -1) {
		relax(df, b.mn - a.mx);
	}
	if (a.df > -1) {
		relax(df, a.df);
	}
	if (b.df > -1) {
		relax(df, b.df);
	}
	return {
		a.mn > -1 ? a.mn : b.mn,
		b.mx > -1 ? b.mx : a.mx,
		df
	};
}

int big;

void fill_ans(int v, int cur, int when) {
	if (cur < when) {
		const int ll = (1 << when);
		for (int mask = 0; mask < ll; ++mask) {
			Node res = def;
			for (int i = 0; i < big; ++i) {
				int off = ((v >> when) ^ i);
				auto tmp = tree[when][(off << when) | mask];
				if (tmp.mn > -1) {
					tmp.mn ^= v;
				}
				if (tmp.mx > -1) {
					tmp.mx ^= v;
				}
				// if ((v | mask) == 0) cerr << tmp << " ";
				res = merge(res, tmp);
			}
			// if ((v | mask) == 0) cerr << (v | mask) << ": " << res << "\n";
			ans[v | mask] = res.df;
		}
		return;
	}
	fill_ans(v, cur - 1, when);
	fill_ans(v | (1 << cur), cur - 1, when);
}

void solve() {
	int n = nxt(), k = nxt();
	vector<int> a(n);
	generate(all(a), nxt);

	if (k == 1) {
		cout << "1 1\n";
		return;
	}

	const int kk = 1 << k;
	const int sm = k - 1;

	fill(tree[0], tree[0] + kk, def);
	for (int x : a) {
		tree[0][x] = {x, x, -1};
	}
	for (int l = 1; l <= sm; ++l) {
		const int ll = 1 << l;
		const int lll = ll >> 1;
		fill(tree[l], tree[l] + kk, def);
		for (int i = 0; i < kk; i += ll) {
			for (int mask = 0; mask < ll; ++mask) {
				if (mask & lll) {
					auto le = tree[l - 1][i + lll + (mask ^ lll)];
					auto ri = tree[l - 1][i + (mask ^ lll)];
					if (le.mn > -1) {
						le.mn ^= lll;
					}
					if (ri.mn > -1) {
						ri.mn ^= lll;
					}
					if (le.mx > -1) {
						le.mx ^= lll;
					}
					if (ri.mx > -1) {
						ri.mx ^= lll;
					}
					tree[l][i + mask] = merge(le, ri);
				} else {
					auto ri = tree[l - 1][i + lll + mask];
					auto le = tree[l - 1][i + mask];
					tree[l][i + mask] = merge(le, ri);
				}
				// cerr << "tree[" << l << "][" << i + mask << "] = " << tree[l][i + mask] << "\n";
			}
		}
	}
	big = 1 << (k - sm);
	fill_ans(0, k - 1, sm);

	for (int i = 0; i < (1 << (k - 1)); ++i) {
		cout << ans[i] << " ";
	}
	for (int i = (1 << (k - 1)) - 1; i >= 0; --i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}