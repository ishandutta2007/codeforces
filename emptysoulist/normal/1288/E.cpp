#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define ls(x) tr[x].l
#define rs(x) tr[x].r
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ;
int Mi[N], Mx[N], n, m, cnt, a[N], bef[N], Go[N], nxt[N], rt[N] ;
struct Tr {
	int l, r, w ; 
} tr[N * 25] ;
void insert( int &x, int u, int l, int r, int k ) {
	x = ++ cnt, tr[x] = tr[u], ++ tr[x].w ;
	if( l == r ) return ; 
	int mid = ( l + r ) >> 1 ;
	if( mid >= k ) insert( ls(x), ls(u), l, mid, k ) ;
	else insert( rs(x), rs(u), mid + 1, r, k ) ;
}
int Query( int u, int x, int l, int r, int k ) {
	if( l == r ) return tr[u].w - tr[x].w ;
	int mid = ( l + r ) >> 1 ; 
	if( mid >= k ) return Query( ls(u), ls(x), l, mid, k ) ;
	else return Query( rs(u), rs(x), mid + 1, r, k ) + tr[ls(u)].w - tr[ls(x)].w ;
}
int tree[N] ;
int lowbit( int x ) {
	return x & (-x) ;
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
	n = gi(), m = gi() ;
	rep( i, 1, m ) a[i] = gi() ; 
	rep( i, 1, n ) Mi[i] = Mx[i] = i ;
	rep( i, 1, m ) Mi[a[i]] = 1 ;
	rep( i, 1, m ) Go[i] = nxt[a[i]], nxt[a[i]] = i ; 
	rep( i, 1, m ) insert( rt[i], rt[i - 1], 1, m + 1, Go[i] + 1 ) ;
	rep( i, 1, m ) {
		if( !bef[a[i]] ) {
			Mx[a[i]] = max( Mx[a[i]], Q(n) - Q(a[i]) + a[i] ) ;
			add( a[i], 1 ) ; // 1 4 2 4 1
		}
		else Mx[a[i]] = max( Mx[a[i]], Query( rt[i - 1], rt[bef[a[i]]], 1, m + 1, bef[a[i]] + 1 ) + 1 ) ;
		bef[a[i]] = i ;
	}
	int top = n ; 
	for( re int i = n; i >= 1; -- i ) 
	if( !bef[i] ) Mx[i] = max( Mx[i], top ), -- top ;
	for( re int i = 1; i <= n; ++ i )
		if( bef[i] ) {
			Mx[i] = max( Mx[i], Query( rt[m], rt[bef[i]], 1, m + 1, bef[i] + 1 ) + 1 ) ;
		}
	rep( i, 1, n ) printf("%I64d %I64d\n", Mi[i], Mx[i] ) ;
	return 0 ;
}