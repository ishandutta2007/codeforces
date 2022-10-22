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
const int maxn = 4e6;
int n, mod, f[maxn + 5], g[maxn + 5], h[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n >> mod;
	f[1] = g[1] = 1;
	rep(i, 2, n) {
		h[i] = add(1, add(h[i], h[i - 1]));
		f[i] = add(g[i - 1], h[i]);
		g[i] = add(g[i - 1], f[i]);
		rep(j, 2, n / i) h[i * j] = add(h[i * j], sub(f[i], f[i - 1]));
	}
	cout << f[n] << '\n';
	return 0;
}