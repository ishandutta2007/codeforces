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
const int maxn = 1e5;
int n, q;
ll a[maxn + 5], b[maxn + 5];
array<ll, 2> operator + (array<ll, 2> a, array<ll, 2> b) {
	return (array<ll, 2>) {min(a[0], b[0]), max(a[1], b[1])};
}
struct Seg {
	#define ls rt << 1
	#define rs rt << 1 | 1
	array<ll, 2> s[maxn * 4 + 5];
	inline void pushup(int rt) {
		s[rt] = s[ls] + s[rs];
	}
	void build(int rt, int l, int r) {
		if(l == r) {
			s[rt] = (array<ll, 2>) {b[l],  b[l]};
			return ;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		pushup(rt);
	}
	array<ll, 2> query(int rt, int l, int r, int ql, int qr) {
		if(l >= ql && r <= qr) return s[rt];
		int mid = l + r >> 1;
		if(qr <= mid) return query(ls, l, mid, ql, qr);
		else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
		else return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
	}
}t;
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> q;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i], a[i] -= b[i];
	rep(i, 1, n) b[i] = b[i - 1] + a[i];
	t.build(1, 1, n);
	rep(i, 1, q) {
		int l, r;
		cin >> l >> r;
		array<ll, 2> x = t.query(1, 1, n, l, r);
		if(x[1] > b[l - 1] || b[r] != b[l - 1]) puts("-1");
		else cout << b[l - 1] - x[0] << '\n';
	}
	return 0;
}