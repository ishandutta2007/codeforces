#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int unsigned long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ;
const int M = 1e9 + 7 ;
int n, val[N], t[N], wal[N], cnt, num ;
struct node { int id, w, k ; } a[N], b[N] ;
bool cmp( node x, node y ) {
	return ( x.w == y.w ) ? x.k < y.k : x.w < y.w ;
}
signed main()
{
	n = gi() ; srand(time(NULL)) ; int x, y ;
	rep( i, 1, n ) {
		x = gi(), y = gi() ; t[i] = rand() << 31 | rand() ;
		a[++ cnt] = (node){ i, x, 0 }, a[++ cnt] = (node){ i, y, 1 } ;
		x = gi(), y = gi() ; 
		b[++ num] = (node){ i, x, 0 }, b[++ num] = (node){ i, y, 1 } ;
	}
	sort( a + 1, a + cnt + 1, cmp ) ;
	sort( b + 1, b + cnt + 1, cmp ) ;
	int Xor = 0 ;
	for( re int i = 1; i <= cnt; ++ i ) {
		if( a[i].k ) val[a[i].id] ^= Xor ; 
		else Xor ^= t[a[i].id] ;
	} Xor = 0 ;
	for( re int i = 1; i <= cnt; ++ i ) {
		if( !a[i].k ) val[a[i].id] ^= Xor ; 
		else Xor ^= t[a[i].id] ;
	} Xor = 0 ;
	for( re int i = 1; i <= cnt; ++ i ) {
		if( b[i].k ) val[b[i].id] ^= Xor ; 
		else Xor ^= t[b[i].id] ;
	} Xor = 0 ;
	for( re int i = 1; i <= cnt; ++ i ) {
		if( !b[i].k ) val[b[i].id] ^= Xor ; 
		else Xor ^= t[b[i].id] ;
	} Xor = 0 ;
	rep( i, 1, n ) if( val[i] > 0 ) { puts("NO") ; exit(0) ; }
	puts("YES") ;
	return 0 ;
}