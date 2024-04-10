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
template<int T> using A = array<int, T>;
const int maxn = 2e5;
const int maxm = 4e5;
const int mod = 998244353;
int T, n, cnt, head[maxn + 5], inv[maxn + 5];
int val, ans;
struct Edge {
	int to, nxt;
	vector<P> x, y;
}e[maxm + 5];
void add(int u, int v, vector<P> x, vector<P> y) {
	e[++ cnt] = {v, head[u], x, y}, head[u] = cnt;
}
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int fpw(int a, int b) {
	int ans =1;
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
int cur[maxn + 5], mx[maxn + 5];
void dfs1(int u, int par) {
	trv(i, u, v) if(v != par) {
		for(auto x : e[i].y) {
			cur[x.fi] += x.se;
		}
		for(auto x : e[i].x) {
			cur[x.fi] -= x.se;
			chkmx(mx[x.fi], - cur[x.fi]);
		}
		dfs1(v, u);
		for(auto x : e[i].x) {
			cur[x.fi] += x.se;
		}
		for(auto x : e[i].y) {
			cur[x.fi] -= x.se;
		}
	}
}
void dfs2(int u, int par) {
	ans = add(ans, val);
	trv(i, u, v) if(v != par) {
		int lst = val;
		for(auto x : e[i].x) {
			val = mul(val, fpw(inv[x.fi], x.se));
		}
		for(auto x : e[i].y) {
			val = mul(val, fpw(x.fi, x.se));
		}
		dfs2(v, u);
		val = lst;
	}
}
void init() {
	inv[0] = inv[1] =1;
	rep(i, 2, maxn) inv[i] = mul(mod - mod / i, inv[mod % i]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	for(cin >> T; T; T --) {
		cin >> n;
		rep(i, 2, n) {
			int u, v, x, y;
			cin >> u >> v >> x >> y;
			vector<P> p, q;
			rep(i, 2, sqrt(x)) if(x % i == 0) {
				int ret =0 ;
				while(x % i == 0) x/= i, ret ++;
				p.pb({i, ret});
			}
			if(x != 1) p.pb({x, 1});
			rep(i, 2, sqrt(y)) if(y % i == 0) {
				int ret =0 ;
				while(y % i == 0) y /= i, ret ++;
				q.pb({i, ret});
			}
			if(y != 1) q.pb({y, 1});
			add(u, v, p, q);
			add(v, u, q, p);
		}
		dfs1(1, 1);
		val = 1;
		rep(i, 1, n) val = mul(val, fpw(i, mx[i]));//, cout << i << ' ' << mx[i] << '\n';
		dfs2(1, 1);
		cout << ans << '\n';
		rep(i, 1, n) cur[i] = mx[i] = 0, head[i] = 0;
		cnt = ans = 0;
	}
	return 0;
}