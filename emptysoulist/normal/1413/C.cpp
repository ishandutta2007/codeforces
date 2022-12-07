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
const int inf = 1e15 ; 
const int N = 2e5 + 5 ; 
const int M = 1e6 + 5 ; 
int n, a[N], b[N], cnt[N] ; 
int top, Col, f[N][10] ; 
struct node {
	int c, w ; 
} g[M] ;
bool cmp(node x, node y) {
	return x.w < y.w ; 
}
void Add(int x) {
	++ cnt[g[x].c] ; 
	if( cnt[g[x].c] == 1 ) ++ Col ; 
}
void Del(int x) {
	-- cnt[g[x].c] ;
	if( !cnt[g[x].c] ) -- Col ;  
}
signed main()
{
	rep( i, 1, 6 ) a[i] = gi() ; 
	n = gi() ; 
	rep( i, 1, n ) b[i] = gi() ; 
	sort(b + 1, b + n + 1) ;
	sort(a + 1, a + 7) ;
	rep( i, 1, n ) {		
		rep( j, 1, 6 ) 
			g[++ top] = (node){ i, b[i] - a[j] } ; 
	}
	sort(g + 1, g + top + 1, cmp) ; 
	int l = 1 ; Col = 0 ; int Ans = inf ;
	rep( i, 1, top ) {
		Add(i) ; 
		while( l < i && (cnt[g[l].c] > 1) && (Col == n) ) Del(l), ++ l ;
		if( Col == n ) Ans = min( Ans, g[i].w - g[l].w ) ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}