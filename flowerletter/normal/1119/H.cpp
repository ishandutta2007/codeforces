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
const int maxn = 1 << 20;
const int maxk = 3;
const int maxs = 1 << 3;
const int mod = 998244353;
const int inv2 = (mod + 1) / 2;
int n, m, k = 3, x, y, z, val[maxk + 5], w[maxs + 5], sum[maxs + 5], a[maxn + 5][maxk + 5], b[maxs + 5][maxn + 5], c[maxs + 5], f[maxn + 5], lg[maxs + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b)< 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
inline int fpw(int a, int b, int ans = 1) {
	for(; b; b >>= 1, a = mul(a, a)) if(b & 1) ans = mul(ans, a);
	return ans;
}
void fwt(int *a, int len, int type) {
	for(int i = 1; i < len; i <<= 1) {
		for(int j = 0; j < len; j += (i << 1)) {
			for(int k = 0; k < i; k ++) {
				int x = a[j + k], y = a[i + j + k];
				if(type) a[j + k] = add(x, y), a[i + j + k] = sub(x, y);
				else a[j + k] = mul(inv2, add(x, y)), a[i + j + k] = mul(inv2, sub(x, y));
			}
		}
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n >> m;
	rep(i, 0, k - 1) cin >> val[i];
	rep(i, 2, (1 << k) - 1) lg[i] = lg[i >> 1] + 1;
	rep(s, 0, (1 << k) - 1) {
		rep(i, 0, k - 1) if(s & (1 << i)) w[s] = sub(w[s], val[i]); else w[s] = add(w[s], val[i]);	
	}
	rep(i, 1, n) {
		rep(j, 0, k - 1) cin >> a[i][j];
		b[0][0] ++;
		rep(s, 1, (1 << k) - 1) {
			sum[s] = sum[s ^ lb(s)] ^ a[i][lg[lb(s)]];
			b[s][sum[s]] ++;
		}
	}
	rep(i, 0, (1 << k) - 1) fwt(b[i], 1 << m, 1);
	rep(i, 0, (1 << m) - 1) {
		rep(s, 0, (1 << k) - 1) c[s] = b[s][i];
		fwt(c, 1 << k, 0);
		f[i] = 1;
		rep(s, 0, (1 << k) - 1) f[i] = mul(f[i], fpw(w[s], c[s]));
	}
	fwt(f, 1 << m, 0);
	rep(i, 0, (1 << m) - 1) cout << f[i] << ' ';
	return 0;
}