#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int inf = 1e9 + 7000 ; 
const int N = 150 + 5 ; 
int n, m ;
struct Mat {
	bitset<N> a[N] ; 
	void init() {
		rep( i, 1, n ) rep( j, 1, n ) a[i][j] = 0 ;
	}
	void init2() {
		rep( i, 1, n ) rep( j, 1, n ) a[i][j] = 0 ;
		rep( i, 1, n ) a[i][i] = 1 ;  
	}
} A, B ;  
struct E {
	int a, b, c ; 
} e[N] ;
bool cmp( E x, E y ) {
	return x.c < y.c ; 
}
Mat Mul( Mat x, Mat y ) {
	Mat ans ; ans.init() ; 
	rep( k, 1, n ) rep( i, 1, n ) if( x.a[i][k] ) ans.a[i] |= y.a[k] ;
	return ans ; 
}
Mat fpow( Mat x, int k ) {
	Mat ans, base = x ; ans.init2() ; 
	while( k ) {
		if( k & 1 ) ans = Mul( ans, base ) ;
		base = Mul( base, base ), k >>= 1 ; 
	} return ans ; 
}
void Add( int x, int y ) {
	A.a[x][y] = 1 ; 
} 
signed main()
{
	n = gi(), m = gi() ; rep( i, 1, m ) 
	e[i].a = gi(), e[i].b = gi(), e[i].c = gi() ; 
	sort( e + 1, e + m + 1, cmp ) ; e[m + 1].c = inf ; 
	B.init2() ; int t = 0 ; e[0].c = 0 ; 
	for( re int i = 0; i <= m; ++ i ) {
		Add( e[i].a, e[i].b ) ;
		if( e[i].c == e[i + 1].c ) continue ; 
		for( re int j = 1; j <= min( n, e[i + 1].c - e[i].c ); ++ j ) {
			B = Mul( B, A ), ++ t ;
			if( B.a[1][n] == 1 ) { cout << t << endl ; exit(0) ; }
		}
		int ut = max( 0, e[i + 1].c - e[i].c - n ) ; 
		B = Mul( B, fpow( A, ut ) ), t += ut ;
	}
	puts("Impossible") ;
	return 0 ;
}