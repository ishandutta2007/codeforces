#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, ll> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e6;
const int maxm = 1 << 21;
int n, q, a[maxn + 5], l_[maxn + 5], r_[maxn + 5], tp[maxn + 5];
ll ans[maxn + 5];
struct Fuck {
	int l, r, v, id;
	bool c, t;
};
vector<Fuck> qry[maxn + 5];
struct Segment {
	#define ls u << 1
	#define rs u << 1 | 1
	int cnt[maxm + 5];
	ll sum[maxm + 5];
	void update(int u, int l, int r, int p, int k1, ll k2) {
		sum[u] += k2, cnt[u] += k1;
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) update(ls, l, mid, p, k1, k2);
		else update(rs, mid + 1, r, p, k1, k2);
	}
	ll query(int u, int l, int r, int ql, int qr, int c) {
		if(l >= ql && r <= qr) return c ? sum[u] : cnt[u];
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls, l, mid, ql, qr, c);
		else if(ql > mid) return query(rs, mid + 1, r, ql, qr, c);
		else return query(ls, l, mid, ql, qr, c) + query(rs, mid + 1, r, ql, qr, c);
	}
}ds[2];
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), q = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, q) l_[i] = read(), tp[l_[i] - 1] += 4;
	rep(i, 1, q) r_[i] = read(), tp[r_[i]] += 4;
	rep(i, 0, n) qry[i].resize(tp[i]), tp[i] = 0;
	rep(i, 1, q) {
		int l = l_[i], r = r_[i];
		qry[l - 1][tp[l - 1] ++] = {l, r, 1, i, 0, 1};
		qry[l - 1][tp[l - 1] ++] = {l, r, -1, i, 1, 1};
		qry[l - 1][tp[l - 1] ++] = {0, l - 1, l, i, 0, 0};
		qry[l - 1][tp[l - 1] ++] = {r + 1, n + 1, -r, i, 1, 0};
		qry[r][tp[r] ++] = {l, r, -1, i, 0, 1};
		qry[r][tp[r] ++] = {l, r, 1, i, 1, 1};
		qry[r][tp[r] ++] = {0, l - 1, -l, i, 0, 0};
		qry[r][tp[r] ++] = {r + 1, n + 1, r, i, 1, 0};
		ans[i] = r - l + 1;
	}
	rep(i, 1, n) {
		static int s[maxn + 5], tp = 0;
		while(tp && a[s[tp]] < a[i]) r_[s[tp]] = i, tp --;
		if(tp) l_[i] = s[tp];
		else l_[i] = 0;
		s[++ tp] = i; 
		if(i == n) {
			while(tp) r_[s[tp]] = n + 1, tp --;
		}
	}
	rep(i, 1, n) {
		int l = l_[i] + 1, r = r_[i] - 1;
		ds[0].update(1, 0, n + 1, l, 1, l); 
		ds[1].update(1, 0, n + 1, r, 1, r);
		rep(j, 0, tp[i] - 1) {
			Fuck x = qry[i][j];
			ans[x.id] += 1ll * x.v * ds[x.c].query(1, 0, n + 1, x.l, x.r, x.t);
		}
	}
	rep(i, 1, q) cout << ans[i] << ' ';
	return 0;
}