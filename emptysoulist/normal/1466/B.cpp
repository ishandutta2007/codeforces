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
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 3e5 + 5 ; 
int n, a[N], f[N] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 1, n ) 
			if(a[i - 1] >= a[i]) ++ a[i] ; 
		int lim = 2 * n + 1, ans = 0 ; 
		rep( i, 1, n ) f[a[i]] = 1 ; 
		rep( i, 1, lim ) if(f[i]) ++ ans ; 
		cout << ans << endl ; 
		rep( i, 0, lim ) f[i] = 0 ; 
		rep( i, 1, n ) a[i] = 0 ; 
		
	}
	return 0 ;
}