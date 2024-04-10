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
const int N = 2000 + 5 ; 
const int M = 1e6 + 5 ; 
int n, m, a[N], b[N], c[N], d[N] ;
int Mx, Ans[M] ;  
signed main()
{
	n = gi(), m = gi() ;
	rep( i, 1, n ) a[i] = gi(), b[i] = gi() ;
	rep( i, 1, m ) {
		c[i] = gi(), d[i] = gi() ;
		Mx = max( Mx, d[i] ) ; 
	}
	++ Mx ; 
	rep( i, 1, n ) {
		
		rep( j, 1, m ) {
			if( d[j] >= b[i] ) {
				int cd = d[j] - b[i] ;
				Ans[cd] = max( Ans[cd], c[j] + 1 - a[i] ) ;
			}
		}
	}
	
	drep( i, 0, Mx ) 
		Ans[i] = max( Ans[i], Ans[i + 1] ) ;
	int ans = Mx + 1 ;
	rep( i, 0, Mx ) ans = min( ans, i + Ans[i] ) ;
	cout << ans << endl ; 
	//b[i] + y  
	//max(mxc[b[i] + y] - a[i], 0)  m  
	return 0 ;
}