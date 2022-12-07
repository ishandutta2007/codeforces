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
const int N = 50 + 5 ; 
int n, a[N][N], stx[N], sty[N], top ;  
signed main()
{
	fflush(stdout) ; 
	cin >> n ;
	rep( k, 2, 2 * n ) {
		int t = 0 ;
		int l = max( 1ll, k - n ) ;
		int r = min( n, k - 1 ) ; 
		rep( i, l, r ) {
			a[i][k - i] = t * (1ll << (k - 2)) ;
			t ^= 1 ; 
		}
	}
	rep( i, 1, n ) {
		rep( j, 1, n ) {
			cout << a[i][j] << " " ; 
		}
		puts("") ; 
	}
	int q ; 
	cin >> q ;
	while( q-- ) {
		int x, nx = 1, ny = 1 ; 
		cin >> x ;
		top = 1, stx[1] = sty[1] = 1 ; 
		rep( k, 3, 2 * n ) {
			int u = x & (1ll << (k - 2)) ; 
			++ top ; 
			if( a[nx + 1][ny] == u && nx < n ) stx[top] = nx + 1, sty[top] = ny, ++ nx ;
			else stx[top] = nx, sty[top] = ny + 1, ++ ny ; 
		}
		rep( i, 1, top ) cout << stx[i] << " " << sty[i] << endl ; 
	}
	return 0 ;
}