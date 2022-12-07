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
const int N = 3e5 + 5 ; 
const int M = 100 + 5 ; 
int n, w[N], val[N], bit[N], Sum[M] ; 
int Get(int x) { 
	int ans = 0 ;
	rep( i, 0, 62 ) if((x >> i) & 1) ans = i ;
	return ans ;  
}
signed main()
{
	n = gi() ; int S = 0, ans = 0 ;
	rep( i, 1, n ) 
		val[i] = gi(), w[i] = gi(), bit[i] = Get(w[i]), S += val[i] ; 
	if( S > 0 ) rep( i, 1, n ) val[i] = -val[i] ;
	rep( i, 1, n ) Sum[bit[i]] += val[i] ; 
	rep( k, 0, 62 ) {
		if( Sum[k] >= 0 ) continue ; 
		ans |= (1ll << k) ;
		rep( i, 1, n ) if((w[i] >> k) & 1) Sum[bit[i]] -= val[i] * 2, val[i] = -val[i] ; 
	}
	cout << ans << endl ; 
	return 0 ;
}