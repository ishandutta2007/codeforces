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
const int maxn = 1e5;
int T, f[maxn + 5];
ll a, b, c;
void init() {
	rep(i, 1, maxn) rep(j, 1, maxn / i) f[i * j] ++;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	for(cin >> T; T; T --) {
		cin >> a >> b >> c;
		ll x = __gcd(a, b), y = __gcd(a, c), z = __gcd(b, c), w = __gcd(z, a);
		ll w1 = f[a] - f[x] - f[y] + f[w], w2 = f[b] - f[x] - f[z] + f[w], w3 = f[c] - f[y] - f[z] + f[w];
		ll w4 = f[x] - f[w], w5 = f[y] - f[w], w6 = f[z] - f[w], w7 = f[w];
		ll ans = 0;
		ans += w1 * w2 * w3;
		ans += w1 * w2 * w5;
		ans += w1 * w2 * w6;
		ans += w1 * w2 * w7;
		
		ans += w1 * w4 * w3;
		ans += w1 * w4 * w5;
		ans += w1 * w4 * w6;
		ans += w1 * w4 * w7;
		
		
		ans += w1 * w6 * w3;
		ans += w1 * w6 * w5;
		ans += w1 * w6 * (w6 + 1) / 2;
		ans += w1 * w6 * w7;
		
		ans += w1 * w7 * w3;
		ans += w1 * w7 * w5;
		ans += w1 * w7 * (w7 + 1) / 2;
		
		ans += w4 * w2 * w3;
		ans += w4 * w2 * w6;
		ans += w4 * w2 * w7;
		ans += w4 * w2 * w5; // 2 4 5
		
		ans += w4 * (w4 + 1) * w3 / 2;
		ans += w4 * (w4 + 1) * w6 / 2;
		ans += w4 * (w4 + 1) * w7 / 2;
		ans += w4 * (w4 + 1) * w5 / 2;
		
		ans += w4 * w6 * w3; // 4 6 3
		ans += w4 * w6 * w5; // 4 6 5
		ans += w4 * w6 * (w6 + 1) / 2;
		ans += w4 * w6 * w7; // 4 6 7 
		
		ans += w4 * w7 * (w7 + 1) / 2;
		ans += w4 * w7 * w3;
		ans += w4 * w7 * w5;
		
		ans += w5 * w2 * w3;
		ans += w5 * w2 * (w5 + 1) / 2;
		ans += w5 * w2 * w6;
		ans += w5 * w2 * w7;
		
		ans += w5 * w4 * w3;
		ans += w5 * w4 * (w5 + 1) / 2;
		
		ans += w5 * w6 * w3;
		ans += w5 * w6 * (w5 + 1) / 2;
		ans += w5 * w6 * (w6 + 1) / 2;
		ans += w5 * w6 * w7;
		
		ans += w5 * w7 * (w7 + 1) / 2;
		ans += w5 * w7 * (w5 + 1) / 2;
		ans += w5 * w7 * w3;
		
		ans += (w7 + 1) * (w7 + 1) * w7 / 2 - w7 * (w7 + 1) * (2 * w7 + 1) / 6;
		ans += w7 * (w7 + 1) * w3 / 2;
		ans += w7 * (w7 + 1) * w6 / 2;
		
		ans += w7 * w2 * w3;
		ans += w7 * w2 * w6;
		ans += w7 * w2 * (w7 + 1) / 2;
		
		ans += w7 * w6 * w3;
		ans += w7 * w6 * (w6 + 1) / 2;		 
		
		cout << ans << '\n';
	}
	return 0;
}