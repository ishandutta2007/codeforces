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
const int N = 5e5 + 5 ; 
const int P = 1e9 + 7 ; 
const int M = 65 ; 
int n, a[N], fac[M] ; 
signed main()
{
	int T = gi() ; 
	while( T-- ) {
		n = gi() ; 
		rep( i, 1, n ) {
			a[i] = gi() ; 
			rep( j, 0, 60 ) 
			if((a[i] >> j) & 1) ++ fac[j] ; 
		}
		int ans = 0 ; 
		rep( i, 1, n ) {
			int f1 = 0, f2 = 0 ; 
			rep( j, 0, 60 ) {
				if((a[i] >> j) & 1) {
					int d1 = (1ll << j) % P * fac[j] % P ; 
					int d2 = (1ll << j) % P * n % P ; 
					f1 = (f1 + d1) % P ; 
					f2 = (f2 + d2) % P ; 
				}
				else {
					int d2 = (1ll << j) % P * fac[j] % P ; 
					f2 = (f2 + d2) % P ; 
				}
			}
			ans = (ans + f1 * f2) % P ; 
		}
		printf("%lld\n", ans ) ; 
		rep( j, 0, 60 ) fac[j] = 0 ; 
	}
	return 0 ;
}