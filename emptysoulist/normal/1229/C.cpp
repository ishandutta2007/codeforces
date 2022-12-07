#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, m, cnt, top, Ans, in[N], out[N] ; 
vi G[N] ; 
signed main()
{
	n = gi(), m = gi() ; int x, y ; 
	rep( i, 1, m ) {
		x = gi(), y = gi() ; 
		if(x > y) swap(x, y) ; 
		++ in[x], ++ out[y], G[x].pb(y) ; 
	} cnt = sqrt(m) ; 
	rep( i, 1, n ) Ans += in[i] * out[i] ; 
	cout << Ans << endl ; 
	int q = gi() ; 
	rep( i, 1, q ) {
		x = gi() ; Ans -= in[x] * out[x] ; 
		for(int v : G[x]) {
			Ans += (out[v] - in[v] - 1) ; 
			G[v].push_back(x), -- out[v], ++ in[v] ; 
		} 
		G[x].clear() ; out[x] = in[x] + out[x], in[x] = 0 ; 
		printf("%lld\n", Ans ) ; 
	}
	return 0 ;
}