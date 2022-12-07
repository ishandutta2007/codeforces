#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
#define pb push_back
#define vi vector<int>
#define fr front()
#define bk back()
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
deque<int> f[10] ;
struct node {
	int x, y ; 
	node(int _x = 0, int _y = 0) {
		x = _x, y = _y ; 
	}
} ;
struct Sunward {
	vi x ; 
	int y, z ; 
	Sunward(vi _x, int _y = 0, int _z = 0) {
		x = _x, y = _y, z = _z ;
	}
	bool operator < (Sunward &a) const {
		return (x == a.x) ? ( (y == a.y) ? z < a.z : y < a.y ) : x < a.x ; 
	}
} ;
vector<Sunward> Isaunoya ;
vector<node> G, bb ;
int n, a[N] ;
void solve1(int zz) {
	vi tmp ; int zf = 0 ; 
	int zk = n, t1 = zz, t2 = 0 ;
	if( !f[2].empty() ) {
		++ zf, t2 = f[2].bk ; 
		if( zk == 0 ) ++ zf ; 
		f[2].pop_back(), -- zk ;
	}
	while (!f[3].empty() && f[3].fr < (t2 ? t2 : t1)) {
		tmp.pb(f[3].fr) ; 
		if( zf == 0 ) ++ zk ; 
		f[3].pop_front();
	}
	Isaunoya.pb(Sunward(tmp, t2, t1));
}
void Solve() {
	int ans = 1, fgo = 0 ;
	for (Sunward ff : Isaunoya) {
		vi x = ff.x ; 
		for( re int i = 0; i < x.size(); ++ i ) {
			G.pb(node(ans, x[i])) ;
			if( (i + 1) < x.size() ) G.pb(node(ans, x[i + 1]));
			++ ans ;
		}
		int sff = ff.y ; 
		if( sff ) {
			if( !fgo ) ++ fgo ; 
			if (!x.empty()) G.pb(node(ans - 1, ff.y));
			bb.pb(node(fgo, ff.y)) ; 
			G.pb(node(ans , ff.y));
		} 
		else if( !x.empty() ) {
			if( !fgo ) ++ fgo ; 
			bb.pb(node(fgo, ff.z)) ; 
			G.pb(node(ans - 1, ff.z)) ;
		}
		G.pb(node(ans, ff.z)), ++ ans ;
	}
}
signed main() {
	n = gi() ; 
	rep( i, 1, n ) a[i] = gi() ; 
	rep( i, 1, n ) {
		if( a[i] == 1 ) solve1(i) ; 
		else f[a[i]].pb(i) ;
	}
	if( f[2].size() || f[3].size() ) {
		puts("-1") ; exit(0) ; 
	}
	Solve() ; 
	printf("%lld\n", (int)G.size());
	for( node x : G ) 
		printf("%lld %lld\n", x.x, x.y ) ;
	return 0 ; 
}