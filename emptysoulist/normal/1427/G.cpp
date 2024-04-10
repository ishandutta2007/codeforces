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
const int M = 220 ;  
int n, num, D, L, a[M][M], cnt, head[N], vis[N], R[N], F[N] ; 
int cur[N] ; 
long long Ans ;
vector<int> st, f[M * 4] ; 
map<int, int> S ; 
struct E {
	int to, next, w ; 
} e[N << 1] ;
int Id(int x, int y) {
	return (x - 1) * n + y ; 
}
void add(int x, int y) {
	e[++ cnt] = (E){ y, head[x], 1 }, head[x] = cnt,
	e[++ cnt] = (E){ x, head[y], 1 }, head[y] = cnt ; 
}
void init(int x, int id) {
	if(vis[id]) return ; vis[id] = x ; 
	if(!S[x]) S[x] = ++ L ; f[S[x]].pb(id) ; 
}
queue<int> q ; 
vector<int> ST ; 
int dep[N], beg ; 
int DFS2(int x, int k) {
	if(vis[x] > k && R[x]) { R[x] = 0 ; return 1 ; }
	//printf("DFS2 %d %d %d\n", x, k, dep[x] ) ; 
	for(int &i = cur[x]; i; i = e[i].next ) {
		int v = e[i].to ; 
		if(e[i].w && (dep[v] == (dep[x] + 1))) {
			int d = DFS2(v, k) ; 
			if(!d) continue ; 
			e[i].w -= d, e[i ^ 1].w += d ; 
			return d ; 
		}
	} return 0 ; 
}
void BFS2(int x, int k) { // 
	if(F[x]) return ; 
//	printf("BFS2 %d %d %d\n", x, k, D ) ;
	rep( i, 0, num ) dep[i] = 0 ; dep[x] = 1, q.push(x) ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if(!dep[v] && e[i].w) 
			dep[v] = dep[u] + 1, q.push(v) ; 
		}
	}
	rep( i, 1, num ) cur[i] = head[i] ; 
	int de = DFS2(x, k) ; D += de, F[x] = de ; 
	//printf("BFS2 %d %d %d\n", x, k, D ) ;
}
int DFS1(int x, int k) {
	if(vis[x] < k && vis[x] && F[x]) { beg = x, F[x] = 0 ; return 1 ; }
	for(int &i = cur[x]; i; i = e[i].next ) {
		int v = e[i].to ; 
		if((e[i].w == 2) && dep[v] == dep[x] + 1) {
			int d = DFS1(v, k) ; 
			if(!d) continue ; 
			e[i].w -= d, e[i ^ 1].w += d ; 
			return d ; 
		}
	} return 0 ; 
}
void BFS1(int x, int k) { // 
	if(R[x]) return ; 
//	printf("BFS %d %d\n", x, k ) ;
	rep( i, 0, num ) dep[i] = 0 ; dep[x] = 1,  q.push(x) ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; 
			if(!dep[v] && (e[i].w == 2)) 
			dep[v] = dep[u] + 1, q.push(v) ; 
		}
	}
	rep( i, 1, num ) cur[i] = head[i] ; beg = 0 ; 
	int de = DFS1(x, k) ; D -= de, R[x] = de ;
	if(beg) BFS2(beg, k) ; 
}
void update(int K) {
//	printf("update %d\n", K ) ; 
	int id = S[K] ; 
	for(int v : f[id]) BFS1(v, K) ; 
	for(int v : f[id]) BFS2(v, K) ; 
}
signed main()
{
	//freopen("test.in", "r", stdin ) ;
	n = gi(), cnt = 1, num = n * n ; 
	memset(a, -1, sizeof(a)) ; 
	rep( i, 1, n ) rep( j, 1, n ) 
	a[i][j] = gi() ; 
	rep( i, 2, n ) 
		Ans += abs(a[1][i] - a[1][i - 1]), 
		Ans += abs(a[n][i] - a[n][i - 1]),
		Ans += abs(a[i][1] - a[i - 1][1]),
		Ans += abs(a[i][n] - a[i - 1][n]);
	rep( i, 1, n ) 
		st.pb(a[i][1]), st.pb(a[i][n]), 
		st.pb(a[1][i]), st.pb(a[n][i]),
		init(a[i][1], Id(i, 1)), init(a[i][n], Id(i, n)),
		init(a[1][i], Id(1, i)), init(a[n][i], Id(n, i)) ; 
	a[1][1] = a[1][n] = a[n][1] = a[n][n] = -1 ; 
	rep( i, 1, num ) R[i] = 1 ; 
	for(int i = 2; i <= n; ++ i) {
		for(int j = 2; j <= n; ++ j) {
			if(a[i][j] == -1) continue ; 
			if((a[i - 1][j] != -1) && (j != n)) add(Id(i - 1, j), Id(i, j)) ;
			if((a[i][j - 1] != -1) && (i != n)) add(Id(i, j - 1), Id(i, j)) ;
		}
	}
	sort(st.begin(), st.end()) ; 
	int bef = 0 ; 
	for(int v : st) {
		if(v == bef) continue ; 
		Ans += 1ll * (v - bef - 1) * D ; 
		update(v), Ans += D, bef = v ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}