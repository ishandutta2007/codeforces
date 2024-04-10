// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int mod = 1e9 + 7 ;
const int mod2 = 1e9 + 9 ;
const int ha = 233 ; 
const int ha2 = 377 ;
const int N = 1e6 + 5 ;
int n, cnt, r, inv[N], inv2[N] ;
char out[N], s[N] ; 
signed main()
{
	n = read() ; int Maxa = 1e6 ; inv[0] = 1, inv2[0] = 1 ; 
	rep( i, 1, Maxa ) inv[i] = ( inv[i - 1] * ha ) % mod, inv2[i] = ( inv2[i - 1] * ha2 ) % mod ; 
	int w = 0 ;
	rep( i, 1, n ) {
		scanf("%s", s + 1 ) ;
		r = strlen( s + 1 ) ; 
		int hash1 = 0, hash2 = 0 ;
		int hash12 = 0, hash22 = 0 ;
		int k = min( r, cnt ), ans = 0 ;
		rep( i, 1, k ) {
			hash1 = ( hash1 * ha + s[i] ) % mod ;
			hash2 = ( hash2 + out[cnt - i + 1] * inv[i - 1] ) % mod ;
			hash12 = ( hash12 * ha2 + s[i] ) % mod ;
			hash22 = ( hash22 + out[cnt - i + 1] * inv2[i - 1] ) % mod ;
			if( hash1 == hash2 && hash12 == hash22 ) ans = i ;
		}
		for( int i = ans + 1; i <= r; ++ i ) out[++ cnt] = s[i] ;
		w ^= 1 ;
	}
	rep( i, 1, cnt ) printf("%c", out[i] ) ;
	return 0;
}