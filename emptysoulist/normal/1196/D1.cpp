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
const int N = 2000 + 5 ;
int n, k, a[N] ;
char s[N] ;
signed main()
{
	int T = read() ;
	while( T-- ) {
		n = read(), k = read() ; int Ans = n + 1 ;
		scanf("%s", s ) ;
		rep( i, 1, n ) {
			int to = i - 1 ;
			if( s[to] == 'R' ) a[i] = 0 ;  
			if( s[to] == 'G' ) a[i] = 1 ;
			if( s[to] == 'B' ) a[i] = 2 ;
			
		}
		rep( i, 1, n ) {
			if( i + k > n + 1 ) break ; 
			int fr = i, ans1 = 0, ans2 = 0, ans3 = 0 ;
			int a1 = 0, a2 = 1, a3 = 2 ; 
			for( re int j = 0; j < k; ++ j ) {
				if( a[i + j] != ( a1 + j ) % 3 ) ++ ans1 ;
				if( a[i + j] != ( a2 + j ) % 3 ) ++ ans2 ;
				if( a[i + j] != ( a3 + j ) % 3 ) ++ ans3 ; 
			}
			Ans = min( Ans, min( ans1, min( ans2, ans3 ) ) ) ;
		}
		printf("%d\n", Ans ) ;
	}
	return 0;
}