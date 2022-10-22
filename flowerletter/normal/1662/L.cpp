#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
const int maxn = 2e5;
const int mxlg = 20;
int n, v, id[maxn + 5];
ll t[maxn + 5], a[maxn + 5], x[maxn + 5], y[maxn + 5], f[maxn + 5];
vector<ll> sx, sy;
struct Bit {
	ll n, c[maxn + 5];
	ll *stk[maxn * mxlg + 5], w[maxn * mxlg + 5], tp;
	void upd(int x, int k) {
		x ++;
		for(; x <= n; x += lb(x)) if(c[x] < k) {
			stk[++ tp] = &c[x], w[tp] = c[x];
			c[x] = k;
		}
	}
	ll qry(int x) {
		x ++;
		ll ans = -1e9;
		for(; x; x -= lb(x)) chkmx(ans, c[x]);
		return ans;
	}
	void clear() {
		per(i, tp, 1) *stk[i] = w[i];
		tp = 0;
	}
	void init(int _n) {
		n = _n;
		fill(c + 1, c + n + 1, -1e9);
	}
}ds;
void solve(int l, int r) {
	if(l == r) return ;
	int mid = l + r >> 1;
	solve(l, mid);
	sort(id + l, id + mid + 1, [&] (int a, int b) {return x[a] < x[b];});
	sort(id + mid + 1, id + r + 1, [&] (int a, int b) {return x[a] < x[b];});
//	cout << l << ' ' << r << "------------\n";
//	rep(i, l, mid) cout << id[i] << ' '; cout << '\n';
//	rep(i, mid + 1, r) cout << id[i] << ' '; cout << '\n';
	int i = l, j = mid + 1;
	for(; j <= r; j ++) {
		while(i <= mid && x[id[i]] <= x[id[j]]) ds.upd(y[id[i]], f[id[i]]), i ++;
		chkmx(f[id[j]], ds.qry(y[id[j]]) + 1);
//		cout << j << ' '<< i << '\n';
//		rep(k, l, i - 1) if(y[id[k]] <= y[id[j]]) chkmx(f[id[j]], f[id[k]] + 1);
	}
	ds.clear();
	iota(id + mid + 1, id + r + 1, mid + 1);
	solve(mid + 1, r);
}
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> v;
	rep(i, 1, n) cin >> t[i];
	rep(i, 1, n) cin >> a[i];
	rep(i, 0, n) {
		sx.pb(x[i] = v * t[i] - a[i]);
		sy.pb(y[i] = v * t[i] + a[i]);
	}
	sort(all(sx)), sort(all(sy));
	rep(i, 0, n) {
		x[i] = lower_bound(all(sx), x[i]) - sx.begin();
		y[i] = lower_bound(all(sy), y[i]) - sy.begin();
	}
	ds.init(n + 1);
	iota(id, id + n + 1, 0);
	fill(f + 1, f + n + 1, -1e9);
	solve(0, n);
	cout << *max_element(f, f + n + 1) << '\n';
	return 0;
}