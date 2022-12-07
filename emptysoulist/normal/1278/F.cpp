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
const int P = 998244353 ; 
const int N = 5000 + 5 ; 
int n, m, k, S[N][N], fac[N], C[N] ; 
int fpow( int x, int k ) {
	int ans = 1, base = x ; 
	while( k ) {
		if( k & 1 ) ans = ans * base % P ; 
		base = base * base % P, k >>= 1 ; 
	} return ans ; 
}
signed main()
{
	n = gi(), m = gi(), k = gi() ; 
	C[0] = fac[0] = S[0][0] = 1 ; //Cn[i] = n!/i!(n-i)!
	//Cn[i-1]= n!/(i-1)!(n-i+1)!
	//Cn[i] = Cn[i - 1] /i * (n-i+1)  
	rep( i, 1, k ) rep( j, 1, k ) S[i][j] = ( S[i - 1][j - 1] + S[i - 1][j] * j % P ) % P ; 
	rep( i, 1, k ) fac[i] = fac[i - 1] * i % P, C[i] = C[i - 1] * ( n - i + 1 ) % P * fpow( i, P - 2 ) % P ;
	int Ans = 0 ; 
	rep( i, 1, k ) Ans = ( Ans + fac[i] * C[i] % P * S[k][i] % P * fpow( m, P - 1 - i ) % P ) % P ; 
	printf("%lld\n", Ans ) ;
	return 0 ;
}