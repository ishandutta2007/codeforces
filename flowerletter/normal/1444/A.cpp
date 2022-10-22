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
int T;
ll p, q;
inline ll fpw(ll a, int b, ll ans = 1) {
	for(; b; b >>= 1, a = a * a) if(b & 1) ans = ans * a;
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T --)  {
		scanf("%lld%lld", &p, &q);
		if(p % q != 0) printf("%lld\n", p);
		else {
			ll mn = p;
			rep(i, 2, sqrt(q)) {
				if(q % i == 0) {
					ll res = 0, x = p, y = q;
					while(x % i == 0) res ++, x /= i;
					while(y % i == 0) res --, y /= i;
					chkmn(mn, fpw(i, res + 1));
					q = y;
				}
			}
			if(q != 1) {
				ll res = -1, x = p;
				while(x % q == 0) res ++, x /= q;
				chkmn(mn, fpw(q, res + 1));
			}
			printf("%lld\n", p / mn);
		}
	}
	return 0;
}