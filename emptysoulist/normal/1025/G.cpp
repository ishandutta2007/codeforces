#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 1e9 + 7 ;  
const int N = 500 + 5 ; 
int n, cnt[N] ;  
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int f(int x) {
	return (fpow(2, x) - 1) ;
}
signed main()
{
	n = gi() ; int x ; 
	rep( i, 1, n ) {
		x = gi() ; 
		if( x != -1 ) ++ cnt[x] ; 
	}
	int Ans = f(n - 1) ;
	rep( i, 1, n ) Ans = (Ans - f(cnt[i]) + P) % P ; 
	cout << Ans << endl ; 
	return 0 ;
}