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
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 2e5;
const int inf = 1e9;
int T, n, a[maxn + 5], p[maxn + 5];
namespace Segment {
	#define ls rt << 1
	#define rs rt << 1 | 1
	int mx[maxn * 4 + 5], sum[maxn * 4 + 5], tag[maxn * 4 + 5];
	void pushup(int rt) {mx[rt] = max(mx[ls], mx[rs]), sum[rt] = sum[ls] + sum[rs];}
	void seta(int rt, int k) {mx[rt] += k, tag[rt] += k;}
	void pushdown(int rt) {
		if(tag[rt]) {
			seta(ls, tag[rt]), seta(rs, tag[rt]);
			tag[rt] = 0;
		}
	}
	void build(int rt, int l, int r) {
		tag[rt] = sum[rt] = 0;
		if(l == r) return mx[rt] = -inf + l + (l & 1), void();
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(rt);
	}
	void update(int rt, int l, int r, int p) {
		if(l == r) return mx[rt] += inf, sum[rt] = 1, void();
		int mid = l + r >> 1; pushdown(rt);
		if(p <= mid) update(ls, l, mid, p);
		else update(rs, mid + 1, r, p);
		pushup(rt);
	}
	void add(int rt, int l, int r, int ql, int qr, int k) {
		if(l >= ql && r <= qr) return seta(rt, k), void();
		int mid = l + r >> 1; pushdown(rt);
		if(qr <= mid) add(ls, l, mid, ql, qr, k);
		else if(ql > mid) add(rs, mid + 1, r, ql, qr, k);
		else add(ls, l, mid, ql, qr, k), add(rs, mid + 1, r, ql, qr, k);
		pushup(rt);
	}
	int fnd(int rt, int l, int r) {
		if(l == r) return l - (sum[rt] == 0);
		int mid = l + r >> 1;
		if(sum[ls] == mid - l + 1) return fnd(rs, mid + 1, r);
		else return fnd(ls, l, mid); 
	}
}
using Segment::build;
using Segment::update;
using Segment::add;
using Segment::fnd;
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T--) {
		int ans = 0;
		cin >> n;
		rep(i, 1, n) cin >> a[i], p[a[i]] = i;
		build(1, 1, n);
		int lst = 0;
		rep(i, 1, n) {
			update(1, 1, n, p[i]);
			if(p[i] > 1) add(1, 1, n, 1, p[i] - 1, 2);
			int nw = fnd(1, 1, n);
			if(lst != nw) add(1, 1, n, lst + 1, nw, -inf);
			lst = nw;
			chkmx(ans, Segment::mx[1] - i);
		}
		cout << ans << '\n';
	}
	return 0;
}