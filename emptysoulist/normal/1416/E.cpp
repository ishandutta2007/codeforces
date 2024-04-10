#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
const int inf = 1e9 ; 
int n, a[N], k, b, L, R ; 
set<int> S ; 
set<int>::iterator it ; 
bool find(int x) {
	return (((L <= x) && (x <= R)) | (S.find(k * (x - b)) != S.end())) ;
}
int st[N], top ; 
void Del(int x) {
	top = 0 ; 
	if( S.empty() ) return ; 
	if( k == 1 ) {
		it = S.lower_bound(x - b) ; 
		for(; it != S.end(); ++ it) st[++ top] = *it ; 
	}
	else {
		it = S.upper_bound(b - x) ; 
		if( it == S.begin() ) return ;
		-- it ; 
		for(; it != S.begin(); -- it) st[++ top] = *it ; 
		if( it == S.begin() ) st[++ top] = *it ; 
	} while( top ) S.erase(st[top]), -- top ; 
}
void solve() {
	n = gi() ; int ans = 0 ;
	L = inf, R = 1, k = 1, b = 0 ;
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, n ) {
		if( a[i] % 2 == 0 ) {
			int u = a[i] / 2 ; Del(a[i]) ;
			if( find(u) ) S.clear(), ans += 2, S.insert(k * (u - b)), L = inf, R = 1 ; 
			else {
				++ ans, S.insert(k * (u - b)) ; 
				L = a[i] - L, R = a[i] - R,
				swap( L, R ), L = max( L, 1ll ) ;  
				if( L > R ) L = inf, R = 1 ; 
			}
		}
		else {
			int flag = 1 ; 
			Del(a[i]), L = a[i] - L, R = a[i] - R, 
			swap( L, R ), L = max( L, 1ll ) ;
			if( L > R ) L = inf, R = 1, flag = 0 ; 
			if(S.empty()) {
				if( flag ) ++ ans ; 
				else L = 1, R = a[i] - 1 ;
			} 
			else ++ ans ; 
		}
		k = -k, b = -b, b += a[i] ; 
	}
	cout << 2 * n - ans << endl ; 
	S.clear() ; 
}
signed main()
{
	int T = gi() ; 
	while( T-- ) solve() ; 
	return 0 ;
}