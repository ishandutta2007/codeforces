#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
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
const int N = 1e5 + 5 ; 
const int M = 1e6 + 5 ; 
const int IM = 1e6 ; 
const int mod = 1e9 + 7 ; 
int P2, H = 233 ; 
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % mod ;
		base = 1ll * base * base % mod, k >>= 1 ;
	} return ans ;
}
int sw(int x) {
	return (1ll * rand() << 16ll ^ rand()) % x + 1 ; 
}
bool check(int x) {
	int lim = sqrt(x) ; 
	for(re int i = 2; i <= lim; ++ i) {
		if(x % i == 0) return 0 ; 
	} return 1 ; 
}
void init() {
	int lim = 1e8 ; 
	while(1) {
		P2 = 1e9 + sw(lim) ; 
		if(check(P2)) break ; 
	}
}
int n, q, lim, f2[N], inv[N], fac[M], pre[20][M], L[20] ; 
int Pre[M], Nxt[M], g[N][27], F[M] ; 
char A[105], B[N], C[M] ; 
void Has(int x) {
	int l = L[x] ; 
	rep( i, 1, l ) pre[x][i] = (pre[x][i - 1] * H + pre[x][i]) % P2 ; 
}
int Get(int l, int r, int x) {
	if(l > r) return 0 ; 
	if(r > L[x]) return -1 ;
	if(l <= 0) return -1 ; 
	return (pre[x][r] - pre[x][l - 1] * fac[r - l + 1] % P2 + P2) % P2 ; 
}
int Getpre(int l, int r) {
	if(l > r) return 0 ; 
	return (Pre[r] - Pre[l - 1] * fac[r - l + 1] % P2 + P2) % P2 ; 
}
int Getnxt(int l, int r) {
	if(l > r) return 0 ; 
	return (Nxt[r] - Nxt[l - 1] * fac[r - l + 1] % P2 + P2) % P2 ;  
}
int GetC(int l, int r) {
	if(l > r) return 0 ; 
	return (F[r] - F[l - 1] * fac[r - l + 1] % P2 + P2) % P2 ;  
}
void Init() {
	int len = strlen(A + 1) ; 
	rep( i, 1, len ) A[i] -= ('a' - 1) ; 
	rep( i, 1, n ) B[i] -= ('a' - 1) ; 
	fac[0] = 1 ; 
	rep( i, 1, IM ) fac[i] = fac[i - 1] * H % P2 ; 
	L[0] = len ; 
	rep( i, 1, len ) pre[0][i] = A[i] ; 
	int z = len ; lim = 1 ; 
	for(re int j = 1; ; ++ j) {
		int l = 2 * z + 1 ; 
		if(l <= IM) {
			L[j] = l ; 
			rep( i, 1, z ) pre[j][i] = pre[j - 1][i] ; 
			pre[j][z + 1] = B[j] ; 
			rep( i, 1, z ) pre[j][z + 1 + i] = pre[j - 1][i] ; 
		}
		else {
			rep( i, 1, z ) Pre[i] = pre[j - 1][i] ; 
			Pre[z + 1] = B[j] ; 
			for(re int i = z + 2; i <= IM; ++ i)
			Pre[i] = pre[j - 1][i - z - 1] ; 
			rep( i, 1, z ) 
			Nxt[IM - i + 1] = pre[j - 1][z - i + 1] ; 
			Nxt[IM - z] = B[j] ; 
			for(re int i = 1; i <= z; ++ i) {
				if(IM - z - i <= 0) break ; 
				Nxt[IM - z - i] = pre[j - 1][z - i + 1] ; 
			}
			rep( i, 1, IM ) Pre[i] = (Pre[i - 1] * H + Pre[i]) % P2 ; 
			rep( i, 1, IM ) Nxt[i] = (Nxt[i - 1] * H + Nxt[i]) % P2 ; 
			break ; 
		}
		lim = j + 1, z = l ; 
	} 
	rep( i, 0, lim - 1 ) Has(i) ; 
}
signed main()
{
	srand(time(NULL)) ; 
	init() ; 
	n = gi(), q = gi() ; 
	scanf("%s", A + 1) ; 
	scanf("%s", B + 1) ; f2[0] = inv[0] = 1 ; 
	rep( i, 1, n ) f2[i] = f2[i - 1] * 2 % mod ; 
	rep( i, 1, n ) inv[i] = fpow(f2[i], mod - 2) ; 
	Init() ; 
	rep( i, 1, n ) {
		int u = B[i] ; 
		rep( j, 1, 26 ) g[i][j] = g[i - 1][j] ;
		g[i][u] = (g[i][u] + inv[i]) % mod ;
	}
	while(q--) {
		int w = gi() ; scanf("%s", C + 1) ; 
		int p = f2[w] ; 
		int len = strlen(C + 1) ; 
		rep( i, 1, len ) C[i] -= ('a' - 1) ; F[0] = 0 ; 
		rep( i, 1, len ) F[i] = (F[i - 1] * H + C[i]) % P2 ; 
		int ans = 0 ; 
		for(re int i = 1; i <= L[0]; ++ i) 
			if(Get(i, i + len - 1, 0) == F[len]) ++ ans ; 
		int ret = min(w, lim) ;  
		for(re int i = 0; i < ret; ++ i) {
			int z = inv[i + 1] ; 
			for(re int j = 1; j <= len; ++ j) {
				if(C[j] != B[i + 1]) continue ; 
		//		printf("QAQ %lld %lld (%lld %lld) (%lld %lld) %lld [%lld %lld]\n", i, j, 
			//		Get(L[i] - j + 2, L[i], i), Get(1, len - j, i), 
			//		F[j - 1], GetC(j + 1, len), L[i], L[i] - j + 2, L[i] ) ; 
				
				if(Get(L[i] - j + 2, L[i], i) != F[j - 1]) continue ; 
				if(Get(1, len - j, i) != GetC(j + 1, len)) continue ; 
				ans = (ans + z) % mod ; 
		//		printf("qwq %lld %lld\n", i, j ) ; 
			}
			//len - j
		}
		if(w > lim) {
			for(re int j = 1; j <= len; ++ j) {
				if(Getnxt(IM - j + 2, IM) != F[j - 1]) continue ; 
				if(Getpre(1, len - j) != GetC(j + 1, len)) continue ; 
				int u = C[j] ; 
				ans = (ans + g[w][u] - g[lim][u] + mod) % mod ; 
			}
		}
		printf("%lld\n", ans * f2[w] % mod) ;
	}
	return 0 ; 
}