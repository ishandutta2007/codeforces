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
const int N = (1 << 10) + 5 ;
const int M = 505 ;
int lim, n, m ; 
struct Mat {
	int a[N][N] ; 
	int sx[M], sy[M], top ; 
	void ins( int x, int y ) { ++ top, sx[top] = x, sy[top] = y ; }
	void init() { top = 0, memset( a, 0, sizeof(a) ) ; }
} A, F, ans ; 
Mat operator * ( Mat x, Mat y ) {
	ans.init() ; 
	for(re int i = 0; i < lim; ++ i) for(re int j = 0; j < lim; ++ j) 
		rep( k, 1, y.top ) 
			ans.a[(y.sx[k] + i) % lim][(y.sy[k] + j) % lim] ^= ( x.a[i][j] ) ;
	return ans ; 
} 
void Find(Mat &x) {
	x.top = 0 ; 
	for(re int i = 0; i < lim; ++ i) for(re int j = 0; j < lim; ++ j)
		if( x.a[i][j] ) x.ins(i, j) ; 
}
signed main()
{
	n = gi(), lim = (1 << n) ;
	rep( i, 0, lim - 1 ) rep( j, 0, lim - 1 ) A.a[i][j] = gi() ; 
	m = gi() ; int x, y ; 
	rep( i, 1, m ) x = gi() - 1, y = gi() - 1, F.a[x][y] = 1, F.ins(x, y) ; 
	rep( i, 1, n ) 
		A = A * F, F = F * F, Find(F) ;
	int Ans = 0 ; 
	rep( i, 0, lim - 1 ) rep( j, 0, lim - 1 ) if( A.a[i][j] ) ++ Ans ; 
	cout << Ans << endl ; 
	return 0 ;
}