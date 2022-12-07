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
int a[10] ;
signed main()
{
	int T = read(), a, b, c ;
	while( T-- ) {
		a = read(), b = read(), c = read() ; 
		printf("%I64d\n", ( a + b + c ) / 2 ) ;
		
		
	} 
	return 0;
}