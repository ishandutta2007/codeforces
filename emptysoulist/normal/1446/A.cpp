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
const int N = 2e5 + 5 ; 
int n, W, a[N] ; 
vector<int> ans ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi(), W = gi() ; 
		int lim = (W + 1) / 2, C = 0 ; 
		rep( i, 1, n ) {
			a[i] = gi() ; 
			if( a[i] < lim && C < lim ) C += a[i], ans.push_back(i) ;
			else if( a[i] >= lim && a[i] <= W ) {
				ans.clear(), ans.push_back(i), C = a[i] ; 
			}
		}
		if( C < lim || !ans.size() ) puts("-1") ; 
		else {
			printf("%lld\n", (int)ans.size() ) ;
			for(int z : ans) printf("%lld ", z ) ; puts("") ; 
		}
		ans.clear() ; 
	}
	return 0 ;
}