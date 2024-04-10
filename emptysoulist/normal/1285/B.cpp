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
const int inf = 1e15 + 7 ; 
const int N = 1e5 + 5 ; 
int a[N], sum[N], Mi ; 
int L, R ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		int n = gi(), Ans = 0, fl = 0, Mi2 = inf ; Mi = 0 ; 
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 1, n ) {
			sum[i] = sum[i - 1] + a[i] ; 
			if( fl || ( i != n ) ) Ans = max( Ans, sum[i] - Mi ) ;
			else Ans = max( Ans, sum[i] - Mi2 ) ;
			if( sum[i] <= Mi ) Mi2 = Mi, Mi = sum[i], fl = 1 ; 
			else if( sum[i] <= Mi2 ) Mi2 = sum[i] ; 
		}
		if( Ans < sum[n] ) printf("Yes\n") ;
		else puts("No") ; 
	}
	return 0 ;
}