#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5 + 10;
constexpr double eps = 1e-10;
int n, a, b, x[N], y[N];
double limit[N], k[N], f[N];
struct SGT {
	#define ls u << 1
	#define rs u << 1 | 1
	pair<double, int> mn[N << 2];
	double tag[N << 2];
	void up(int u) {mn[u] = min(mn[ls], mn[rs]);}
	void seta(int u, double k) {mn[u].first += k, tag[u] += k;}
	void dw(int u) {
		seta(ls, tag[u]), seta(rs, tag[u]);
		tag[u] = 0;
	}
	void build(int u, int l, int r) {
		tag[u] = 0;
		if(l == r) {
			mn[u] = {0.0, l};
			return ;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		up(u);
	}
	void add(int u, int l, int r, int ql, int qr, double k) {
		if(l >= ql && r <= qr) return seta(u, k);
		int mid = l + r >> 1; dw(u);
		if(qr <= mid) add(ls, l, mid, ql, qr, k);
		else if(ql > mid) add(rs, mid + 1, r, ql, qr, k);
		else add(ls, l, mid, ql, qr, k), add(rs, mid + 1, r, ql, qr, k);
		up(u);
	}
	pair<double, int> qry(int u, int l, int r, int ql, int qr) {
		if(l >= ql && r <= qr) return mn[u];
		int mid = l + r >> 1; dw(u);
		if(qr <= mid) return qry(ls, l, mid, ql, qr);
		else if(ql > mid) return qry(rs, mid + 1, r, ql, qr);
		else return min(qry(ls, l, mid, ql, qr), qry(rs, mid + 1, r, ql, qr));
	}
}t1, t2;
void solve() {
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i ++) cin >> x[i];
	for(int i = 1; i <= n; i ++) cin >> y[i];
	f[0] = a;
	t1.build(1, 1, n), t2.build(1, 1, n);
	cout << fixed << setprecision(10);
	for(int i = 1; i <= n; i ++) {
		k[i] = 1.0 * x[i] / y[i];
		t1.add(1, 1, n, i, i, f[i - 1]);
		t2.add(1, 1, n, i, i, k[i]);
		limit[i] = 0;
		f[i] = f[i - 1];
		if(b > eps) {
			double cur = min(b, y[i]);
			b -= cur;
			limit[i] += cur / y[i];
			f[i] += cur / y[i] * x[i];
			t1.add(1, 1, n, i, i, cur / y[i] * x[i]);
		}
		while(1) {
			pair<double, int> mn = t2.qry(1, 1, n, 1, i);
			if(mn.first >= k[i] || mn.second == i) break;
			int q = mn.second;
			double cur = min({t1.qry(1, 1, n, q, i).first / x[q] * y[q], (limit[q] + 1) * y[q], (1 - limit[i]) * y[i]});
			f[i] += cur / y[i] * x[i] - cur / y[q] * x[q];
			t1.add(1, 1, n, q, i, -cur / y[q] * x[q]);
			t1.add(1, 1, n, i, i, cur / y[i] * x[i]);
			limit[q] -= cur / y[q];
			limit[i] += cur / y[i];
			if(limit[i] > 1 - eps) break;
			t2.add(1, 1, n, q, q, 1e18);
		}
		cout << f[i] << '\n';
	}
}
int main() {
// 	freopen("in.txt", "r", stdin);
// 	freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		solve();
	}
	return 0;
}