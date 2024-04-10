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
const int maxn = 4e5;
const int mod = 998244353;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
int T, n, m, k, x[maxn + 5], y[maxn + 5], root, vis[maxn + 5];
int fac[maxn + 5], inv[maxn + 5];
vector<int> s;
struct Treap {
	int nodecnt = 0, ls[maxn + 5], rs[maxn + 5], size[maxn + 5], val[maxn + 5], rnd[maxn + 5];
	int tp = 0, recycle[maxn + 5];
	void pushup(int u) {size[u] = size[ls[u]] + size[rs[u]] + 1;}
	int newnode(int x) {
		int nw;
		size[nw = (tp ? recycle[tp--]: ++nodecnt)] = 1, val[nw] = x, rnd[nw] = rand();
		return nw;
	}
	int merge(int u, int v) {
		if(!u || !v) return u | v;
		if(rnd[u] < rnd[v]) {
			rs[u] = merge(rs[u], v), pushup(u);
			return u;
		}
		else {
			ls[v] = merge(u, ls[v]), pushup(v);
			return v;
		}
	}
	void split1(int u, int &x, int &y, int k) {
		if(!u) return x = y = 0, void();
		if(size[ls[u]] < k) x = u, split1(rs[u], rs[x], y, k - size[ls[u]] - 1);
		else y = u, split1(ls[u], x, ls[y], k);
		pushup(u);
	}
}t;
void insert(int p, int x) {
	int a, b;
	t.split1(root, a, b, p - 1);
	root = t.merge(t.merge(a, t.newnode(x)), b);
}
void erase(int p) {
	int a, b, c;
	t.split1(root, a, b, p - 1);
	t.split1(b, b, c, 1);
	root = t.merge(a, c);
	if(t.tp <= maxn) t.recycle[++t.tp] = b;
}
int kth(int p, int x) {
	int a, b, c, ans;
	t.split1(root, a, b, p - 1);
	t.split1(b, b, c, 1);
	ans = t.val[b];
	root = t.merge(t.merge(t.merge(a, t.newnode(x)), b), c);
	return ans;
}
void init() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
	rep(i, 2, maxn) inv[i] = mul(inv[mod % i], mod - mod / i);
	rep(i, 2, maxn) inv[i] = mul(inv[i], inv[i - 1]);
}
int c(int n, int m) {
	return mul(mul(fac[n], inv[m]), inv[n - m]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	init();
	rep(i, 1, 2e5) insert(i, i);
	for(cin >> T; T; T--) {
		cin >> n >> m; k = n - 1, s.clear();
		rep(i, 1, m) {
			cin >> x[i] >> y[i];
			erase(x[i]);
			int tmp = kth(y[i], x[i]);
			if(!vis[tmp]) vis[tmp] = 1, k --, s.push_back(tmp);
		}
		cout << c(k + n, n) << '\n';
		for(auto x : s) vis[x] = 0;
		per(i, m, 1) {
			erase(y[i]);
			insert(x[i], x[i]);
		}
	}
	return 0;
}