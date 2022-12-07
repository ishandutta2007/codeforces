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
const int maxn = 1e9 ; 
const long long inf = 1e17 ; 
int n, W, root, tot, top, vis[N], cnt, ls[N * 32], rs[N * 32], w[N * 32] ;
long long Ans, sum[N * 32] ; 
struct node { int a, b, id ; } p[N], B[N], C[N] ; 
bool cmp(node x, node y) { return x.b < y.b ; }
void pushup(int x) {
	w[x] = w[ls[x]] + w[rs[x]], sum[x] = sum[ls[x]] + sum[rs[x]] ; 
}
void insert(int &x, int l, int r, int k, int type) {
	if(!x) x = ++ cnt ; 
	if(l == r) { w[x] += type, sum[x] += l * type ; return ; }
	int mid = (l + r) >> 1 ; 
	if(k <= mid) insert(ls[x], l, mid, k, type) ;
	else insert(rs[x], mid + 1, r, k, type) ; 
	pushup(x) ;  
}
long long query(int x, int l, int r, int k) {
	if(l == r) return k * l ; 
	int mid = (l + r) >> 1 ;
	if(k <= w[ls[x]]) return query(ls[x], l, mid, k) ;
	else return sum[ls[x]] + query(rs[x], mid + 1, r, k - w[ls[x]]) ; 
}
signed main() 
{
	n = gi(), W = gi() ; 
	rep( i, 1, n ) p[i].a = gi(), p[i].b = gi(), p[i].id = i ; 
	sort(p + 1, p + n + 1, cmp) ; 
	long long S = 0 ; Ans = inf ; int ip = 0 ; 
	rep( i, 1, n ) insert(root, -maxn, maxn, p[i].a, 1) ; 
	if(W <= n) Ans = min(Ans, query(root, -maxn, maxn, W)) ;
	rep( i, 1, n ) {
		insert(root, -maxn, maxn, p[i].a, -1), S += p[i].a, 
		insert(root, -maxn, maxn, p[i].b - p[i].a, 1) ;
		if(W - i <= n && W >= i) {
			long long z = S + query(root, -maxn, maxn, W - i) ;
			if(Ans >= z) Ans = z, ip = i ; 
		}
	}
	cout << Ans << endl ; 
	for(re int i = ip + 1; i <= n; ++ i) 
	B[++ tot] = (node){i, p[i].a, p[i].id} ;
	for(re int i = 1; i <= ip; ++ i)
	B[++ tot] = (node){i, p[i].b - p[i].a, p[i].id}, vis[p[i].id] = 1 ; 
	sort(B + 1, B + tot + 1, cmp) ; 
	for(re int i = 1; i <= W - ip; ++ i) ++ vis[B[i].id] ; 
	rep( i, 1, n ) printf("%d", vis[i] ) ; 
	return 0 ;
}