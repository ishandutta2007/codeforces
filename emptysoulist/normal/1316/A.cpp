#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int T, n, m, a[N] ;  
signed main()
{
	T = gi() ;
	while( T-- ) {
		n = gi(), m = gi() ; int Sum = 0 ;
		rep( i, 1, n ) a[i] = gi(), Sum += a[i] ;
		cout << min( Sum, m ) << endl ; 
	}
	return 0 ;
}