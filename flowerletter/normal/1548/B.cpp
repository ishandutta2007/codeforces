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
typedef pair<ll, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 2e5;
int n;
ll a[maxn + 5];
int main() {
// 	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) a[i] = read();
		per(i, n, 2) a[i] -= a[i - 1];
		vector<P> s;
		int ans = 0;
		rep(i, 2, n) {
			vector<P> t;
			s.pb({a[i], 1});
			for(auto &x : s) {
				x.fi = abs(__gcd(x.fi, a[i])); 
			}
			per(i, sz(s) - 1, 1) {
				if(s[i].fi == s[i - 1].fi) {
					s[i - 1].se += s[i].se;
					s[i].se = 0;
				}
			}
			for(auto x : s) if(x.se) t.pb(x);
			s = t;
			int cur = 0;
			for(auto x : s) if(x.fi != 1) cur += x.se, chkmx(ans, cur); 
		}
		cout << ans + 1 << '\n';
	}
	return 0;
}