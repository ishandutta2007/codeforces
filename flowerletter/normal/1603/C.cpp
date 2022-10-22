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
const int maxn = 1e5;
const int mod = 998244353;
int T, n, a[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(T = read(); T; T --) {
		ll ans = 0;
		n = read();
		rep(i, 1, n) a[i] = read();
		vector<P> s;
		per(i, n, 1) {
			vector<P> t;
			for(auto &x : s) (ans += 1ll * x.se * i % mod * ((a[i] - 1) / x.fi) % mod) %= mod, x.fi = a[i] / ((a[i] + x.fi - 1) / x.fi);			s.pb({a[i], 1});
			per(i, sz(s) - 1, 0) {
				if(i && s[i].fi == s[i - 1].fi) s[i - 1].se += s[i].se;
				else t.push_back(s[i]);
			}
			swap(s, t);
		}
		cout << ans << '\n';
	}
	return 0;
}