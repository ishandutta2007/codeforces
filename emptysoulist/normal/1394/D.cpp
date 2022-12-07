#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
#define pb push_back
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
const int inf = 1e15 + 7 ;
int n, cnt, w[N], h[N], head[N], f[N][2] ; 
struct E {
	int to, next ; 
} e[N << 1] ;
void add(int x, int y) {
	e[++ cnt] = (E){y, head[x]}, head[x] = cnt,
	e[++ cnt] = (E){x, head[y]}, head[y] = cnt ; 
}
vector<int> st[N] ; 
void Dfs(int x, int fa) {
	int sum = 0, a = 0, b = 0 ; 
	Next( i, x ) {
		int v = e[i].to ; if( v == fa ) continue ; 
		Dfs(v, x) ; 
		if( h[v] == h[x] ) st[x].pb(f[v][1] - f[v][0]), sum += f[v][0], ++ a ; 
		else if( h[v] > h[x] ) ++ b, sum += f[v][1] ;
		else ++ a, sum += f[v][0] ; 
	}
	sort(st[x].begin(), st[x].end()) ;
	for(re int i = 0; i <= st[x].size(); ++ i) {
		f[x][0] = min( f[x][0], sum + max(a, b + (x != 1)) * w[x] ) ;
		f[x][1] = min( f[x][1], sum + max(a + (x != 1), b) * w[x] ) ; 
		-- a, ++ b ;
		if( i < st[x].size() ) sum += st[x][i] ; 
	}
}
signed main()
{
	n = gi() ; int x, y ; 
	rep( i, 1, n ) w[i] = gi() ; 
	rep( i, 1, n ) h[i] = gi() ; 
	rep( i, 2, n ) x = gi(), y = gi(), add(x, y) ; 
	memset( f, 63, sizeof(f) ) ;
	Dfs(1, 1) ; 
	cout << min(f[1][0], f[1][1]) << endl ; 
	return 0 ;
}