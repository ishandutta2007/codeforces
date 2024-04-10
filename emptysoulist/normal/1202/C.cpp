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
const int N = 2e5 + 5 ; 
char s[N] ;
int a[N], b[N], sum1[N], sum2[N], mi1[N], mx1[N], mi2[N], mx2[N], n, num, cnt ;  
signed main()
{
	int T = read() ; 
	while( T-- ) {
		scanf("%s", s + 1 ) ;
		n = strlen(s + 1), num = 0, cnt = 0 ;
		for( int i = 1; i <= n; ++ i ) {
			if( s[i] == 'W' ) a[++ num] = 1 ;
			if( s[i] == 'S' ) a[++ num] = -1 ; 
			if( s[i] == 'A' ) b[++ cnt] = -1 ; 
			if( s[i] == 'D' ) b[++ cnt] = 1 ; 
		}
		for( int i = 1; i <= num; ++ i ) sum1[i] = a[i] + sum1[i - 1], mi1[i] = min( sum1[i], mi1[i - 1] ), mx1[i] = max( sum1[i], mx1[i - 1] ) ;
		for( int i = 1; i <= cnt; ++ i ) sum2[i] = b[i] + sum2[i - 1], mi2[i] = min( sum2[i], mi2[i - 1] ), mx2[i] = max( sum2[i], mx2[i - 1] ) ; 
		int Ans = ( mx1[num] - mi1[num] + 1 ) * ( mx2[cnt] - mi2[cnt] + 1 ) ;
		int x = mx1[num] - mi1[num], y = mx2[cnt] - mi2[cnt] ; 
		//W
		int mx = 0, mi = 0, Mi, Mx, xx = x, yy = y ; 
		for( int i = num; i >= 1; -- i ) {
			mi = min( sum1[i] - 1, mi ), mx = max( sum1[i] - 1, mx ) ;
			Mi = min( mi, mi1[i] ), Mx = max( mx, mx1[i] ) ;
			xx = min( xx, Mx - Mi ) ;
		}
		Ans = min( Ans, ( xx + 1 ) * ( y + 1 ) ) ;
		xx = x, mx = 0, mi = 0 ;
		//S
		for( int i = num; i >= 1; -- i ) {
			mi = min( sum1[i] + 1, mi ), mx = max( sum1[i] + 1, mx ) ;
			Mi = min( mi, mi1[i] ), Mx = max( mx, mx1[i] ) ;
			xx = min( xx, Mx - Mi ) ;
		}
		Ans = min( Ans, ( xx + 1 ) * ( y + 1 ) ) ;
		//A
		mx = mi = 0 ; yy = y ; 
		for( int i = cnt; i >= 1; -- i ) {
			mi = min( sum2[i] - 1, mi ), mx = max( sum2[i] - 1, mx ) ;
			Mi = min( mi, mi2[i] ), Mx = max( mx, mx2[i] ) ;
			yy = min( yy, Mx - Mi ) ;
		}
		Ans = min( Ans, ( x + 1 ) * ( yy + 1 ) ) ;
		
		//D
		mx = mi = 0 ; yy = y ; 
		for( int i = cnt; i >= 1; -- i ) {
			mi = min( sum2[i] + 1, mi ), mx = max( sum2[i] + 1, mx ) ;
			Mi = min( mi, mi2[i] ), Mx = max( mx, mx2[i] ) ;
			yy = min( yy, Mx - Mi ) ;
		}
		Ans = min( Ans, ( x + 1 ) * ( yy + 1 ) ) ;
		printf("%I64d\n", Ans ) ;
	}
	return 0;
}