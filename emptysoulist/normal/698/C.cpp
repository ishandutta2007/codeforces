#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
double ans[21], dp[1 << 20] ; 
int n, k ;
double p[22] ; 
int lowbit( int x ) {
    return __builtin_popcountll(x) ;
}
signed main()
{
	n = gi(), k = gi() ; 
	dp[0] = 1.0 ; int cnt = 0 ; 
	rep( i, 1, n ) cin >> p[i], cnt += (p[i] > 0) ;
	if(cnt <= k) {
		rep( i, 1, n ) printf("%d ", p[i] > 0) ; 
		exit(0) ; 
	}
	int limit = (1 << n) - 1 ; 
	for(int S = 0; S < limit; ++ S) {
		if(lowbit(S) == k) {
			for(int i = 1; i <= n; ++ i) 
				if(S & (1 << (i - 1))) ans[i] += dp[S] ; 
			continue ; 
		}
		double fm = 1 ; 
		for(int i = 1; i <= n; ++ i) 
			if(S & (1 << (i - 1))) fm -= p[i] ; 
		for(int i = 1; i <= n; ++ i) {
			if(S & (1 << (i - 1))) continue ; 
			dp[S | (1 << (i - 1))] += dp[S] * p[i] / fm ; 
		}
	}
	rep( i, 1, n ) printf("%.12lf ", ans[i] ) ; 
	return 0 ; 
}