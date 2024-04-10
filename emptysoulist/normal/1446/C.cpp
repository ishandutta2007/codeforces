#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define pb push_back
#define vi vector<int> 
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
vector<int> A ; 
int n, a[N] ; 
int get(int x) {
	drep( i, 0, 30 ) if( (1 << i) & x ) return i ; 
	return -1 ; 
}
int solve(vi S) {
	if( S.empty() ) return 0 ; 
	vi t[32] ; int nxt[32], pre[32] ; 
	rep( i, 0, 31 ) t[i].clear() ; 
//	printf("now solve\n") ;
	for(int z : S) {
	//	printf("QAQ %d\n", z ) ; 
		int h = get(z) ;
		int o = (h == -1) ? 0 : (1 << h) ;  
	//	printf("qwq %d %d\n", z, h ) ;
		t[h + 1].pb(z ^ o) ; 
	}
	rep( i, 0, 31 ) nxt[i] = 0, pre[i] = 0 ;
	drep( i, 0, 30 ) nxt[i] = nxt[i + 1] + (!t[i].empty()) ; 
	pre[0] = !t[0].empty() ; 
	rep( i, 1, 31 ) pre[i] = (pre[i - 1] | (!t[i].empty())) ; 
	int ans = (!t[0].empty()) + nxt[1] ; 
	for(re int i = 1; i <= 30; ++ i) {
		if( !t[i].empty() ) ans = max( ans, solve(t[i]) + nxt[i + 1] + pre[i - 1] ) ; 
	}
	return ans ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi(), A.pb(a[i]) ; 
	sort(A.begin(), A.end()) ;
	int ans = n - solve(A) ; 
	cout << ans << endl ; 
	return 0 ;
}