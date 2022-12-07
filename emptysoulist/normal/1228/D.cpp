#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int gi() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 1e5 + 5 ; 
const int M = 3e5 + 5 ; 
int n, m, cnt, head[N], vis[N], Fr[M], Ed[M], Can[N], L[N], R[N], flag, idnex ; 
struct E {
	int to, next ; 
} e[M * 2] ;  
void add( int x, int y ) {
	e[++ cnt] = (E){ y, head[x] }, head[x] = cnt ,
	e[++ cnt] = (E){ x, head[y] }, head[y] = cnt ; 
}
struct node {
	int u, v ; 
};
int fa[N] ;
int fd( int x ) {
	return ( fa[x] == x ) ? x : fa[x] = fd(fa[x]) ; 
}
void del( int x ) {
	R[L[x]] = R[x], L[R[x]] = L[x] ; 
}
queue<int> q ;
void merge( int x, int y ) {
	int u = fd(x), v = fd(y) ; 
	if( u == v ) return ; 
	fa[u] = v ; 
}
void solve( int x ) {
	++ idnex, q.push(x), del(x), vis[x] = idnex ;
	while( !q.empty() ) {
		int u = q.front() ; q.pop() ; 
		Next( i, u ) {
			int v = e[i].to ; Can[v] = 1 ; 
		}
		for( re int i = 0; i != n + 1; i = R[i] ) {
			if( !i || Can[i] ) continue ; 
			del(i), q.push(i), merge( x, i ), vis[i] = idnex ;
		}
		Next( i, u ) {
			int v = e[i].to ; Can[v] = 0 ;
		}
	}
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) fa[i] = i, L[i] = i - 1, R[i] = i + 1 ;
	rep( i, 1, m ) Fr[i] = gi(), Ed[i] = gi(), add( Fr[i], Ed[i] ) ; R[0] = 1 ;
	rep( i, 1, n ) {
		if( !vis[i] ) solve(i) ;
	}
	if( idnex != 3 ) puts("-1") ;
	else {
		rep( i, 1, m ) if( fd(Fr[i]) == fd(Ed[i]) ) flag = 1 ; 
		if( flag ) puts("-1") ; 
		else {
			rep( i, 1, n ) printf("%d ", vis[i] ) ;
		}
	}
	return 0 ;
}