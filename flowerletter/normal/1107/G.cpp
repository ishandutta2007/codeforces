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
typedef pair<ll,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 3e5;
const int lg = 18;
int n, a, d[maxn + 5], c[maxn + 5], lg2[maxn + 5];
ll ans, gap[maxn + 5], pre[maxn + 5], suf[maxn + 5];
struct RealPair {
	ll first;
	int second;
	friend bool operator < (RealPair x, RealPair y) {return x.first < y.first;} 
};
struct Rmq {
	ll mx[maxn + 5][lg + 1];
	int p[maxn + 5][lg + 1]; 
	void init(ll * a) {
		rep(i, 1, n) mx[i][0] = a[i], p[i][0] = i;
		rep(i, 1, lg) rep(j, 1, n - (1 << i) + 1) {
			if(mx[j][i - 1] <mx[j + (1 << i - 1)][i - 1]) mx[j][i] = mx[j + (1 << i - 1)][i - 1], p[j][i] = p[j + (1 << i - 1)][i - 1];
			else mx[j][i] = mx[j][i - 1], p[j][i] = p[j][i - 1];
		}
	}
	RealPair query(int l, int r) {
		if(l > r) return {0, -1};
		int k = lg2[r - l + 1];
		if(mx[l][k] < mx[r - (1 << k) + 1][k]) return {mx[r - (1 << k) + 1][k], p[r - (1 << k) + 1][k]};
		else return {mx[l][k], p[l][k]};
	}
}g, p, s;
void solve(int l, int r) {
	if(l == r) return chkmx(ans, (ll) a - c[l]), void();
	RealPair mid = g.query(l, r - 1);
	RealPair ls = s.query(l, mid.se), rs = p.query(mid.se + 1, r);
	chkmx(ans, ls.fi + rs.fi - mid.fi - suf[mid.se + 1] - pre[mid.se]);
	solve(l, mid.se), solve(mid.se + 1, r);
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), a = read();
	rep(i, 1, n) d[i] = read(), c[i] = read();
	rep(i, 2, maxn) lg2[i] = lg2[i >> 1] + 1;
	rep(i, 1, n) gap[i] = 1ll * (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
	rep(i, 1, n) pre[i] = pre[i - 1] + a - c[i];
	per(i, n, 1) suf[i] = suf[i + 1] + a - c[i];
	g.init(gap), p.init(pre), s.init(suf);
	solve(1, n);
	cout << ans << '\n';
	return 0;
}