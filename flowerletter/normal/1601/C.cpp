#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 2e6;
const int lg = 20;
const int inf = 1e9;
int T, n, m, lim, rt[maxn + 5], a[maxn + 5], b[maxn + 5];
ll ans;
struct ChairamnTree {
	int nodecnt, ls[maxn * lg], rs[maxn * lg], cnt[maxn * lg];
	void update(int &u, int v, int l, int r, int p) {
		cnt[u = ++nodecnt] = cnt[v] + 1;
		ls[u] = ls[v], rs[u] = rs[v];
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) update(ls[u], ls[v], l, mid, p);
		else update(rs[u], rs[v], mid + 1, r, p);
	}
	int query(int u, int l, int r, int ql, int qr) {
		if(!u) return 0;
		if(l >= ql && r <= qr) return cnt[u];
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls[u], l, mid, ql, qr);
		else if(ql > mid) return query(rs[u], mid + 1, r, ql, qr);
		else return query(ls[u], l, mid, ql, qr) + query(rs[u], mid + 1, r, ql, qr);
	}
	void clear() {
		nodecnt = 0;
	}
}t;
void solve(int l, int r, int ql, int qr) {
	if(l > r) return ;
	static int mem[maxn + 5], *pre = mem + 1, suf[maxn + 5];
	int mid = l + r >> 1;
	pre[ql - 1] = suf[qr + 1] = 0;
	if(b[mid] + 1 <= lim) pre[ql - 1] = t.query(rt[ql - 1], 1, lim, b[mid] + 1, lim);
	if(1 <= b[mid] - 1) suf[qr + 1] = t.query(rt[n], 1, lim, 1, b[mid] - 1) - t.query(rt[qr], 1, lim, 1, b[mid] - 1);
	rep(i, ql, qr) pre[i] = pre[i - 1] + (a[i] > b[mid]);
	per(i, qr, ql) suf[i] = suf[i + 1] + (b[mid] > a[i]);
	int res = inf, p = ql;
	rep(i, ql, qr) if(chkmn(res, pre[i] + suf[i + 1])) p = i;
	ans += res;
	solve(l, mid - 1, ql, p), solve(mid + 1, r, p, qr);
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(T = read(); T; T --) {
		vector<int> st; ans = 0; t.clear();
		n = read(), m = read();
		rep(i, 1, n) a[i] = read(), st.push_back(a[i]);
		rep(i, 1, m) b[i] = read(), st.push_back(b[i]);
		sort(b + 1, b + m + 1);
		sort(all(st)), st.erase(unique(all(st)), st.end()); lim = sz(st);
		rep(i, 1, n) a[i] = lower_bound(all(st), a[i]) - st.begin() + 1;
		rep(i, 1, m) b[i] = lower_bound(all(st), b[i]) - st.begin() + 1;
		rep(i, 1, n) t.update(rt[i], rt[i - 1], 1, lim, a[i]), ans += (a[i] < lim ? t.query(rt[i], 1, lim, a[i] + 1, lim) : 0);
		solve(1, m, 0, n);
		cout << ans << '\n';
	}
	return 0;
}