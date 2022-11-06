#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
const int N = 5e4;
const int inf = 0x3f3f3f3f;
const uint unf = 0xffffffff;

int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a % b);
}

struct SQX {
	int n;
	vector<vector<int>> dv;
	vector<uint> a, b;
	vector<int> id, l, r, covertag;
	vector<uint> ansb;
	const int B = 200;
	vector<array<uint, N + 1>> rec;
	SQX(int n) : a(n + 1), b(n + 1), id(n + 2) {
		this->n = n;
		dv.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j += i) {
				dv[j].emplace_back(i);
			}
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			id[i] = i / B;
		}
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		id[0] = -1, id[n + 1] = id[n] + 1;
		l.resize(id[n] + 1, n + 1);
		r.resize(id[n] + 1, 0);
		ansb.resize(id[n] + 1, unf);
		covertag.resize(id[n] + 1, -1);
		for (int i = 1; i <= n; i++) {
			l[id[i]] = min(l[id[i]], i);
			r[id[i]] = max(r[id[i]], i);
		}
		rec.resize(id[n] + 1);
		for (int i = id[1]; i <= id[n]; i++) {
			vector<int> mn(N + 1, inf);
			for (int j = l[i]; j <= r[i]; j++) {
				mn[b[j]] = b[j];
			}
			rec[i].fill(unf);
			for (int j = 1; j <= N; j++) {
				for (int k = j; k <= N; k += j) {
					mn[j] = min(mn[j], mn[k]);
				}
				for (int k = j; k <= N; k += j) {
					if (mn[j] < inf) {
						rec[i][k] = min(rec[i][k], uint(1ll * mn[j] / j * k / j));
					}
				}
			}
		}
		for (int i = 0; i <= id[n]; i++) {
			build(i);
		}
	}
	void build(int bid) {
		ansb[bid] = unf;
		for (int i = l[bid]; i <= r[bid]; i++) {
			uint d = gcd(a[i], b[i]);
			ansb[bid] = min(ansb[bid], a[i] * b[i] / (d * d));
		}
	}
	void cover(int lx, int rx, int x) {
		if (id[lx] == id[rx]) {
			coverb(id[lx], lx, rx, x);
		} else {
			if (lx > l[id[lx]]) {
				coverb(id[lx], lx, r[id[lx]], x);
				lx = r[id[lx]] + 1;
			}
			if (rx < r[id[rx]]) {
				coverb(id[rx], l[id[rx]], rx, x);
				rx = l[id[rx]] - 1;
			}
			for (int i = id[lx]; i <= id[rx]; i++) {
				coverb(i, x);
			}
		}
	}
	void coverb(int bid, int lx, int rx, int x) {
		if (covertag[bid] >= 0) {
			for (int i = l[bid]; i <= r[bid]; i++) {
				a[i] = covertag[bid];
			}
			covertag[bid] = -1;
		}
		for (int i = lx; i <= rx; i++) {
			a[i] = x;
		}
		build(bid);
	}
	uint calc(int loc) {
		uint av = a[loc];
		if (covertag[id[loc]] >= 0) {
			av = covertag[id[loc]];
		}
		uint d = gcd(av, b[loc]);
		return av * b[loc] / (d * d);
	}
	void coverb(int bid, int x) {
		covertag[bid] = x;
		ansb[bid] = rec[bid][x];
	}
	uint query(int lx, int rx) {
		uint ans = unf;
		if (id[lx] == id[rx]) {
			for (int i = lx; i <= rx; i++) {
				ans = min(ans, calc(i));
			}
		} else {
			while (lx != l[id[lx]]) {
				ans = min(ans, calc(lx)), ++lx;
			}
			while (rx != r[id[rx]]) {
				ans = min(ans, calc(rx)), --rx;
			}
			for (int i = id[lx]; i <= id[rx]; i++) {
				ans = min(ans, ansb[i]);
			}
		}
		return ans;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	SQX seq(n);
	for (int i = 1; i <= m; i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1) {
			int x;
			cin >> x;
			seq.cover(l, r, x);
		} else {
			printf("%lld\n", (long long)seq.query(l, r));
		}
	}
    return 0;
}