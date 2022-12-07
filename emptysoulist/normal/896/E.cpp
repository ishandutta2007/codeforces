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
const int N = 1e6 + 5 ; 
const int M = 5000 ; 
const int W = 1e5 + 5 ; 
int n, m, mx, cnt, a[N], fa[N], L[M], R[M], Id[N] ; 
struct node {
	int op, l, r, x, ans ; 
} opt[N / 2] ; 
int Lef, Ret, w[N], rt[W], RT[N] ; 
int fd(int x) {
	return (fa[x] == x) ? x : fa[x] = fd(fa[x]) ; 
}
void merge(int x, int &y, int z) { // x  y  
	if(!y) { y = x ; RT[x] = z ; }
	else if(x) { int u = fd(x), v = fd(y) ; fa[u] = v, w[v] += w[u] ; }
}
signed main()
{
	n = gi(), m = gi() ; 
	rep( i, 1, n ) a[i] = gi(), mx = max(mx, a[i]) ; 
	cnt = 500 + 1 ; int idx = 1 ; L[1] = 1 ; 
	rep( i, 1, n ) {
		Id[i] = idx ; if(i % cnt == 0) R[idx] = i, L[++ idx] = i + 1 ; 
	} 
	if(L[idx] > n) -- idx ; R[idx] = n ; 
	rep( i, 1, m ) 
		opt[i].op = gi(), opt[i].l = gi(), 
		opt[i].r = gi(), opt[i].x = gi() ; 
	for(int x = 1; x <= idx; ++ x) {
		int ll = L[x], rr = R[x] ; 
		rep( i, 0, mx ) w[i] = 0 ; Lef = Ret = 0 ; 
		for(int i = ll; i <= rr; ++ i) Ret = max(Ret, a[i]) ; 
		rep( i, 0, Ret ) rt[i] = 0 ; 
		rep( i, ll, rr ) 
			fa[i] = i, w[i] = 1, RT[i] = 0, merge(i, rt[a[i]], a[i]) ; 
		for(int i = 1; i <= m; ++ i) {
			if(opt[i].r < ll || opt[i].l > rr) continue ; 
			int Mx = Ret - Lef, z = opt[i].x ; 
			if(opt[i].l <= ll && rr <= opt[i].r) {
				if(opt[i].op == 1) {
					if(Mx < z) continue ; 
					if(Mx >= 2 * z) {
						for(int j = Lef; j <= Lef + z; ++ j) 
						merge(rt[j], rt[j + z], j + z), rt[j] = 0 ; 
						Lef += z ; 
					}
					else {
						for(int j = Lef + z + 1; j <= Ret; ++ j)
						merge(rt[j], rt[j - z], j - z), rt[j] = 0 ; 
						Ret = Lef + z ;  
					}
				}
				else opt[i].ans += w[rt[z + Lef]] ; 
			}
			else {
				rep( j, ll, rr ) a[j] = RT[fd(j)] - Lef ; 
				rep( j, ll, rr ) if(fd(j) == j) rt[RT[j]] = 0 ; 
				Lef = 0, Ret = 0 ; 
				if(opt[i].op == 1) {
					int l = max(opt[i].l, ll), r = min(opt[i].r, rr) ; 
					for(int j = l; j <= r; ++ j) 
					if(a[j] > z) a[j] -= z ; 
				}
				else { 
					int l = max(opt[i].l, ll), r = min(opt[i].r, rr) ; 
					for(int j = l; j <= r; ++ j) 
					opt[i].ans += (a[j] == z) ;  
				} 
				rep( j, ll, rr ) Ret = max(Ret, a[j]) ;
				rep( j, ll, rr ) 
					fa[j] = j, w[j] = 1, 
					RT[j] = 0, merge(j, rt[a[j]], a[j]) ; 
			}
		}
	} 
	rep( i, 1, m ) if(opt[i].op == 2) printf("%d\n", opt[i].ans ) ; 
	return 0 ;
}