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
const int mod = 998244353;
int n, a, x, y, k, m, invn, pw[17];
vector<int> f, g;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;} 
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;} 
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), a = read(), x = read(), y = read(), k = read(), m = read();
	ll lcm = 1;
	int invn = fpw(n, mod - 2);
	rep(i, 1, k - 1) lcm *= i / __gcd((ll) i, lcm);
	f.resize(lcm), g.resize(lcm);
	pw[0] = 1;
	rep(i, 1, k) pw[i] = mul(pw[i - 1], n); 
	per(i, k - 1, 1) {
		swap(f, g);
		rep(j, 0, lcm - 1) {
			f[j] = add(mul(n - 1, g[j]), add(g[j - j % i], mul(mul(j % i, k - i), pw[k - i - 1])));
		}
	}
	int ans = 0;
	rep(i, 0, n - 1) {
		ans = sub(ans, f[a % lcm]);
		ans = add(ans, mul(a, mul(k, pw[k - 1]))); 
		a = (1ll * a * x + y) % m;
	}
	cout << ans << '\n';
	return 0;
}