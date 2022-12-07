#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 1e5 + 5 ; 
int T, len1, len2;
char a[N], b[N] ; 
signed main()
{
	T = read() ;
	while( T-- ) {
		scanf("%s%s", a + 1, b + 1 ) ;
		len1 = strlen(a + 1), len2 = strlen(b + 1) ;
		int w = 0, k = 0 ;
		for( re int i = len2; i > 0; -- i ) 
		if( b[i] == '1' ) { w = i; break ; }
		for( re int i = ( len1 - ( len2 - w ) ); i > 0; -- i ) {
			if( a[i] == '1' ) { k = i; break; }
		}
		printf("%d\n", ( len1 - k - ( len2 - w ) ) ) ;
	}
	return 0;
}