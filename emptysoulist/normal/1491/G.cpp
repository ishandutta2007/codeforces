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
const int N = 2e5 + 5 ; 
int n, top, cnt, vis[N], c[N] ; 
vector<int> R[N] ; 
pi opt[N] ; 
void Swap(int x, int y) { opt[++ top] = mp(x, y) ; }
signed main() 
{
	n = gi() ; 
	rep( i, 1, n ) c[i] = gi() ; 
	rep( i, 1, n ) {
		if(vis[i]) continue ; 
		int u = i ; ++ cnt, R[cnt].clear() ; 
		while(!vis[u]) R[cnt].pb(u), vis[u] = 1, u = c[u] ; 
		if(R[cnt].size() == 1) -- cnt ; 
	}
	for(int k = 1; k < cnt; k += 2) {
		vi a = R[k], b = R[k + 1] ;  
		Swap(a[0], b[0]) ; 
		for(int i = 1; i < (int)a.size(); ++ i)
		Swap(a[i], b[0]) ; 
		for(int i = 1; i < (int)b.size(); ++ i)
		Swap(b[i], a[0]) ; 
		Swap(b[0], a[0]) ; 
	}
	if(cnt & 1) {
		vi a = R[cnt] ; 
		if(a.size() == 2) {
			int x = a[0], y = a[1], z = 0 ; 
			rep( i, 1, n ) if((i != x) && (i != y)) z = i ; 
			Swap(x, z), Swap(z, y), Swap(z, x) ; 
		}
		else {
			Swap(a[0], a[1]) ; 
			for(int i = 2; i < (int)a.size() - 1; ++ i) 
				Swap(a[i], a[0]) ; 
			int x = a[0], y = a[1], z = a[a.size() - 1] ; 
			Swap(y, z), Swap(x, z), Swap(x, y) ; 
		}
	}
	printf("%d\n", top ) ; 
	rep( i, 1, top ) printf("%d %d\n", opt[i].first, opt[i].second ) ; 
	return 0 ;
}