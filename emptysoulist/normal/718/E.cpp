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
const int N = 1e5 + 10 ; 
int n, a[N], dis[10][N], f[N], vis[N], h[N], g[10][300], p[10][10][300][300], mx ; 
long long ans ; 
char s[N] ; queue<int> q ; 
void update(int x, int k) { vis[x] = 1, f[x] = k, q.push(x) ; }
signed main()
{
	n = gi(), scanf("%s", s + 1), mx = 0 ; 
	rep( i, 1, n ) a[i] = s[i] - 'a' + 1 ; 
	int lim = n + 8 ; 
	rep( c, 1, 8 ) {
		rep( i, 1, lim ) f[i] = 16, vis[i] = 0 ; 
		rep( i, 1, n ) if(a[i] == c) update(i, 0) ; 
		while(!q.empty()) {
			int u = q.front(), z = a[u] ; q.pop() ; 
			if((u > 1) && (!vis[u - 1])) update(u - 1, f[u] + 1) ;
			if((u < n) && (!vis[u + 1])) update(u + 1, f[u] + 1) ; 
			if(!vis[z + n]) {
				f[z + n] = f[u], vis[z + n] = 1 ; 
				rep( i, 1, n ) if((!vis[i]) && (a[i] == z)) update(i, f[u] + 1) ;
			}
		}
		rep( i, 1, lim ) dis[c][i] = f[i] ; dis[c][n + c] = 0 ; 
	} 
	rep( i, 1, 8 ) rep( j, 1, 8 ) rep( S, 0, 255 ) rep( T, 0, 255 ) {
		int d = 16 ; 
		rep( k, 0, 7 ) 
		d = min(d, ((S >> k) & 1) + ((T >> k) & 1) + dis[k + 1][i + n] + dis[k + 1][j + n] + 1) ; 
		p[i][j][S][T] = d ; 
	}
	rep( i, 1, n ) rep( k, 1, 8 ) {
		if(dis[k][i] > dis[k][n + a[i]]) h[i] |= (1 << (k - 1)) ;  
	}
	rep( i, 2, n ) { 
		for(int j = i - 1; j > max(0, i - 16); -- j) {
			int d = min(i - j, p[a[i]][a[j]][h[i]][h[j]]) ; 
			if(d > mx) mx = d, ans = 0 ;
			if(d == mx) ++ ans ; 
		}
		if(i > 16) g[a[i - 16]][h[i - 16]] ++ ; 
		rep( c, 1, 8 ) rep( j, 0, 255 ) {
			if(!g[c][j]) continue ;
			int d = p[a[i]][c][h[i]][j] ; 
			if(d > mx) mx = d, ans = 0 ;
			if(d == mx) ans += g[c][j] ; 
		}
	}
	cout << mx << " " << ans << endl ; 
	return 0 ;
}