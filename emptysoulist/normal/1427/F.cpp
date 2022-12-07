#include<bits/stdc++.h>
using namespace std ; 
#define rep( i, s, t ) for(int i = (s); i <= (t); ++ i)
int gi() {
	int cn = 0, flus = 1 ; char cc = getchar() ; 
	while(cc < '0' || cc > '9') { if(cc == '-') flus = -flus ; cc = getchar() ; }
	while(cc >= '0' && cc <= '9') cn = cn * 10 + cc - '0', cc = getchar() ; 
	return cn * flus ; 
}
const int N = 1200 + 5 ; 
int n, m, a[N], col[N], st[N], top, d[N], deg[N], vis[N], fa[N], num ; 
struct node {
	int l, x, r ; 
} p[N] ; 
void print(int x) {
	printf("%d %d %d\n", p[x].l, p[x].x, p[x].r), vis[x] = 1, -- deg[fa[x]] ; 
}
signed main() {
	n = gi() ; int x ; 
	for(int i = 1; i <= 3 * n; ++ i) 
		x = gi(), a[x] = 1 ; 
	for(int i = 1; i <= 6 * n; ++ i) {
		st[++ top] = i ; 
		if(top >= 3 && (a[st[top - 1]] == a[st[top - 2]]) && (a[st[top]] == a[st[top - 1]])) {
			p[++ m].l = st[top - 2], p[m].x = st[top - 1], p[m].r = st[top], top -= 3 ; 
			while(num && p[d[num]].l > p[m].l) ++ deg[m], fa[d[num]] = m, -- num ; 
			d[++ num] = m, col[m] = a[i] ; 
		}
	}
	for(int k = 1; k <= m; k += 2) {
		int u1 = 0, u2 = 0 ; 
		rep( i, 1, m ) {
			if(vis[i] || deg[i]) continue ; 
			if(!col[i]) continue ; 
			if(deg[fa[i]] == 1) u1 = i ;
			else u2 = i ; 
		}
		if(u1) print(u1) ;
		else print(u2) ; 
		u1 = 0, u2 = 0 ;
		rep( i, 1, m ) {
			if(vis[i] || deg[i]) continue ; 
			if(col[i]) continue ; 
			if(!fa[i]) u2 = i ;
			else u1 = i ; 
		}
		if(u1) print(u1) ;
		else print(u2) ; 
	}
	return 0 ; 
}