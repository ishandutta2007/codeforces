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
const int N = 4e5 + 5 ; 
const int inf = 1e9 + 7 ;  
const int Inf = 1e8 + 7 ; 
int n, A[N], w[N], cnt = 1, m, rem, bef = 1 ; 
char s[N], a[N] ; 
struct Suffix {
	int ch[30], lef, lk, len ; 
} t[N] ;
int node( int l, int len ) {
	t[++ cnt].lef = l, t[cnt].len = len, t[cnt].lk = 1 ; return cnt ; 
}
void insert( int x ) {
	++ rem, ++ m, s[x] = s[x] - 'a' ; int u = s[x], lst = 1 ; 
	while( rem ) {
		while( rem > t[t[bef].ch[s[m - rem + 1]]].len ) 
		rem -= t[bef = t[bef].ch[s[m - rem + 1]]].len ;
		int &d = t[bef].ch[s[m - rem + 1]], c = s[t[d].lef + rem - 1] ;
		if( !d || u == c ) {
			t[lst].lk = bef, lst = bef ; 
			if( !d ) d = node( m - rem + 1, inf ) ;
			else return ; 
		}
		else {
			int np = node( t[d].lef, rem - 1 ) ; 
			t[np].ch[u] = node(m, inf), t[np].ch[c] = d,
			t[d].lef += ( rem - 1 ), t[d].len -= ( rem - 1 ), 
			t[lst].lk = d = np, lst = d ; 
		}
		( bef == 1 ) ? -- rem : bef = t[bef].lk ; 
	}
}
int Ans = 0 ;
void dfs( int x, int fa, int dep ) {
	if( t[x].len >= Inf ) t[x].len = n - t[x].lef ; int fl = 0 ;
	rep( i, 0, 26 ) if( t[x].ch[i] ) dfs( t[x].ch[i], x, dep + t[x].len ), w[x] += w[t[x].ch[i]], fl = 1 ;
	if( !fl ) w[x] = A[dep + t[x].len] ;
	Ans = max( Ans, ( dep + t[x].len ) * w[x] ) ;
}
signed main()
{
	n = gi(), scanf("%s", s + 1 ), scanf("%s", a + 1 ) ;
	rep( i, 1, n ) A[i] = ( a[i] - '0' ) ^ 1 ; 
	s[++ n] = 'z' + 1, t[0].len = inf ; 
	rep( i, 1, n ) insert(i) ;
	dfs( 1, 0, 0 ), cout << Ans << endl ;
	return 0 ;
}