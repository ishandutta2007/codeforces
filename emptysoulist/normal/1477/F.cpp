#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 52 ; 
const int M = 4000 + 5 ; 
const int P = 998244353 ;
int n, m, L, S, a[N], f[N][M], g[N][M] ; 
int inv[M], fac[M], ifac[M] ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
void inc(int &x, int y) { ((x += y) >= P) && (x -= P) ; }
void dec(int &x, int y) { ((x -= y) < 0) && (x += P) ; }
signed main()
{
	n = gi(), m = gi(), fac[0] = 1 ; 
	rep( i, 1, 2000 ) inv[i] = fpow(i, P - 2), fac[i] = fac[i - 1] * i % P ; 
	rep( i, 0, 2000 ) ifac[i] = fpow(fac[i], P - 2) ; 
	rep( i, 1, n ) a[i] = gi(), S += a[i] ; 
	f[0][0] = 1 ; 
	rep( i, 1, n ) {
		int lim = (a[i] / m) ; L += lim ; 
		rep( j, 0, i ) rep( k, 0, L ) g[j][k] = f[j][k], f[j][k] = 0 ; 
		rep( j, 0, lim ) {
			int z = a[i] - j * m, o = z * inv[S] % P, v = ifac[j] * fpow(P - 1, j) % P ; 
			int zz = fpow(o, j + P - 2) * j % P * v % P ;
			rep( k, 0, i ) rep( l, 0, L ) 
			inc(f[k + 1][l + j], g[k][l] * zz % P) ; 
			int zt = fpow(o, j) * v % P ; 
			rep( k, 0, i ) rep( l, 0, L ) 
			inc( f[k][l + j], g[k][l] * zt % P) ; 
		}
	} int ans = 0 ; 
	rep( o, 0, n ) rep( j, 0, L ) {
		if((!o) && (!j)) continue ; 
		if(!f[o][j]) continue ; 
		int i = j - o ; 
		int d = f[o][j] * fac[i] % P * fpow(S * fpow(j * m, P - 2) % P, i + 1) % P ; 
		dec(ans, d) ; 
	}
	cout << ans << endl ; 
	return 0 ;
}