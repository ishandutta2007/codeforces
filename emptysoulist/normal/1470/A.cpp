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
const int N = 3e5 + 5 ; 
int n, m, c[N], a[N] ; 
priority_queue<int> Q ; 
void solve() {
	n = gi(), m = gi() ; 
	rep( i, 1, n ) c[i] = gi() ; 
	rep( i, 1, m ) a[i] = gi() ; 
	sort(c + 1, c + n + 1) ; 
	int id = n ;
	for(re int i = 1; i <= n; ++ i) {
		if(n - i + 1 <= c[i]) id = min(id, i) ; 
	}
	int ans = 0, lim = n - id + 1 ;
	for(re int i = 1; i < id; ++ i) ans += a[c[i]] ;
	for(re int i = 1; i <= lim; ++ i) ans += a[i] ; 
	cout << ans << endl ; 
}
signed main()
{
	int T = gi() ; 
	while(T--) solve() ; 
	return 0 ;
}