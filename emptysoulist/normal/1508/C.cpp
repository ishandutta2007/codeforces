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
int n, m, L[N], R[N], bef[N], vis[N], fa[N] ; 
struct E { int x, y, z ; } e[N] ;
bool cmp(E x, E y) { return x.z < y.z ; }
vector<int> G[N] ; 
int fd(int x) { return (fa[x] == x) ? x : fa[x] = fd(fa[x]) ; }
void merge(int x, int y) { int u = fd(x), v = fd(y) ; fa[u] = v ; }
queue<int> q ; 
int num, chs[N], st[N], top ; 
struct node {
	int x, y ; 
} A[N] ; 
void del(int x) { R[L[x]] = R[x], L[R[x]] = L[x] ; }
void ins(int x, int y) { q.push(x), del(x), vis[x] = 1, A[++ num] = (node){x, y} ; }
void solve(int x) {
	q.push(x), del(x), vis[x] = 1 ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop() ; 
		for(int v : G[u]) chs[v] = 1 ; 
		for(int i = R[0]; i != n + 1; i = R[i]) {
			if(chs[i]) continue ; 
			st[++ top] = i, merge(i, x) ; 
		}
		while(top) ins(st[top], u), -- top ; 
		for(int v : G[u]) chs[v] = 0 ; 
	}
}
signed main()
{
	n = gi(), m = gi() ; int S = 0 ; 
	rep( i, 1, m ) 
		e[i].x = gi(), e[i].y = gi(), e[i].z = gi(), S ^= e[i].z,
		G[e[i].x].pb(e[i].y), G[e[i].y].pb(e[i].x) ; 
	rep( i, 1, n ) fa[i] = i ; 
	sort(e + 1, e + m + 1, cmp) ; 
	long long lim = 1ll * n * (n - 1) / 2 ; 
	rep( i, 1, n ) L[i] = i - 1, R[i] = i + 1 ; 
	R[0] = 1 ; 
	rep( i, 1, n ) if(!vis[i]) solve(i) ; 
	if(lim != num + m) {
		int ans = 0 ; 
		rep( i, 1, m ) {
			int x = e[i].x, y = e[i].y ; 
			if(fd(x) != fd(y)) merge(x, y), ans += e[i].z ; 
		}
		cout << ans << endl ; 
	}
	else {
		int Ans = 0, ans = 0, tt = 0 ; 
		rep( i, 1, m ) {
			int x = e[i].x, y = e[i].y ; 
			if(fd(x) != fd(y)) merge(x, y), ans += e[i].z ; 
		}
		Ans = ans + S ; 
		rep( i, 1, num ) {
			rep( j, 1, n ) fa[j] = j ; 
			tt = n, ans = 0 ; 
			rep( j, 1, num ) {
				if(i == j) continue ; 
				int x = A[j].x, y = A[j].y ; 
				if(fd(x) != fd(y)) -- tt, merge(x, y) ; 
			}
			rep( j, 1, m ) {	
				int x = e[j].x, y = e[j].y ; 
				if(fd(x) != fd(y)) -- tt, merge(x, y), ans += e[j].z ; 
			}
			if(tt == 1) Ans = min(Ans, ans) ; 
		}
		cout << Ans << endl ; 
	}
	return 0 ;
}
/*
4 4
1 2 1
2 3 2
3 4 4
1 4 8
*/