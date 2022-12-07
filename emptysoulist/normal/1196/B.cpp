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
const int N = 2e5 + 5 ;
int n, k, a[N], rev[N] ;
signed main()
{
	int T = read() ;
	while( T-- ) {
		n = read(), k = read() ; int cnt = 0 ;
		rep( i, 1, n ) {
			a[i] = read() % 2 ;
			if( a[i] == 1 ) rev[++ cnt] = i ;
		}
		if( cnt < k || ( cnt - k ) & 1 ) puts("NO");
		else {
			puts("YES");
			for( re int i = 1; i < k; ++ i ) printf("%d ", rev[i] ) ;
			printf("%d\n", n ) ; 
		}
	} 
	return 0;
}