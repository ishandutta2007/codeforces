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
int n, k, c[N][N], ln1[N], ln2[N], sn1[N], sn2[N] ;
int sum1[N][N], sum2[N][N], dp1[N][N], dp2[N][N], Ans;
char s[N][N] ;
signed main()
{
	n = read(), k = read() ;
	rep( i, 1, n ) scanf("%s", s[i] + 1 ) ;
	rep( i, 1, n ) rep( j, 1, n ) c[i][j] = ( s[i][j] == 'W' ? 0 : 1 ) ;
	rep( i, 1, n ) {
		int flag1 = 0, flag2 = 0 ; 
		rep( j, 1, n ) flag1 = max( flag1, c[i][j] ), flag2 = max( flag2, c[j][i] ) ;
		ln1[i] = flag1 ^ 1, ln2[i] = flag2 ^ 1 ; 
		sn1[i] = sn1[i - 1] + ln1[i]; sn2[i] = sn2[i - 1] + ln2[i] ;
	}
	rep( i, 1, n ) rep( j, 1, n ) {
		sum1[i][j] = sum1[i][j - 1] + c[i][j] ;
		sum2[i][j] = sum2[i - 1][j] + c[i][j] ;
	}
	for( int i = 1; i <= n; ++ i )
		for( int j = 1; j <= n; ++ j ) {
			int k1 = sum1[i][n] + sum1[i][j - 1] - sum1[i][j + k - 1] ; 
			int k2 = sum2[n][j] + sum2[i - 1][j] - sum2[i + k - 1][j] ; 
			dp1[i][j] = ( k1 == 0 ) ;
			dp2[i][j] = ( k2 == 0 ) ;
			dp1[i][j] = dp1[i - 1][j] + dp1[i][j] ;
			dp2[i][j] = dp2[i][j - 1] + dp2[i][j] ;
		}
	for( int i = 1; i <= n - k + 1; ++ i ) {
		for( int j = 1; j <= n - k + 1; ++ j ) {
			int line = sn1[n] - sn1[i + k - 1] + sn1[i - 1] ;
			int line2 = sn2[n] - sn2[j + k - 1] + sn2[j - 1] ;
			line += ( dp1[i + k - 1][j] - dp1[i - 1][j] ) ;
			line2 += ( dp2[i][j + k - 1] - dp2[i][j - 1] ) ;
			Ans = max( Ans, line + line2 ) ;
		}
	}
	printf("%d\n", Ans ) ;
	return 0;
}