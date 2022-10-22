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
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e6;
const ll inf = 1e18;
int n, m, a[maxn + 5], b[maxn + 5];
ll f[maxn + 5][2];
int main() {
// 	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read(), m = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 1, m) b[i] = read();
		int gcd = 0;
		rep(i, 1, m) gcd = __gcd(gcd, b[i]);
		ll ans1 = 0, ans2 = 0;
		rep(i, 0, gcd - 1) {
			int id = 0; 
			for(int j = !i ? gcd : i; j <= n; j += gcd) {
				f[j][0] = max(a[j] + (j <= gcd ? 0 : f[j - gcd][0]), -a[j] + (j <= gcd ? -inf : f[j - gcd][1]));
				f[j][1] = max(a[j] + (j <= gcd ? -inf : f[j - gcd][1]), -a[j] + (j <= gcd ? 0 : f[j - gcd][0]));
				id = j;
			}
			ans1 += f[id][0], ans2 += f[id][1];
		}
		cout << max(ans1, ans2) << '\n';
	}
	return 0;
}