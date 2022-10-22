/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5;
const int inf = 1e9;
int xmx, ymx, zmx, n, m, k, x, y, z, ans[maxn + 5];
int xl, xr, yl, yr, zl, zr;
struct Node {int type, x, y, z;};
vector<Node> s[8], add[maxn + 5], qry[maxn + 5];
inline int type(int x, int mx, int l, int r) {
	if(x < l) return 0;
	else if(mx - x + 1 < r) return 1;
	else return 2;
}
struct Seg {
	#define ls rt << 1
	#define rs rt << 1 | 1
	int mx[maxn * 4 + 5];
	void build(int rt, int l, int r) {
		mx[rt] = 0;
		if(l == r) return ;
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	void update(int rt, int l, int r, int p, int k) {
		if(l == r) return chkmx(mx[rt], k), void();
		int mid = l + r >> 1;
		if(p <= mid) update(ls, l, mid, p, k);
		else update(rs, mid + 1, r, p, k);
		mx[rt] = max(mx[ls], mx[rs]);
	}
	int query(int rt, int l, int r, int ql, int qr) {
		if(l >= ql && r <= qr) return mx[rt];
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
		else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
	}
}t;
void solve(vector<Node> s, int limx, int limy, int limz) {
	rep(i, 1, limx) qry[i].clear(), add[i]. clear();
	for(auto &a : s) chkmn(a.x, limx), chkmn(a.y, limy), chkmn(a.z, limz);
	for(auto a : s) if(a.type) qry[a.x].push_back(a); else add[a.x].push_back(a);
	t.build(1, 1, limy);
	per(i, limx, 1) {
		for(auto a : add[i]) t.update(1, 1, limy, a.y, a.z);
		for(auto a : qry[i]) ans[a.type] |= t.query(1, 1, limy, a.y, limy) >= a.z;
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d%d%d%d%d", &xmx, &ymx, &zmx, &n, &m, &k);
	xl = yl = zl = xr = yr = zr = inf;
	rep(i, 1, n) {
		scanf("%d%d%d", &x, &y, &z);
		chkmn(xl, x), chkmn(xr, xmx - x + 1);
		chkmn(yl, y), chkmn(yr, ymx - y + 1);
		chkmn(zl, z), chkmn(zr, zmx - z + 1);
	}
	rep(i, 1, m) {
		scanf("%d%d%d", &x, &y, &z);
		int fx = type(x, xmx, xl, xr), fy = type(y, ymx, yl, yr), fz = type(z, zmx, zl, zr); 
		rep(a, 0, 1) rep(b, 0, 1) rep(c, 0, 1) {
			if((a == fx || fx == 2) && (b == fy || fy == 2) && (c == fz || fz == 2)) {
				s[a + (b << 1) + (c << 2)].push_back((Node){0, a ? xmx - x + 1 : x, b ? ymx - y + 1 : y, c ? zmx - z + 1 : z});
			}
		}
		if(fx == 2 && fy == 2 && fz == 2) return puts("INCORRECT"), 0;
	}
	puts("CORRECT");
	rep(i, 1, k) {
		scanf("%d%d%d", &x, &y, &z);
		int fx = type(x, xmx, xl, xr), fy = type(y, ymx, yl, yr), fz = type(z, zmx, zl, zr); 
		if(fx == 2 && fy == 2 && fz == 2) ans[i] = -1;
		else {
			if(fx == 2) fx = 0;
			if(fy == 2) fy = 0;
			if(fz == 2) fz = 0;
 			s[fx + (fy << 1) + (fz << 2)].push_back((Node){i, fx ? xmx - x + 1 : x, fy ? ymx - y + 1 : y, fz ? zmx - z + 1 : z});
		}
	} 
	rep(i, 0, 7) solve(s[i], (i & 1) ? xr : xl, (i >> 1 & 1) ? yr : yl, (i >> 2 & 1) ? zr : zl);
	rep(i, 1, k) puts(ans[i] == -1 ? "OPEN" : (ans[i] ? "CLOSED" : "UNKNOWN"));
	return 0;
}