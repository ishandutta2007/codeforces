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
const int M = 5e5 + 5 ; 
struct E {
	int to, next ; 
} e[M << 1] ;
int n, m, head[M], p[M], t[M], tf[M], Id[M], cnt ;
int w[M] ;  
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ;  
}
bool cmp( int x, int y ) {
	return tf[x] < tf[y] ; 
}
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, m ) x = gi(), y = gi(), add( x, y ) ; 
	rep( i, 1, n ) tf[i] = gi(), Id[i] = i ; 
	sort( Id + 1, Id + n + 1, cmp ) ;
	rep( i, 1, n ) {
		p[i] = Id[i] ; 
		Next( j, p[i] ) w[t[e[j].to]] = 1 ; 
		int f = 1 ; 
		while( w[f] ) ++ f ;
		t[p[i]] = f ; 
		Next( j, p[i] ) w[t[e[j].to]] = 0 ; 
	}
	int flag = 0 ; 
	rep( i, 1, n ) if( t[i] != tf[i] ) flag = 1 ; 
	if( flag ) { puts("-1") ; exit(0) ; } 
	rep( i, 1, n ) printf("%d ", p[i] ) ;
	return 0 ;
}