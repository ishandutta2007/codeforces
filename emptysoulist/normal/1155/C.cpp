#include<bits/stdc++.h>
using namespace std;
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 3e5 + 5 ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
int n, m, a[N], s[N], Ans ; 
int gcd( int a, int b ) {
	if( b == 0 ) return a ; 
	return gcd( b, a % b ) ;
}
signed main()
{
	n = read(), m = read() ;
	int s = 0 ;
	rep( i, 1, n ) {
		a[i] = read() ; 
		if( i > 1 ) {
			s = a[i] - a[i - 1] ; 
			if( !Ans ) Ans = s ; 
			else Ans = gcd( Ans, s ) ; 
		}
	}
	int fr = a[1] ; 
	int x, wh = 0 ;
	rep( i, 1, m ) {
		x = read() ; 
		if( Ans % x == 0 ) wh = i; 
	}
	if( wh ) printf("YES\n%I64d %I64d\n", fr, wh ) ; 
	else puts("NO");
	return 0;
}