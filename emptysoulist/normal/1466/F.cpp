#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define int long long
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5e5 + 5 ; 
const int P = 1e9 + 7 ; 
int n, m, a[N], fa[N], st[N], top ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int fd(int x) {
	return (fa[x] == x) ? fa[x] : fa[x] = fd(fa[x]) ; 
}
bool merge(int x, int y) {
	int u = fd(x), v = fd(y) ; 
	if(u == v) return 0 ; 
	fa[u] = v ; return 1 ; 
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, m + 1 ) fa[i] = i ; 
	rep( i, 1, n ) {
		int k = gi() ; 
		if(k == 1) {
			int x = gi() ; 
			int t = merge(x, m + 1);
			if(t) st[++ top] = i ; 
		}
		else {
			int x = gi(), y = gi() ; 
			int t = merge(x, y) ;
			if(t) st[++ top] = i ; 
		}
	}
	cout << fpow(2, top) << " " << top << endl ; 
	rep( i, 1, top ) printf("%lld ", st[i] ) ; 
	return 0 ;
}