#include <bits/stdc++.h>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 105
#define MAXM 
#define mod 
#define inf (1<<30)
#define eps (1e-6)
#define alpha 0.75
#define rep(i, x, y) for(register int i = x; i <= y; ++i)
#define repd(i, x, y) for(register int i = x; i >= y; --i)
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
template <typename T> il bool chkmin(T &x, T y) {return x > y ? x = y, 1 : 0;}
template <typename T> il bool chkmax(T &x, T y) {return x < y ? x = y, 1 : 0;}
template <typename T> il void read(T &x) {
	char ch = getchar(); int f = 1; x = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	x *= f;
}
template <typename T, typename... Args> il void read(T &x, Args &...args) {
	read(x), read(args...);
}
int n, x[MAXN], y[MAXN];
bool check(int b) {
	int xl = 1e9, xr = -1, yl = 1e9, yr = -1;
	// cerr << b << ' ' << x[b] << ' ' << y[b] << endl;;
	rep(i, 1, n) 
		if(i != b) {
			chkmin(xl, x[i]), chkmax(xr, x[i]), chkmin(yl, y[i]), chkmax(yr, y[i]);
		}
	// cerr << b << ' ' << xr - xl << ' ' << yr - yl << endl;
	if(xr - xl != yr - yl) return 0;
	if(x[b] == xl && y[b] >= yl && y[b] <= yr) return 0;
	if(x[b] == xr && y[b] >= yl && y[b] <= yr) return 0;
	if(y[b] == yl && x[b] >= xl && x[b] <= xr) return 0;
	if(y[b] == yr && x[b] >= xl && x[b] <= xr) return 0;
	return 1;
}
int main() {
	read(n), n = n * 4 + 1;
	rep(i, 1, n) read(x[i], y[i]);
	rep(i, 1, n) if(check(i)) return 0 * printf("%d %d\n", x[i], y[i]);
	return 0;
}