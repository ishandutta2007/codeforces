#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ;
int n, m, a[N], col[N], b[N], t[N], w[N], Ans, tree[N] ; 
int lowbit( int x ) {
	return ( x & ( -x ) ) ;
}
void add( int x, int k ) {
	for( re int i = x; i <= n; i += lowbit(i) ) tree[i] += k ; 
}
int Q( int x ) {
	int sum = 0 ; 
	for( re int i = x; i; i -= lowbit(i) ) sum += tree[i] ;
	return sum ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), m = gi() ; Ans = 0 ;
		rep( i, 1, n ) a[i] = gi(), col[a[i]] = i ;
		rep( i, 1, m ) b[i] = gi(), t[col[b[i]]] = i ; 
		int bef = m + 1 ; 
		rep( i, 1, n ) {
			w[i] = i - 1 - Q( t[i] ) ;
			if( t[i] != 0 ) add( t[i], 1 ) ;
		}
		for( re int i = n; i >= 1; -- i ) {
			if( !t[i] ) continue ; 
			if( bef > t[i] ) {
				Ans += ( w[i] * 2 + 1 ) ; 
			}
			else Ans ++ ;
			bef = min( bef, t[i] ) ;
		}
		printf("%I64d\n", Ans ) ;
		rep( i, 1, n ) tree[i] = t[i] = col[i] = b[i] = w[i] = a[i] = 0 ;
		Ans = 0 ;
	}
	return 0 ;
}