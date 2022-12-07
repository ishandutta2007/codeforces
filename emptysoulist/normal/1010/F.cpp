#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define Rep(i, s, t) for(register int i = (s); i < (t); ++ i)
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define mp make_pair
#define pi pair<int, int>
#define pb push_back
#define int long long
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 4e5 + 5 ; 
const int P = 998244353 ; 
const int G = 3 ; 
const int Gi = 332748118 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, X, ch[N], sz[N], deg[N], R[N], fa[N], fac[N], inv[N], ind[N], L, limit, Inv ; 
vector<int> F[N], E[N] ; 
void init(int x) {
	limit = 1, L = 0 ; while( limit < x ) limit <<= 1, ++ L ; 
	Rep(i, 0, limit) R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1)) ; 
	Inv = fpow(limit, P - 2) ; 
}
void NTT(vi& a, int type) {
	Rep(i, 0, limit) if(R[i] > i) swap( a[i], a[R[i]] ) ; 
	for(re int k = 1; k < limit; k <<= 1) {
		int d = fpow( (type) ? G : Gi, (P - 1) / (k << 1) ) ;
		for(re int i = 0; i < limit; i += (k << 1))
		for(re int j = i, g = 1; j < i + k; ++ j, g = g * d % P) {
			int nx = a[j], ny = a[j + k] * g % P ; 
			a[j] = (nx + ny) % P, a[j + k] = (nx - ny + P) % P ; 
		}
	}
	if( !type ) Rep(i, 0, limit) a[i] = a[i] * Inv % P ; 
}
void dfs1(int x, int ff) {
	sz[x] = 1, fa[x] = ff ; 
	for(int v : E[x]) if(v ^ ff) {
		dfs1(v, x), sz[x] += sz[v], ++ deg[x] ;
		if( sz[v] >= sz[ch[x]] ) ch[x] = v ; 
	}
}
vector<int> p[N], f[N], st[N] ; int top ; 
vi operator + (vi a, vi b) {
	vi ans ; int cnt = max(a.size(), b.size()) ; 
	ans.resize(cnt), a.resize(cnt), b.resize(cnt) ; 
	Rep(i, 0, cnt) ans[i] = a[i] + b[i] ; 
	return ans ; 
}
vi operator * (vi a, vi b) {
	vi ans ; init(a.size() + b.size() + 2) ; int cnt = a.size() + b.size() - 1 ; 
	ans.resize(limit), a.resize(limit), b.resize(limit) ; 
	NTT(a, 1), NTT(b, 1) ;
	Rep( i, 0, limit ) ans[i] = a[i] * b[i] % P ; 
	NTT(ans, 0), ans.resize(cnt) ; 
	return ans ; 
}
void Solve(int l, int r) {
	if(l == r) { p[l] = st[l], f[l] = st[l], ++ f[l][0] ; return ; }
	int mid = (l + r) >> 1 ; 
	Solve(l, mid), Solve(mid + 1, r) ; 
	vi fl = f[l], pr = p[mid + 1], fr = f[mid + 1] ; 
//	printf("now solve [%lld %lld]\n", l, r ) ; 
	//int cnt = fl.size() ; 
//	Rep( i, 0, cnt ) printf("%lld ", fl[i] ) ; puts("") ; cnt = fr.size() ; 
//	Rep( i, 0, cnt ) printf("%lld ", fr[i] ) ; puts("") ; cnt = pr.size() ; 
//	Rep( i, 0, cnt ) printf("%lld ", pr[i] ) ; puts("") ; 
	-- fl[0], f[l] = (fl * pr + fr), p[l] = p[l] * p[mid + 1] ; 
//	cnt = f[l].size() ; 
//	Rep( i, 0, cnt ) printf("%lld ", f[l][i] ) ; puts("") ; 
}
void count(int x) {
	Solve(1, top), F[x] = f[1] ; top = 0 ; 
}
void solve(int x, int ff) {
//	printf("?? solve %lld\n", x ) ; 
	if( deg[x] <= 1 ) F[x].resize(1), F[x][0] = 1 ; 
	for(int v : E[x]) {
		if(v == fa[x] || v == ch[x]) continue ; 
		solve(v, v), F[x] = F[v] ; 
	}
	if( ch[x] ) solve(ch[x], x) ; 
//	printf("now case %lld\n", F[x].size() ) ; 
	int cnt = F[x].size() ; F[x].resize(cnt + 1) ; 
	drep( i, 1, cnt ) F[x][i] = F[x][i - 1] ; 
	F[x][0] = 0, st[++ top] = F[x] ; 
//	printf("now solve(%lld %lld)\n", x, ff ) ; 
//	rep( i, 0, cnt ) printf("%lld ", F[x][i] ) ; puts("") ; 
	if( x == ff ) count(x) ; 
	cnt = F[x].size() ; 
//	printf("now End - (%lld %lld)\n", x, ff ) ; 
//	Rep( i, 0, cnt ) printf("%lld ", F[x][i] ) ; puts("") ; 
}
signed main()
{
	n = gi(), X = gi() ; int x, y ; 
	rep( i, 2, n ) x = gi(), y = gi(), E[x].pb(y), E[y].pb(x) ; 
	dfs1(1, 1), solve(1, 1) ; 
	int Ans = 0 ; fac[0] = inv[0] = ind[0] = 1 ; 
	rep( i, 1, n ) fac[i] = fac[i - 1] * i % P ;  
	rep( i, 1, n ) inv[i] = fpow( fac[i], P - 2 ) ; 
	rep( i, 1, n ) ind[i] = ind[i - 1] * ((X + i) % P) % P ; 
	rep( i, 0, n - 1 ) Ans = (Ans + ind[i] * inv[i] % P * F[1][i + 1] % P) % P ; 
//	rep( i, 1, n ) printf("%lld ", F[1][i] ) ; puts("") ; 
	cout << Ans << endl ; 
	return 0 ;
}