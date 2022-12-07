#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define int long long
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, a[N], st[N], top, deg[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; int ans = 0 ; 
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 2, n ) {
			int x = gi(), y = gi() ; 
			++ deg[x], ++ deg[y] ; 
		}
		rep( i, 1, n ) ans += a[i] ; 
		rep( i, 1, n ) -- deg[i] ; top = 0 ; 
		rep( i, 1, n ) {
			while(deg[i]) -- deg[i], st[++ top] = a[i] ; 
		}
		sort(st + 1, st + top + 1) ; 
		printf("%lld ", ans ) ; 
		for(re int i = top; i >= 1; -- i) {
			ans += st[i] ; 
			printf("%lld ", ans ) ; 
		}
		puts("") ; 
	}
	return 0 ;
}