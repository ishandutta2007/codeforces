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
const int N = 100 + 5 ; 
int n, c[N] ; 
int q, flag ; 
vector<vector<int>> d, opt[N] ; 
void solve(int x) {
	d.clear() ; 
//	printf("now case %d %d\n", x, flag ) ; 
//	rep( i, 1, n ) printf("%d ", c[i] ) ; puts("") ;  
	if( flag == 1 ) {
		if( c[n - x + 1] == x ) return ; 
		vector<int> f ; f.clear() ; 
		for(re int i = 1; i <= n; ++ i ) {
			if( c[i] < x ) {
				if( !f.empty() ) d.pb(f) ; 
				f.clear(), f.pb(c[i]), d.pb(f), f.clear() ;
			}
			else if( c[i] == x ) {
				if( !f.empty() ) d.pb(f) ;
				f.clear(), f.pb(c[i]) ; 
			}
			else f.pb(c[i]) ;  
		}
	}
	else {
		if( c[x] == x ) return ; 
		vector<int> f ; f.clear() ; 
		for(re int i = 1; i <= n; ++ i) {
			if( c[i] < x ) f.pb(c[i]), d.pb(f), f.clear() ;
			else if( c[i] == x ) f.pb(c[i]), d.pb(f), f.clear() ; 
			else f.pb(c[i]) ; 
		}
		if( !f.empty() ) d.pb(f) ; 
	}
	opt[++ q] = d ; 
	reverse(d.begin(), d.end()) ; 
	int top = 0 ;
	for(vi z : d) {
		for(int u : z) c[++ top] = u ; 
	}
	flag ^= 1 ; 
}
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) c[i] = gi() ; 
	flag = 0 ;  
	if( c[n] == 1 ) flag = 1 ; 
	rep( i, 1, n ) solve(i) ; 
	if( flag == 1 && n != 1 ) {
		vi f ; f.clear() ; opt[++ q] ;
		rep( i, 1, n ) f.pb(c[i]), opt[q].pb(f), f.clear() ;
	}
	printf("%d\n", q ) ; 
	rep( i, 1, q ) {
		printf("%d ", opt[i].size() ) ;
		for(vi u : opt[i]) printf("%d ", u.size() ) ; puts("") ; 
	}
	return 0 ;
}