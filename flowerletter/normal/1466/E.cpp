/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fir first
#define sec second
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int maxn = 5e5, maxw = 60, mod = 1e9 + 7;

int T, n, cnt[maxw + 5];
ll ans, a[maxn + 5], f[maxn + 5], g[maxn + 5];

inline void red(ll &x) {x %= mod;}

int main() {
	//freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n);ans = 0;
		rep(i, 1, n) f[i] = g[i] = 0;
		rep(i, 0, 60) cnt[i] = 0;
		rep(i, 1, n) scanf("%lld", &a[i]);
		rep(i, 1, n) rep(j, 0, 60) if((a[i] >> j) & 1) cnt[j]++;
		rep(i, 1, n) {
			rep(j, 0, 60) if((a[i] >> j) & 1) red(f[i] += (1ll << j) % mod * cnt[j] % mod);
			rep(j, 0, 60) 
				if((a[i] >> j) & 1) red(g[i] += (1ll << j) % mod * n % mod); 
				else red(g[i] += (1ll << j) % mod * cnt[j] % mod);
			red(ans += f[i] * g[i] % mod);
		}
		printf("%lld\n", ans);
	}
	return 0;
}