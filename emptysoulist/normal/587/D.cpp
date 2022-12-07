#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e6 + 5 ; 
int n, m, cnt, head[N], idnum ; 
struct E { int to, next ; } e[N << 1] ;
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ;
}
struct S { int u, v, c, t, id ; } s[N] ; 
struct node { 
	int id, c, Id ;
} ;
vector<node> G[N], V[N] ;
int dfn[N], low[N], st[N], col[N], idnex, top, num ; 
bool cmp( S x, S y ) { return x.c < y.c ; }
void trajin( int x ) {
	dfn[x] = low[x] = ++ num, st[++ top] = x ;
	Next( i, x ) {
		int v = e[i].to ; 
		if( !dfn[v] ) trajin(v), low[x] = min( low[x], low[v] ) ;
		else if( !col[v] ) low[x] = min( low[x], dfn[v] ) ;
	}
	if( dfn[x] == low[x] ) { ++ idnex ; while( st[top + 1] != x ) col[st[top --]] = idnex ; }
} 
bool check( int w, int fl ) {
	memset( head, 0, sizeof(head) ), cnt = 0, top = 0, idnex = 0, num = 0 ;
	memset( dfn, 0, sizeof(dfn) ), memset( low, 0, sizeof(low) ), memset( col, 0, sizeof(col) ) ;
	rep( i, 1, m ) if( s[i].t > w ) add( i + m, i ) ; // i + m i  
	idnum = m + m ;
	rep( x, 1, n ) {
		int bef = 0 ; if( G[x].size() < 2 ) continue ; 
		for( int i = 0; i < G[x].size(); ++ i ) {
			node &k = G[x][i] ; k.Id = ++ idnum, add( idnum, k.id ) ;// 1 id  0
			if( bef ) add( idnum, bef ), add( k.id + m, bef ) ; bef = idnum ; 
		}
		int lef = 0 ;
		for( int i = G[x].size() - 1; i >= 0; -- i ) {
			node &k = G[x][i] ; k.Id = ++ idnum, add( idnum, k.id ) ;
			if( lef ) add( idnum, lef ), add( k.id + m, lef ) ; lef = idnum ; 
		}
	}
	rep( x, 1, n ) {
		int bef = 0, dc = 0 ; if( V[x].size() < 2 ) continue ;
		for( int i = 0; i < V[x].size(); ++ i ) {
			node &k = V[x][i] ; if( k.c != dc ) dc = k.c, bef = 0 ;
			k.Id = ++ idnum, add( idnum, k.id + m ) ;
			if( bef ) add( idnum, bef ), add( k.id, bef ) ; bef = idnum ;
		}
		int lef = 0 ; dc = 0 ;
		for( int i = V[x].size() - 1; i >= 0; -- i ) {
			node &k = V[x][i] ; if( k.c != dc ) dc = k.c, lef = 0 ;
			k.Id = ++ idnum, add( idnum, k.id + m ) ;
			if( lef ) add( idnum, lef ), add( k.id, lef ) ; lef = idnum ;
		}
	}
	rep( i, 1, idnum ) if( !dfn[i] ) trajin(i) ;
	rep( i, 1, m ) if( col[i] == col[i + m] ) return 0 ;
	if( fl ) {
		puts("Yes"), top = 0 ; 
		rep( i, 1, m ) if( col[i] > col[i + m] ) st[++ top] = s[i].id ; 
		printf("%d %d\n", w, top ) ;
		rep( i, 1, top ) printf("%d ", st[i] ) ;
	}
	return 1 ; 
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, m ) s[i].u = gi(), s[i].v = gi(), s[i].c = gi(), s[i].t = gi(), s[i].id = i ; 
	sort( s + 1, s + m + 1, cmp ) ;
	rep( i, 1, m ) {
		G[s[i].u].pb((node){ i, 0, 0 }), G[s[i].v].pb((node){ i, 0, 0 }) ;
		V[s[i].u].pb((node){ i, s[i].c, 0 }), V[s[i].v].pb((node){ i, s[i].c, 0 }) ;
	}
	int l = 0, r = 1000000001, ans = 0 ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ; 
		if( check(mid, 0) ) ans = mid, r = mid - 1 ;
		else l = mid + 1 ; 
	}
	if( !check(ans, 1) ) puts("No") ;
	return 0 ;
}