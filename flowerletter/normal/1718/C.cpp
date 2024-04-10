#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct Seg {
	#define ls u << 1
	#define rs u << 1 | 1
	#define mid (l + r >> 1)
	vector<i64> mx;
	void init(int n) {mx.resize(1 << __lg(n) + 2);}
	void upd(int u, int l, int r, int p, i64 x) {
		if(l == r) return mx[u] = x, void();
		p <= mid ? upd(ls, l, mid, p, x) : upd(rs, mid + 1, r, p, x);
		mx[u] = max(mx[ls], mx[rs]);
	}
	#undef ls
	#undef rs
	#undef mid
};
void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> fact, a(n);
	for(int i = 2, x = n; i <= x; i ++) {
		if(x % i == 0) {
			fact.emplace_back(n / i);
			while(x % i == 0) x/= i;
		}
	}
	for(int i = 0; i < n; i ++) cin >> a[i];
	vector<vector<i64>> w(fact.size());
	Seg all;
	all.init(fact.size());
	vector<Seg> sgt(fact.size());
	for(int c = 0; c < fact.size(); c ++) {
		int g = fact[c];
		w[c].resize(g);
		sgt[c].init(g);
		for(int i = 0; i < n; i ++) {
			w[c][i % g] += a[i];
		}
		for(int i = 0; i < g; i ++) sgt[c].upd(1, 0, g - 1, i, w[c][i]);
		all.upd(1, 0, fact.size() - 1, c, sgt[c].mx[1] * g);
	}
	cout << all.mx[1] << '\n';
	for(int i = 0; i < q; i ++) {
		int p, x;
		cin >> p >> x;
		p --;
		for(int c = 0; c < fact.size(); c ++) {
			int g = fact[c];
			w[c][p % g] += x - a[p];
			i64 lstans = sgt[c].mx[1];
			sgt[c].upd(1, 0, g - 1, p % g, w[c][p % g]);
			if(lstans != sgt[c].mx[1]) 	all.upd(1, 0, fact.size() - 1, c, sgt[c].mx[1] * g);
		}
		a[p] = x;
		cout << all.mx[1] << '\n';
	}
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		solve();
	}
	return 0;
}