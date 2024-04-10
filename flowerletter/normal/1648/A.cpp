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

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e5;
int n, m;
vector<int> a[maxn + 5], st;
vector<P> p[maxn + 5];
ll solve(vector<P> p) {
	sort(all(p));
	ll cur = 0, ans = 0;
	rep(i, 0, sz(p) - 1) {
		ans += 1ll * i * p[i].fi - cur;
		cur += p[i].fi;
	}
	sort(all(p), [&] (P x, P y) {return x.se < y.se;});
	cur = 0;
	rep(i, 0, sz(p) - 1) {
		ans += 1ll * i * p[i].se - cur;
		cur += p[i].se;
	}
	return ans;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	n = read(), m = read();
	rep(i, 1, n) {
		a[i].resize(m + 1);
		rep(j, 1, m) {
			p[a[i][j] = read()].pb({i, j});
		}
	}
	ll ans = 0;
	rep(i, 1, maxn) {
		ans += solve(p[i]);
	}
	cout << ans << '\n';
	return 0;
}