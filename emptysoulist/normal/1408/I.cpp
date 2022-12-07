#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize( \
	"inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2,-ffast-math,-fsched-spec,unroll-loops,-falign-jumps,-falign-loops,-falign-labels,-fdevirtualize,-fcaller-saves,-fcrossjumping,-fthread-jumps,-funroll-loops,-freorder-blocks,-fschedule-insns,inline-functions,-ftree-tail-merge,-fschedule-insns2,-fstrict-aliasing,-fstrict-overflow,-falign-functions,-fcse-follow-jumps,-fsched-interblock,-fpartial-inlining,no-stack-protector,-freorder-functions,-findirect-inlining,-fhoist-adjacent-loads,-frerun-cse-after-loop,inline-small-functions,-finline-small-functions,-ftree-switch-conversion,-foptimize-sibling-calls,-fexpensive-optimizations,inline-functions-called-once,-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
#define pb push_back
#define vi vector<int>
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int P = 998244353 ; 
const int N = (1 << 16) + 5 ; 
const int M = 20 + 5 ;
int fpow(int x, int k) {
	int ans = 1, base = x ;
	while(k) {
		if(k & 1) ans = 1ll * ans * base % P ;
		base = 1ll * base * base % P, k >>= 1 ;
	} return ans ;
}
int n, K, m, lim, S, num, f[N], cnt[N], g[M], A[M], fac[M], inv[M], iv[M], st[N], top ; 
int Ln[N][M] ; 
map<vi, int> G ; 
vector<int> sd[205] ; int sc[205] ; 
int bit(int x) { return __builtin_popcount(x) ;}
int Fm[M], Fp[M] ; 
int mod(int x) { return (x - x / P * P) ; }
void polydiv(int *a) { rep( i, 1, K ) a[i - 1] = i * a[i] % P ; a[K] = 0 ; }
void polyln(int *a) {
	rep( j, 0, K ) Fp[j] = 0 ; 
	rep( j, 1, K ) {
		int de = 0 ;
		for(re int i = 1; i < j; ++ i) de = (de + mod(Fp[i] * a[j - i]) * i) ;
		Fp[j] = (a[j] - de % P * iv[j] % P + P) % P ; 
	} rep( j, 0, K ) a[j] = Fp[j] ; 
}
void polyexp(int *a) {
	rep( j, 0, K ) Fp[j] = 0 ; polydiv(a), Fp[0] = 1 ; 
	rep( j, 1, K ) {
		for(int k = 0; k < j; ++ k) Fp[j] = (Fp[j] + mod(Fp[k] * a[j - k - 1])) ; 
		Fp[j] = Fp[j] % P * iv[j] % P ; 
	} rep( j, 0, K ) a[j] = Fp[j] ; 
}
signed main()
{
	n = gi(), K = gi(), m = gi(), lim = 1 << m ; 
	for(int i = 1; i <= n; ++ i) {
		int x = gi(); S ^= x ; vi d ; 
		rep( j, 1, K ) d.pb(x ^ (x - j)) ; ++ G[d] ;
	}
	fac[0] = inv[0] = iv[0] = 1 ; 
	rep( i, 1, K ) 
		fac[i] = fac[i - 1] * i % P, inv[i] = fpow( fac[i], P - 2 ),
		iv[i] = fpow( i, P - 2 ) ; 
	for(auto x : G) ++ num, sd[num] = x.first, sc[num] = x.second ; 
	int St = (1 << K) ; 
	for(re int i = 0; i < St; ++ i) {
		A[0] = 1 ; 
		for(re int j = 1; j <= K; ++ j) 
		A[j] = ((i >> (j - 1)) & 1) ? P - inv[j] : inv[j] ; 
		polyln(A) ; 
		rep( j, 0, K ) Ln[i][j] = A[j] ; 
	}
	for(int t = 0; t < lim; ++ t) {
		for(int i = 1; i <= num; ++ i ) {
			int c = sc[i], z = 0 ; 
			for(re int j = 0; j < K; ++ j) 
				if( bit(sd[i][j] & t) & 1 ) z |= (1 << j) ; //0 mean 1, 1 mean -1
			if( !cnt[z] ) st[++ top] = z ; cnt[z] += c ;
		}
		rep( j, 0, K ) g[j] = 0 ; g[0] = 1 ; 
		for(int x = 1; x <= top; ++ x) {
			int z = st[x] ; 
			rep( j, 0, K ) A[j] = Ln[z][j] * cnt[z] % P ; 
			polyexp(A) ; 
			for(re int j = K; j >= 0; -- j) {
				int tmp = 0 ; 
				rep( k, 0, j ) tmp = (tmp + mod(g[k] * A[j - k])) ; 
				g[j] = tmp % P ; 
			}
		}
		f[t] = g[K] * fac[K] % P ; rep( i, 1, top ) cnt[st[i]] = 0 ; top = 0 ; 
	}
	for(int k = 1; k < lim; k <<= 1) {
		for(int i = 0; i < lim; i += (k << 1)) 
		for(int j = i; j < i + k; ++ j) {
			int nx = f[j], ny = f[j + k] ;
			f[j] = (nx + ny) % P, f[j + k] = (nx - ny + P) % P ;  
		}
	} 
	int di = fpow(lim, P - 2) * fpow(n, P - 1 - K) % P ; 
	for(re int i = 0; i < lim; ++ i) printf("%lld ", f[i ^ S] * di % P ) ; 
	return 0 ;
}