#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
const int inf = 1e15 + 7 ; 
int Ans, n, q, k ; 
int F[10] ; 
int g[N], f[N], bef[N] ; 
void solve1() {
	memset( f, -63, sizeof(f) ),
	memset( g, -63, sizeof(g) ),
	g[0] = 0, f[0] = 0 ; 
	int lim = 0 ; k *= 3 ; k -= 3 ; 
	for(re int i = 5; i >= 0; -- i) {
		rep( j, 0, lim ) g[j * 10] = f[j] ; 
		lim = lim * 10 + 9 ; 
		rep( j, 0, lim ) f[j] = g[j] ; 
		int z = k ; f[0] = 0 ; 
		rep( j, 0, lim ) bef[j] = f[j] ; 
		rep( o, 1, 9 ) {
			int c = 0 ; 
			if( o == 3 ) c = F[i] ;
			if( o == 6 ) c = 2 * F[i] ;
			if( o == 9 ) c = 3 * F[i] ; 
			drep( j, o, lim ) f[j] = max( f[j], bef[j - o] + c ) ; 
		}
		rep( j, 0, 22 ) {
			if( z >= (1 << j) ) z -= (1 << j) ;
			else break ; 
			int w = (1 << j) * 3, c = (1 << j) * F[i] ; 
			drep( l, w, lim ) 
			f[l] = max( f[l], f[l - w] + c ) ; 
		}
		int w = z * 3, c = z * F[i] ; 
		drep( l, w, lim ) 
		f[l] = max( f[l], f[l - w] + c ) ; 
		rep( j, 1, lim ) g[j] = -inf ; 
	}
	Ans = f[n] ; 
}
signed main()
{
	k = gi() ; 
	rep( i, 0, 5 ) F[i] = gi() ; 
	q = gi() ; 
	solve1() ; 
	while(q--) {
		n = gi() ; 
		cout << f[n] << endl ; 
	}
	return 0 ;
}