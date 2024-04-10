/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
 
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int n, m, opt, x, a[maxn + 5], b[maxn + 5], vis[maxn + 5], u[maxn + 5], v[maxn + 5];
int ans;
vector<int> id[maxn + 5];
inline int add(int a) {return a >= mod ? (a - mod) : a;}
inline void upd(int &a) {a = a >= mod ? (a - mod) : a;}
struct Tag {
	int k0, k1, k2;
	inline friend Tag operator + (Tag x, Tag y) {
		return (Tag) {add(x.k0 + y.k0), add(add(x.k1 + y.k1) + mod - 1ll * y.k0 * x.k2 % mod), add(x.k2 + y.k2)};
	}
}tag[maxn * 36];
struct Node {
	int cnt, sp, isp, ss, iss, sum;
	inline friend Node operator + (Node x, Node y) {
		return (Node) {add(x.cnt + y.cnt), add(x.sp + y.sp), add(x.isp + y.isp), add(x.ss + y.ss), add(x.iss + y.iss), add(x.sum + y.sum)};
	}
	inline friend Node operator + (Node x, Tag y) {
		upd(x.isp += 1ll * y.k0 * x.sp % mod), upd(x.iss += 1ll * y.k0 * x.ss % mod);
		upd(x.sum += add(1ll * y.k1 * x.sp % mod + 1ll * x.isp * y.k2 % mod));
		return x;
	}
}s[maxn * 36];
struct Bit {
	#define lb(x) (x & (-x))
	int c[maxn + 5];
	void add(int x, int k) {
		for(; x <= n; x += lb(x)) c[x] += k;
	}
	int qry(int x) {
		int ans = 0;
		for(; x; x-=lb(x)) ans += c[x];
		return ans;
	}
	#undef lb(x)
}mjy, hlt;
int Nodecnt, son[maxn * 36][2];
struct Segment {
	#define ls son[rt][0]
	#define rs son[rt][1]
	int root;
	void pushup(int rt) {
		s[rt] = s[ls] + s[rs]; 
	}
	void seta(int &rt, Tag k) {
		if(!rt) rt = ++Nodecnt;
		s[rt] = s[rt] + k;
		tag[rt] = tag[rt] + k;
	}
	void pushdown(int rt) {
		seta(ls, tag[rt]), seta(rs, tag[rt]);
		tag[rt] = (Tag) {0, 0, 0};
	}
	void modify(int &rt, int l, int r, int L, int R, Tag k) {
		if(l >= L && r <= R) return seta(rt, k) ,void();
		int mid = l + r >> 1;pushdown(rt);
		if(R <= mid) modify(ls, l, mid, L, R, k);
		else if(L > mid) modify(rs, mid + 1, r, L, R, k);
		else modify(ls, l, mid, L, R, k), modify(rs, mid + 1, r, L, R, k);
		pushup(rt);
	}
	void update(int &rt, int l, int r, int p, Node k) {
		if(l == r) {
			s[rt] = k;
			return ; 
		}
		int mid = l + r >> 1;pushdown(rt);
		if(p <= mid) update(ls, l, mid, p, k);
		else update(rs, mid + 1, r, p, k);
		pushup(rt);
	}
	Node query(int rt, int l, int r, int L, int R) {
		if(l >= L && r <= R) return s[rt];
		int mid = l + r >> 1;pushdown(rt);
		if(R <= mid) return query(ls, l, mid, L, R);
		else if(L > mid) return query(rs, mid + 1, r, L, R);
		else return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
	}
	#undef ls
	#undef rs
}T[maxn + 5];
void insert(int x, int y) {
	upd(ans += mod - T[y].query(T[y].root, 1, n, 1, n).sum);
	int p = (1 <= x - 1) ? T[y].query(T[y].root, 1, n, 1, x - 1).cnt : 0;p++;
	Tag tmp1 = (Tag) {1, 0, 0};
	if(x + 1 <= n) T[y].modify(T[y].root, 1, n, x + 1, n, tmp1);
	Node tmp = (x + 1 <= n) ? T[y].query(T[y].root, 1, n, x + 1, n) : (Node){0, 0, 0, 0, 0, 0};
	Tag tmp2 = (Tag) {0, add(tmp.ss + 1ll * (p - 1) * v[x] % mod), mod - v[x]};
	if(1 <= x - 1) T[y].modify(T[y].root, 1, n, 1, x - 1, tmp2);
	Node tmp3 = (Node) {1, u[x], 1ll * p * u[x] % mod, v[x], 1ll * p * v[x] % mod, add(1ll * u[x] * add(tmp.iss + mod - tmp.ss) % mod + mod - 1ll * p * u[x] % mod * tmp.ss % mod)};
	T[y].update(T[y].root, 1, n, x, tmp3);
	upd(ans += T[y].query(T[y].root, 1, n, 1, n).sum);
}
void erase(int x, int y) {
	upd(ans += mod - T[y].query(T[y].root, 1, n, 1, n).sum);
	int p = (1 <= x - 1) ? T[y].query(T[y].root, 1, n, 1, x - 1).cnt : 0;p++;
	Tag tmp1 = (Tag) {mod - 1, 0, 0};	
	Node tmp = (x + 1 <= n) ? T[y].query(T[y].root, 1, n, x + 1, n) : (Node){0, 0, 0, 0, 0, 0};
	if(x + 1 <= n) T[y].modify(T[y].root, 1, n, x + 1, n, tmp1);
	Tag tmp2 = (Tag) {0, add(mod - tmp.ss + mod - 1ll * (p - 1) * v[x] % mod), v[x]};
	if(1 <= x - 1) T[y].modify(T[y].root, 1, n, 1, x - 1, tmp2);
	Node tmp3 = {0, 0, 0, 0, 0 ,0};
	T[y].update(T[y].root, 1, n, x, tmp3);
	upd(ans += T[y].query(T[y].root, 1, n, 1, n).sum);
}
int main() {
//	freopen("in.txt", "r", stdin);	
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i], vis[i] = 1, T[i].root = ++Nodecnt;
	sort(b + 1, b + n + 1);
	int *end = unique(b + 1, b + n + 1);
	rep(i, 1, n) a[i] = lower_bound(b + 1, end, a[i]) - b, id[a[i]].push_back(i);
	rep(i, 1, n) u[i] = mjy.qry(a[i]), mjy.add(a[i], 1);
	per(i, n, 1) v[i] = hlt.qry(a[i]), hlt.add(a[i], 1);
	rep(i, 1, n) for(auto u : id[i]) insert(u, i);
	scanf("%d", &m);
	rep(i, 1, m) {
		scanf("%d%d", &opt, &x);
		if(opt == 1 && vis[x]) erase(x, a[x]), vis[x] = 0;
		if(opt == 2 && !vis[x]) insert(x, a[x]), vis[x] = 1;
		printf("%d\n", ans);
	}
	return 0;
}