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
const int P = 1e9 + 7 ; 
char s[N] ;
int dp[N], n ; 
int Get( int x ) {
	return dp[x] % P ; 
} 
signed main()
{
	scanf("%s", s + 1 ) ; n = strlen( s + 1 ) ;
	rep( i, 1, n ) if( s[i] == 'm' || s[i] == 'w' ){
		puts("0") ; exit(0) ;
	}
	int Ans = 1, befu = 0, befw = 0 ; 
	dp[0] = dp[1] = 1 ; 
	rep( i, 2, n ) dp[i] = ( dp[i - 1] + dp[i - 2] ) % P ; 
	rep( i, 1, n ) {
		if( s[i] != 'u' && befu ) Ans = ( Ans * Get(befu) ) % P, befu = 0 ;
		if( s[i] != 'n' && befw ) Ans = ( Ans * Get(befw) ) % P, befw = 0 ;
		if( s[i] == 'u' ) ++ befu ;
		if( s[i] == 'n' ) ++ befw ; 
	}
	Ans = ( Ans * Get(befu) ) % P, Ans = ( Ans * Get(befw) ) % P ; 
	printf("%I64d\n", Ans ) ;
	return 0 ;
}