#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = (1 << 20) + 5 ; 
int m, n, K, lim, ans1, ans2, c1[25], c2[25], p[25], p2[25], p3[25], f1[N], f2[N], A[N], B[N] ; 
char s[25] ; 
signed main()
{
	n = gi(), m = gi(), K = gi(), lim = (1 << K) - 1; 
	scanf("%s", s + 1 ) ; 
	rep( i, 1, K ) c1[i] = s[i] - '0' ;
	rep( i, 1, K ) A[0] = ((A[0] << 1) | c1[i]), ans1 += c1[i] ; 
	scanf("%s", s + 1 ) ;
	rep( i, 1, K ) c2[i] = s[i] - '0' ; 
	rep( i, 1, K ) B[0] = ((B[0] << 1) | c2[i]), ans2 += c2[i] ; 
	rep( i, 1, K ) p[i] = i ; 
	int x, y ; 
	memset( f1, 63, sizeof(f1) ) ; 
	rep( i, 1, n ) {
		x = gi(), y = gi() ; 
		rep( j, 1, K ) p2[j] = j ;
		swap( p2[x], p2[y] ) ;
		rep( j, 1, K ) p3[j] = p2[p[j]] ;
		rep( j, 1, K ) p[j] = p3[j] ; 
		rep( j, 1, K ) 
			A[i] = ((A[i] << 1) | c1[p[j]]),
			B[i] = ((B[i] << 1) | c2[p[j]]) ;
		
	}
	rep( i, 0, n ) 
		f1[A[i]] = min( f1[A[i]], i ), f2[B[i]] = max( f2[B[i]], i ) ;
	int ans = 0, l = 0, r = 0 ; 
	drep( i, 0, lim ) {
		for(re int j = 1; j <= lim; j <<= 1)
		f1[i ^ j] = min( f1[i ^ j], f1[i] ),
		f2[i ^ j] = max( f2[i ^ j], f2[i] ) ; 
		if( f2[i] - f1[i] >= m ) {
			int d = K - ans1 - ans2 + 2 * __builtin_popcountll(i) ;
			if( ans <= d ) ans = d, l = f1[i], r = f2[i] ; 
		}
	}
	cout << ans << endl ; 
	cout << l + 1 << " " << r << endl ; 
	return 0 ;
}