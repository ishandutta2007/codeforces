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
const int N = 200 + 5 ; 
const int M = 2000 + 5 ; 
const int inf = 1e5 + 7 ; 
struct E {
	int to, next, w ; 
} e[M << 1] ;
pair<int, int> dE[N] ; 
int n, m, cnt, id, head[N], dis[N][N], vis[N], flag[N] ; 
void add(int x, int y, int z) { dis[x][y] = z ; }
void out() { puts("NO") ; exit(0) ; }
queue<int> q ; 
int solve(int x) {
	if(dis[x][x] < 0) out() ; 
	rep( i, 1, m ) if(dis[x][dE[i].first] == dis[x][dE[i].second]) out() ; 
	int mx = 0 ; 
	rep( i, 1, n ) mx = max(mx, dis[x][i]) ; 
	return mx ; 
}
signed main()
{
	n = gi(), m = gi() ; int x, y, z ; 
	rep( i, 1, n ) rep( j, 1, n ) dis[i][j] = (i == j) ? 0 : 100000 ; 
	rep( i, 1, m ) {
		x = gi(), y = gi(), z = gi() ;
		dE[i] = mp(x, y) ; 
		if(!z) add(x, y, 1), add(y, x, 1) ; 
		else add(x, y, 1), add(y, x, -1) ; 
	}
	rep( k, 1, n ) rep( i, 1, n ) rep( j, 1, n ) 
	dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]) ;
	int Ans = -100 ; 
	rep( i, 1, n ) {
		z = solve(i) ;
		if(z > Ans) Ans = z, id = i ; 
	}
	solve(id) ; 
	puts("YES") ; 
	cout << Ans << endl ; 
	rep( i, 1, n ) printf("%d ", dis[id][i] ) ; puts("") ; 
	return 0 ;
}