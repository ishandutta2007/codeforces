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
const int N = 1e3 + 5 ;
const int P = 1000000007 ; 
int a[N][N], h, w, r[N], c[N], flag ;
int fpow( int x, int k ) {
	int ans = 1, base = x ;
	while( k ) {
		if( k & 1 ) ans = ( ans * base ) % P ; 
		base = ( base * base ) % P, k >>= 1 ;
	}
	return ans % P ; 
}
signed main()
{
	h = gi(), w = gi() ; //a[h][w]
	rep( i, 1, h ) {
		r[i] = gi() ; 
		rep( j, 1, r[i] ) a[i][j] = 1 ;
		a[i][r[i] + 1] = 2 ; 
	}
	rep( i, 1, w ) {
		c[i] = gi() ; 
		rep( j, 1, c[i] ) {
			if( a[j][i] == 2 ) flag = 1 ; 
			a[j][i] = 1 ;
		}
		if( a[c[i] + 1][i] == 1 ) flag = 1 ; 
		a[c[i] + 1][i] = 2 ; 
	}
	if( flag ) printf("0\n") ; 
	else {
		int Count = 0 ;
		rep( i, 1, h ) {
			rep( j, 1, w ) {
				if( !a[i][j] ) ++ Count ; 
			}
		}
		printf("%I64d\n", fpow( 2, Count ) % P ) ;
	}
 	return 0;
}