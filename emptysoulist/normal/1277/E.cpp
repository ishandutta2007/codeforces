#include<bits/stdc++.h>
using namespace std ;
#define Next2( i, x ) for( register int i = Head[x]; i; i = s[i].next )
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define re register
#define int long long
inline int gi() {
	int cn = 0, flus = 1 ; char cc = getchar() ;
	while( cc > '9' || cc < '0' ) { if( cc == '-' ) flus = -flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' ) cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ; 
}
const int N = 4e5 + 5 ; 
const int M = 5e5 + 5 ; 
int n, m, cnt, idnex, head[N], dfn[N], low[N], Ans ;
int st[N], top, Col, sz[N], Head[N], vis[N], St, Ed ;
struct E {
    int to, next ; 
} e[M << 1], s[N << 1] ;
void add( int x, int y ) {
    e[++ cnt] = (E){ y, head[x] }, head[x] = cnt,
    e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ;
}
void Add( int x, int y ) {
    s[++ cnt] = (E){ y, Head[x] }, Head[x] = cnt,
    s[++ cnt] = (E){ x, Head[y] }, Head[y] = cnt ;
}
void tarjan( int x, int fa ) {
    dfn[x] = low[x] = ++ idnex, st[++ top] = x ;
    Next( i, x ) {
        int v = e[i].to ; 
        if( !dfn[v] ) {
            tarjan( v, x ) ;
            low[x] = min( low[x], low[v] ) ;
            if( low[v] >= dfn[x] ) {
                ++ Col ; Add( Col, x ), Add( Col, v ) ;
                while( st[top] != v ) {
                    Add( Col, st[top] ), -- top ; 
                } -- top ; 
            }
        }
        else low[x] = min( low[x], dfn[v] ) ;
    }
}
void dfs2( int x, int fa ) {
    if( x <= n ) sz[x] = 1 ; 
	if( x == Ed ) vis[x] = 1 ; 
    Next2( i, x ) {
        int v = s[i].to ; if( v == fa ) continue ;
        dfs2( v, x ) ;
		if( ( x != St ) || ( vis[v] == 0 ) ) sz[x] += sz[v] ;
		if( x != St ) vis[x] |= vis[v] ;
    }
    if( x == St ) {
    	Ans = 1ll * ( sz[St] - 1 ) * ( sz[Ed] - 1 ) ; 
    	printf("%I64d\n", Ans ) ;
	}
}
void init() {
	rep( i, 1, Col ) vis[i] = sz[i] = dfn[i] = low[i] = Head[i] = head[i] = 0 ;
	top = idnex = cnt = 0 ;
}
signed main() {
	int T = gi() ;  
	while( T-- ) {
	    n = gi(), m = gi(), St = gi(), Ed = gi() ; int x, y ; 
	    rep( i, 1, m ) x = gi(), y = gi(), add( x, y ) ;
	    cnt = 0, Col = n ; 
	    rep( i, 1, n ) if( !dfn[i] ) tarjan( i, i ) ;
	    dfs2( St, St ) ;
	    init() ; 
	}
    return 0 ; 
}