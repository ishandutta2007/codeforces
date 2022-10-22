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
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 20;
const int maxm = 5e4;
const int mod = 998244353;
int n, m, d[maxn + 5][maxm + 5], a[maxn + 5];
int ans;
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) ans = 1ll * ans * a % mod;
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	rep(i, 1, n) rep(j, 1, m) scanf("%d", &d[i][j]);
	rep(i, 1, m) {
		rep(j, 1, n) a[j] = d[j][i];
		sort(a + 1, a + n + 1);
		int flag = 1, res = 1;
		rep(i, 1, n) flag |= a[i] <= i; 
		if(!flag) ans ++;
		else {
			rep(i, 1, n) res = 1ll * res * (a[i] - i) % mod * fpw(n - i + 1, mod - 2) % mod;
			ans = (ans + mod + 1 - res) % mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}