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
const int maxn = 1e5;
const int mod = 998244353;
int T, n, fac[maxn+ 5], inv[maxn + 5];
char s[maxn+ 5]; 
void init() {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	rep(i, 2, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
	rep(i, 2, maxn) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	rep(i, 2, maxn) inv[i] = 1ll * inv[i] * inv[i - 1] % mod;
}
inline int c(int n, int m) {
	if(n < m) return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
	//freopen("in.txt", "r", stdin);
	init();
	for(scanf("%d", &T); T; T--) {
		scanf("%d%s", &n, s + 1);
		int cnt1 = 0, cnt00 = 0, lst = 0;
		rep(i, 1, n)  
			if(s[i] == '0') cnt00 += (i - lst - 1) / 2, lst = i;
			else cnt1 ++;
		cnt00 += (n - lst) / 2; 
		printf("%d\n", c(n - cnt1 + cnt00, n - cnt1));
	}
	return 0;
}