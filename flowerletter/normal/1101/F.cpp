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
const int maxn = 400;
const int inf = 1e9;
int n, m, a[maxn + 5], f[maxn + 5][maxn + 5], opt[maxn + 5][maxn + 5];
vector<P> qry[maxn + 5][maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m) {
		int s = read(), f = read(), c = read(), r = read();
		qry[s][f].pb({min(n, r + 1), c}); 
	} 
	ll ans = -1;
	rep(i, 1, n) {
		memset(f, 0, sizeof f);
		rep(j, i + 1, n) f[j][0] = inf; 
		rep(j, i, n) {
			rep(k, 1, n) {
				int nw = opt[j][k];
				while(nw < j && a[j] - a[nw] > f[nw][k - 1]) nw ++;
				if(max(f[nw][k - 1], a[j] - a[nw]) > max(f[nw - 1][k - 1], a[j] - a[nw - 1])) {
					f[j][k] = max(f[nw - 1][k - 1], a[j] - a[nw - 1]);
					opt[j][k] = nw - 1;
				}
				else {
					f[j][k] = max(f[nw][k - 1], a[j] - a[nw]);
					opt[j][k] = nw;
				}
			}
			for(auto x : qry[i][j]) chkmx(ans, 1ll * f[j][x.fi] * x.se);
		}
	}
	cout << ans << '\n';
	return 0;
}