#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define inf 100000
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
int n ; 
signed main()
{
	int T = read() ;
	while( T-- ) {
		n = read() ;
		int Xl = -inf, Xr = inf, Yr = inf, Yl = -inf ; 
		int x, y, f1, f2, f3, f4 ;
		rep( i, 1, n ) {
			x = read(), y = read(), f1 = read(), f2 = read(), f3 = read(), f4 = read() ;
			if( f1 == 0 ) Xl = max( Xl, x ) ;
			if( f2 == 0 ) Yr = min( Yr, y ) ; 
			if( f3 == 0 ) Xr = min( Xr, x ) ;
			if( f4 == 0 ) Yl = max( Yl, y ) ;
		}
		if( Xl > Xr || Yl > Yr ) puts("0") ; 
		else {
			printf("1 ") ;
			printf("%d %d", Xl, Yl ) ;
			puts("");
		}
	}
	return 0;
}