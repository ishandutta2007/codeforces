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
int n, cnt, fa[N], a[N], b[N] ;
int fd(int x) {
	return (fa[x] == x) ? x : fa[x] = fd(fa[x]) ; 
}
void merge(int x, int y) { fa[fd(x)] = fd(y) ; }
signed main() {
	int T = gi() ; 
	while(T--) {
		n = gi(), cnt = 0 ; 
		rep( i, 1, n ) fa[i] = i ; 
		rep( i, 1, n ) a[i] = gi() ; 
		rep( i, 1, n ) b[i] = gi() ; 
		rep( i, 1, n ) merge(a[i], b[i]) ; 
		rep( i, 1, n ) if(fa[i] == i) ++ cnt ; 
		int mod = 1e9 + 7, ans = 1 ; 
		rep( i, 1, cnt ) ans = (ans + ans) % mod ;
		cout << ans << endl ; 
	}
	return 0 ;
}