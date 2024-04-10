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
const int N = 4e6 + 5 ; 
int G, H, n, a[N], b[N], dep[N] ; 
int st[N], top, flag = 0, ans[N], cnt ; 
#define ls(x) ( x << 1 )
#define rs(x) ( x << 1 | 1 ) 
void F( int x ) {
	a[x] = 0, st[++ top] = x ; 
	if( max( a[ls(x)], a[rs(x)] ) != 0 ) {
		if( a[ls(x)] > a[rs(x)] ) a[x] = a[ls(x)], F(ls(x)) ;
		else a[x] = a[rs(x)], F(rs(x)) ; 
	}
	if( ( a[x] == 0 ) && ( dep[x] <= G ) ) flag = 1 ;  
}
void dfs( int x ) {
	if( x > n ) return ; 
	while( ( !flag ) && ( a[x] != 0 ) ) {
		top = 0, F(x) ; 
		if( flag ) rep( i, 1, top ) a[st[i]] = b[st[i]] ; 
		else {
			rep( i, 1, top ) b[st[i]] = a[st[i]] ; 
			ans[++ cnt] = x ;
		}
	}
	flag = 0 ;
	dfs( ls(x) ), dfs( rs(x) ) ;
}
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		H = gi(), G = gi(), cnt = 0 ;
		n = ( 1ll << H ) - 1 ; 
		rep( i, 1, n ) b[i] = a[i] = gi() ; 
		rep( i, 1, n ) dep[i] = dep[i >> 1] + 1 ; 
		dfs( 1 ) ;
		n = ( 1ll << G ) - 1 ; int Ans = 0 ;
		rep( i, 1, n ) Ans += a[i] ; 
		printf("%I64d\n", Ans ) ;
		rep( i, 1, cnt ) printf("%I64d ", ans[i] ) ;
		puts("") ; 
		rep( i, 1, n ) b[i] = a[i] = 0 ;
	}
	return 0 ;
}