#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int P = 1e9 + 7 ; 
const int M = 5e5 + 5 ; 
const int N = 1000 + 5 ; 
int m, n, p[M / 10], top, use[N], tot ;
bool isp[M] ; 
void init() {
	int maxn = M - 5 ; 
	for( re int i = 2; i <= maxn; ++ i ) {
		if( !isp[i] ) p[++ top] = i ; 
		for( re int j = 1; j <= top && p[j] * i <= maxn; ++ j ) {
			isp[i * p[j]] = 1 ;
			if( i % p[j] == 0 ) break ; 
		}
	}
}
void Get( int x ) {
	int cnt = sqrt(x), u = x ;
	for( re int i = 1; p[i] <= sqrt(u); ++ i ) {
		if( u % p[i] == 0 ) {
			use[++ tot] = p[i] ;
			while( u % p[i] == 0 ) u /= p[i] ;
		}
	}
	if( u != 1 ) use[++ tot] = u ; 
}
int fpow( int x, int k ) {
	int ans = 1, base = x % P ;
	while( k ) {
		if( k & 1 ) ans = ( ans * base ) % P ; 
		base = ( base * base ) % P, k >>= 1 ;
	}
	return ans % P ; 
}
signed main()
{
	m = gi(), n = gi() ; 
	init(), Get(m) ; int Ans = 1 ;
	for( re int i = 1; i <= tot; ++ i ) {
		int u = use[i], d = use[i] ; 
		while( u <= n ) {
			Ans = ( Ans * fpow( u, ( n / u ) - ( ( n / d ) / u ) ) % P ) % P ;
			if( u > n / d ) break ; 
			u = ( u * d ) ;
		}
	}
	//10 3
	//
	printf("%I64d\n", Ans % P ) ;
	return 0 ;
}