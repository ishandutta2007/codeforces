#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( int i = (t); i >= (s); -- i )
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
const int N = 2e5 + 5 ; 
int n, m, p, ud[N], a[N], b[N], f[N], vis[70] ; 
char s[N], D[N] ; 
int sw(int x) {
	return ((1ll * rand() << 16ll) ^ rand()) % x + 1 ; 
}
signed main() {
	srand(time(NULL)) ; 
	n = gi(), m = gi(), p = gi() ; 
	rep( i, 1, n ) {
		scanf("%s", s + 1) ; 
		rep( j, 1, m ) 
		a[i] |= (1ll * (s[j] - '0') << (j - 1)) ; 
	}
	int qwq = 30, ans = 0 ; 
	rep( k, 1, m ) D[k] = '0' ; 
	while(qwq --) {
		int u = sw(n), limit = a[u], id = 0 ; 
		rep( i, 1, m ) vis[i] = ((limit >> (i - 1)) & 1) ;
		rep( i, 1, m ) if(vis[i]) vis[i] = ++ id, ud[id] = i ; 
		rep( i, 1, n ) {
			int v = (a[i] & limit) ; b[i] = 0 ; 
			rep( j, 1, m ) 
				if(vis[j] && ((v >> (j - 1)) & 1)) 
				b[i] |= (1ll << (vis[j] - 1)) ;  
		} 
		int lim = (1 << id) - 1 ; 
		rep( i, 0, lim ) f[i] = 0 ; 
		rep( i, 1, n ) ++ f[b[i]] ;  
		for(int k = 0; k < id; ++ k) rep( i, 0, lim )
		if(!((i >> k) & 1)) f[i] += f[i | (1ll << k)] ; 
		rep( i, 0, lim ) if(f[i] >= ((n + 1) / 2)) {
			int d = 0 ; 
			rep( j, 0, id ) d += ((i >> j) & 1) ;
			if(d > ans) {
				ans = d ; rep( k, 1, m ) D[k] = '0' ; 
				rep( k, 1, id ) if((i >> (k - 1)) & 1) D[ud[k]] = 1 + '0' ; 
			}
		}
	} 
	cout << D + 1 << endl ; 
	return 0 ;
}