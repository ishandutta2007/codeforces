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
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 10000 + 5 ; 
int n, a[N], tot[N] ; 
signed main()
{
	int T = gi() ; 
	while(T--) {
		n = gi() ; int ans = 0 ;  
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 1, n ) tot[i] = 0 ; 
		for(int i = 1; i <= n; ++ i) {
			int d = a[i] - tot[i], lim = min(n, i + a[i]) ; 
			ans += max( d - 1, 0ll ) ; 
			for(int j = i + 2; j <= lim; ++ j)
				++ tot[j] ; 
			if(d <= 1) tot[i + 1] += (1 - d) ; 
		}
		cout << ans << endl ; 
	}
	return 0 ;
}