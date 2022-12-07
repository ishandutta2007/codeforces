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
char s[N] ;
int n, book[20] ;
signed main()
{
	n = read() ;
	scanf("%s", s + 1 ) ;
	rep( i, 1, n ) {
		if( s[i] == 'L' ) {
			for( int j = 0; j <= 9; ++ j ) {
				if( !book[j] ) {
					book[j] = 1 ;
					break; }
			}
		}
		else if( s[i] == 'R' ) {
			for( int j = 9; j >= 0; -- j ) {
				if( !book[j] ) {
					book[j] = 1 ;
					break; }
			}
		}
		else {
			book[s[i] - '0'] = 0 ;
		}
	}
	rep( i, 0, 9 ) printf("%d", book[i] ) ;
	return 0;
}