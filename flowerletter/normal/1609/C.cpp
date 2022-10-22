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
const int maxn = 2e5;
const int maxm = 1e6;
const int inf = 1e9;
int n, e, a[maxn + 5], vis[maxm + 5], f[maxn + 5];
void init() {
	rep(i, 2, maxm) if(!vis[i]) {
		rep(j, 2, maxm / i) vis[j * i] = 1;
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	init();
	for(int T = read(); T; T --) {
		n = read(), e = read();
		rep(i, 1, n) a[i] = read();
		ll ans = 0;
		rep(i, 1, e) {
			for(int l = 0, r; l * e + i <= n; l = r + 1) {
				r = l;
				if(vis[a[l * e + i]]) continue;
				int cur = 0;
				vector<int> s;
				if(a[l * e + i] == 1) cur ++;
				else s.pb(0);
				while((r + 1) * e + i <= n && !vis[a[(r + 1) * e + i]]) {
					if(a[(r + 1) * e + i] == 1) cur ++;
					else {
						s.pb(cur);
						cur = 0;
					}
					r ++;
				}
				s.pb(cur);
				rep(i, 1, sz(s) - 1) ans += 1ll * s[i - 1] * s[i] + s[i - 1] + s[i];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}