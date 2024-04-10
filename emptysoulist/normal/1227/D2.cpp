#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) ( x << 1 )
#define rs(x) ( x << 1 | 1 )
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
int n, m, b[N], ans[N], vis[N] ; 
struct Q {
	int id, y ;
} ; 
struct node {
	int x, id ; 
} a[N] ;
vector<Q> e[N] ; 
bool cmp( node x, node y ) {
	return ( x.x == y.x ) ? x.id < y.id : x.x > y.x ; 
}
struct Tr {
	int w ; 
} tr[N << 2] ;
void insert( int x, int l, int r, int pos ) {
	++ tr[x].w ; if( l == r ) return ; 
	int mid = ( l + r ) >> 1 ; 
	if( mid >= pos ) insert( ls(x), l, mid, pos ) ;
	else insert( rs(x), mid + 1, r, pos ) ;
}
int Query( int x, int l, int r, int k ) {
	if( l == r ) return b[l] ; 
	int mid = ( l + r ) >> 1, Ls = tr[ls(x)].w ; 
	if( k > Ls ) return Query( rs(x), mid + 1, r, k - Ls ) ;
	else return Query( ls(x), l, mid, k ) ; 
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 1, n ) a[i].x = gi(), a[i].id = i, b[i] = a[i].x ; 
	sort( a + 1, a + n + 1, cmp ) ;
	m = gi() ; 
	rep( i, 1, m ) {
		x = gi(), y = gi() ; 
		e[x].push_back((Q){i, y}) ; 
	}
	rep( i, 1, n ) {
		insert( 1, 1, n, a[i].id ) ;
		for( re int j = 0; j < e[i].size(); ++ j ) {
			ans[e[i][j].id] = Query( 1, 1, n, e[i][j].y ) ;
		}
	}
	rep( i, 1, m ) printf("%I64d\n", ans[i] ) ;
	return 0 ;
}