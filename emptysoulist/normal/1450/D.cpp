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
const int N = 3e5 + 5 ; 
int n, a[N], fa[N], sz[N], vis[N], A[N] ; 
vector<int> Id[N] ; 
int fd(int x) {
	return (fa[x] == x) ? fa[x] : fa[x] = fd(fa[x]) ; 
}
void merge(int x, int y) {
	int u = fd(x), v = fd(y) ;
	if(u == v) return ; 
	fa[u] = v, sz[v] += sz[u] ; 
}
void solve() {
	n = gi() ; 
	rep( i, 1, n + 1 ) A[i] = 0, Id[i].clear() ; 
	rep( i, 1, n + 1 ) vis[i] = 0, fa[i] = i, sz[i] = 1 ; 
	rep( i, 1, n ) a[i] = gi(), Id[a[i]].pb(i) ; 
	for(re int i = n; i >= 1; -- i) {
		if( Id[i].size() == 0 ) {
			int r = n - i + 1 ; 
			++ A[1], -- A[r + 1] ; 
		}
		else {
			for(int u : Id[i] ) { 
				vis[u] = 1 ; 
				if(vis[u - 1]) merge(u - 1, u) ;
				if(vis[u + 1]) merge(u, u + 1) ; 
			}
			for(int u : Id[i]) {
				int l = sz[fd(u)], r = n - i + 1 ; 
				if(l <= r) ++ A[l + 1], -- A[r + 1] ; 
			}
		}
	}
	rep( i, 1, n ) A[i] += A[i - 1] ;
	rep( i, 1, n ) {
		if(A[i]) printf("0") ;
		else printf("1") ; 
	} puts("") ; 
}
signed main()
{
	int t = gi() ; 
	while(t--) solve() ;  
	return 0 ;
}
/*
121 1321 13231
*/