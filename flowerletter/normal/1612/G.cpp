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
const int maxn = 5e5;
const int maxm = 1e6;
const int mod = 1e9 + 7;
int n, c[maxn + 5], mem[maxm * 2 + 6], *f = mem + maxm + 3;
int fac[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;} 
void init() {
	fac[0] = fac[1] = 1;
	rep(i, 2, maxn) fac[i] = mul(fac[i - 1], i);
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(); init();
	rep(i, 1, n) c[i] = read(), f[-c[i] + 1] ++, f[c[i] + 1] --;
	int ans1 = 0, ans2 = 1, s = 0;
	rep(i, -maxm, maxm) {
		f[i] += f[i - 2];
		ans1 = add(ans1, mul(f[i], s));
		ans2 = mul(ans2, fac[f[i]]);
		s = add(s, mul(f[i], mod - i));
	}
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}