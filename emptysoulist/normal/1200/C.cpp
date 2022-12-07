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
int gcd( int x, int y ) {
	if( x == 0 ) return y ; 
	return gcd( y % x, x ) ;
}
int n, m, q ; 
signed main()
{
	n = read(), m = read(), q = read() ; 
	/*
	int k = gcd( 360, n ), t = gcd( 360, m ) ;
	int kk = n / k, tt = m / t ;
	int wh = gcd( t, k ) ;
	int g = k / wh, p = t / wh ; 
	g = g * kk, p = p * tt ;
	int op1, op2, x, y, ck1, ck2 ; 
	rep( i, 1, q ) {
		op1 = read(), x = read(), 
		op2 = read(), y = read() ; 
		if( op1 == 1 ) ck1 = ( x - 1 ) / g ;
		else ck1 = ( x - 1 ) / p ;
		if( op2 == 1 ) ck2 = ( y - 1 ) / g ; 
		else  ck2 = ( y - 1 ) / p ;
		if( ck1 == ck2 ) puts("YES");
		else puts("NO");
	}*/
	int gd = gcd( n, m ) ;
	int g = n / gd, p = m / gd ;
	int op1, op2, x, y, ck1, ck2 ; 
	rep( i, 1, q ) {
		op1 = read(), x = read(), 
		op2 = read(), y = read() ; 
		if( op1 == 1 ) ck1 = ( x - 1 ) / g ;
		else ck1 = ( x - 1 ) / p ;
		if( op2 == 1 ) ck2 = ( y - 1 ) / g ; 
		else  ck2 = ( y - 1 ) / p ;
		if( ck1 == ck2 ) puts("YES");
		else puts("NO");
	}
	return 0;
}