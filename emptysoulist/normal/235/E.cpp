#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 100000 + 500 ; 
const int P = ( 1 << 30 ) ; 
int A, B, C, f[N], u[N], p[N], d[N], r[N], deg[N], vis[N], book[N], cnt, tot, top ;
bool isp[N] ;
struct E { int to, w ; }; 
struct node { int u, v, w ; } e[N * 10]; 
vector<E> mp[N] ; 
inline void init() {
	isp[1] = 1, u[1] = 1, r[++ tot] = 1, book[1] = tot ;
	for( re int i = 2; i <= N - 5; ++ i ) {
		if( !isp[i] ) p[++ top] = i, u[i] = -1 ; 
		for( re int j = 1; j <= top && i * p[j] <= N - 5; ++ j ) {
			isp[i * p[j]] = 1 ; 
			if( i % p[j] == 0 ) continue ;
			u[i * p[j]] = - u[i] ; 
		}
		if( u[i] != 0 ) r[++ tot] = i, book[i] = tot ; 
	}
	for( re int i = 1; i <= N - 5; ++ i ) {
		for( re int j = i; j <= N - 5; j += i ) ++ d[j] ; 
		f[i] = ( f[i - 1] + d[i] ) % P ;
	} 
}
inline int gcd( int x, int y ) {
	if( x == 0 ) return y ; 
	return gcd( y % x, x ) ;
}
signed main()
{
	init() ; 
		memset( mp, 0, sizeof(mp) ), memset( deg, 0, sizeof(deg) ) ;
		A = read(), B = read(), C = read(), cnt = 0 ; 
		int Ans = 0, D = 0 ; D = max( A, max( B, C ) ) ;
		
		for( re int g = 1; r[g] <= D; ++ g ) {
			for( re int i = 1; r[i] * r[g] <= D; ++ i ) {
				if( !u[r[i] * r[g]] ) continue ;  
				for( re int j = i + 1; j <= tot && r[i] * r[j] * r[g] <= D; ++ j ) {
					if( !u[r[j] * r[g]] || gcd( r[i], r[j] ) != 1 ) continue ;
					int u = book[r[i] * r[g]], v = book[r[j] * r[g]], w = r[i] * r[j] * r[g] ;
					if( w == 0 ) continue ;
					++ deg[u], ++ deg[v], e[++ cnt] = (node){ u, v, w } ;
					mp[u].push_back((E){v, w}), mp[v].push_back((E){u, w}) ; 
				}
			}
		}
		//
		int rD = min( A, min( B, C ) ) ;
		for( re int i = 1; r[i] <= min( A, B ); ++ i ) {
			int siz = mp[i].size() - 1 ; 
			rep( j, 0, siz ) {
				int u1 = mp[i][j].to ; 
				Ans += u[r[i]] * u[r[u1]] * u[r[u1]] * f[A / mp[i][j].w] * f[B / mp[i][j].w] * f[C / r[u1]] ;
				Ans += u[r[i]] * u[r[i]] * u[r[u1]] * f[A / r[i]] * f[B / mp[i][j].w] * f[C / mp[i][j].w] ;
				Ans += u[r[i]] * u[r[i]] * u[r[u1]] * f[A / mp[i][j].w] * f[B / r[i]] * f[C / mp[i][j].w] ;
			}
		}
		// 
		for( re int i = 1; r[i] <= rD; ++ i ) Ans += u[r[i]] * u[r[i]] * u[r[i]] * f[A / r[i]] * f[B / r[i]] * f[C / r[i]] ;
		rep( i, 0, D ) mp[i].clear() ;
		for( re int i = 1; i <= cnt; ++ i )
			if( deg[e[i].u] >= deg[e[i].v] ) mp[e[i].u].push_back((E){ e[i].v, e[i].w }) ;
			else mp[e[i].v].push_back((E){ e[i].u, e[i].w }) ;
		// 
		
		for( re int i = 1; r[i] <= D; ++ i ) {
			long long siz = (long long)mp[i].size() - 1ll ; 
			rep( j, 0, siz ) vis[mp[i][j].to] = mp[i][j].w ; 
			rep( j, 0, siz ) {
				int u1 = mp[i][j].to, siz2 = (long long)mp[u1].size() - 1ll ; 
				rep( k, 0, siz2 ) {
					int v = mp[u1][k].to ; 
					if( !vis[v] ) continue ; 
					int muu = u[r[i]] * u[r[u1]] * u[r[v]], b = mp[i][j].w, c = mp[u1][k].w, a = vis[v] ; 
					int rc = f[A / a] * ( f[B / b] * f[C / c] + f[B / c] * f[C / b] )
                            + f[A / b] * ( f[B / a] * f[C / c] + f[B / c] * f[C / a] )
                            + f[A / c] * ( f[B / a] * f[C / b] + f[ B / b ] * f[C / a] ) ; 
					Ans += muu * rc ; 
				}
			}
			rep( j, 0, siz ) vis[mp[i][j].to] = 0 ; 
		}
		printf("%d\n", Ans % P ) ;
	return 0;
}