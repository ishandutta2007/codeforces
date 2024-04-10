#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int maxn = 4e5;
const int mod = 1e9 + 7;
int n, q, x, ans, rev[maxn + 5], f[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) > 0 ? a + mod : a;}
struct Range {
	int l, r, ok;
}a[maxn + 5];
struct Bit {
	int c[maxn + 5];
	void upd(int x, int k) {
		for(; x <= 2 * n; x += lb(x)) c[x] = add(c[x], k);
	}
	int qry(int x, int ans = 0) {
		for(; x; x -= lb(x)) ans = add(ans, c[x]);
		return ans;
	}
}s, t;
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i, 1, n) cin >> a[i].l >> a[i].r;
	cin >> q;
	rep(i, 1, q) {
		cin >> x;
		a[x].ok = 1;
	}
	sort(a + 1, a + n + 1, [&] (Range x, Range y) {return x.l < y.l;});
	int res = 0;
	per(i, n, 1) {
		f[i] = s.qry(a[i].r) + 1;
		s.upd(a[i].r, f[i]);
		if(t.qry(a[i].r) < res || a[i].ok) ans = add(ans, f[i]);
		if(a[i].ok) t.upd(a[i].r, 1), res ++;
	}
	cout << ans << '\n';
	return 0;
}