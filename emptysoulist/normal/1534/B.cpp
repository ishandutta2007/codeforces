#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int N = 4e5 + 5 ; 
int n, a[N] ; 
signed main() {
	int T = gi() ; 
	while(T--) {
		n = gi() ; long long ans = 0 ; 
		rep( i, 1, n ) a[i] = gi() ; 
		a[0] = 0, a[n + 1] = 0 ; 
		for(int i = 1; i <= n; ++ i) {
			if(a[i] >= a[i - 1] && a[i] >= a[i + 1])
			ans += (a[i] - max(a[i - 1], a[i + 1])),
			a[i] = max(a[i - 1], a[i + 1]) ; 
			if(a[i] >= a[i - 1])
			ans += (a[i] - a[i - 1]) ;
			if(a[i] >= a[i + 1])
			ans += (a[i] - a[i + 1]) ; 
		}
		cout << ans << endl ; 
	}
	return 0 ;
}