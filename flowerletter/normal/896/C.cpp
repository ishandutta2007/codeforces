/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;


template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}

const int maxn = 1e5;
int n, m, seed, vmx, opt, l, r, x, y;
struct Node {
	int l, r; mutable ll x;
	inline friend bool operator < (Node a, Node b) {
		return a.l < b.l;
	}
};
typedef set<Node>::iterator sit;
set<Node> s;
inline int rnd() {
	int ret = seed;
	seed = (1ll * seed * 7 + 13) % (int)(1e9 + 7);
	return ret;
}
inline int fpw(ll a, ll b, ll mod, ll ans = 1) {
	a %= mod;
	for(; b; b >>= 1, a = a * a % mod) if(b & 1) ans = ans * a % mod;
	return ans;
}
sit split(int p) {
	sit it = s.lower_bound((Node){p, 0, 0});
	if(it != s.end() && it -> l == p) return it;
	it --;
	int l = it -> l, r = it -> r;ll x = it -> x;
	s.erase(it), s.insert((Node) {l, p - 1, x});
	return s.insert((Node) {p, r, x}).fi;
}
void add(int l, int r, int k) {
	sit rit = split(r + 1), lit = split(l);
	for(sit it = lit; it != rit; it ++) it -> x += k;
}
void cover(int l, int r, int k) {
	sit rit = split(r + 1), lit = split(l);
	s.erase(lit, rit), s.insert((Node) {l, r, k});
}
ll kth(int l, int r, int k) {
	vector<P> v;
	sit rit = split(r + 1), lit = split(l);
	for(sit it = lit; it != rit; it ++) v.push_back(mk(it -> x, it -> r - it -> l + 1));
	sort(all(v));
	rep(i, 0, sz(v) - 1) {
		k -= v[i].se;
		if(k <= 0) return v[i].fi;
	}
}
int ksum(int l, int r, int k, int mod) {
	sit rit = split(r + 1), lit = split(l);
	int ans = 0;
	for(sit it = lit; it != rit; it ++) ans = (ans + 1ll * (it -> r - it -> l + 1) * fpw(it -> x, k, mod) % mod) % mod;
	return ans;
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &seed, &vmx);
	rep(i, 1, n) s.insert((Node) {i, i, rnd() % vmx + 1});
	rep(i, 1, m) {
		opt = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
		//cout << opt << ":\n";
		if(l > r) swap(l, r);
		if(opt == 3) x = rnd() % (r - l + 1) + 1;
		else x = rnd() % vmx + 1;
		if(opt == 4) y = rnd() % vmx + 1;
		if(opt == 1) add(l, r, x);
		else if(opt == 2) cover(l, r, x);
		else if(opt == 3) printf("%lld\n", kth(l, r, x));
		else if(opt == 4) printf("%d\n", ksum(l, r, x, y));
	}
	return 0;
}