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
int a[N] ;
void Add( int x ) {
	
}
signed main()
{
	int n = read(), x = read(), y = read() ; 
	rep( i, 1, n ) a[i] = read() ; 
	int ans = 0 ; 
	rep( i, 1, n ) {
		int flag = 1 ; 
		for( re int j = max( 1, i - x ); j < i; ++ j ) {
			if( a[j] <= a[i] ) {
				flag = 0 ; break ; 
			}	
		}
		for( re int j = min( n, i + y ); j > i; -- j ) {
			if( a[j] <= a[i] ) {
				flag = 0; break ;
			}
		}
		if( flag ) {
			ans = i; break ;
		}
	}
	printf("%d\n", ans ) ;
	return 0;
}