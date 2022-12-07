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
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 2e5 + 5 ; 
const int M = 500 ; 
int n, m, cnt, a[N], Id[N], tag[N], L[N], R[N] ; 
int pre[N], ll[N] ; 
void Add(int l, int r, int x) {
	if(Id[l] == Id[r]) rep( i, l, r ) a[i] -= x ; 
	else {
		for(int i = l; i <= R[Id[l]]; ++ i) a[i] -= x ;
		for(int i = Id[l] + 1; i < Id[r]; ++ i) tag[i] -= x ; 
		for(int i = L[Id[r]]; i <= r; ++ i) a[i] -= x ; 
	}
}
int qry(int x) { return max(1ll, a[x] + tag[Id[x]]) ; }
int Get(int x) {
	int g = qry(x) ; 
	if(g == 1) return 1 ; 
	return (g < ll[x]) ? g : pre[x] ;
}
set<int> S ; 
set<int>::iterator it ; 
void Rebuild(int x) {
	for(int i = L[x]; i <= R[x]; ++ i) {
		if(qry(i) < ll[i]) pre[i] = qry(i) ; 
		else pre[i] = Get(qry(i)) ;  
	}
}
signed main()
{
	n = gi(), m = gi(), cnt = sqrt(n) + 1 ; 
	rep( i, 2, n ) a[i] = gi() ; 
	int idx = 0 ; L[++ idx] = 1 ; 
	rep( i, 1, n ) {
		Id[i] = idx ; 
		if(!(i % cnt)) R[idx] = i, L[++ idx] = i + 1 ; 
	} R[idx] = n ; pre[1] = 1 ; 
	rep( i, 2, n ) {
		int u = L[Id[i]] ; ll[i] = u ; 
		if(a[i] < u) pre[i] = a[i] ;
		else pre[i] = pre[a[i]], S.insert((int)i) ; 
	} 
	rep( i, 1, m ) {
		int opt = gi(), l = gi(), r = gi() ; 
		if(opt == 1) {
			int x = gi() ; Add(l, r, x) ; 
			if(!S.empty()) {	
				it = S.lower_bound(l) ; 
				vector<int> del ; 
				for(; it != S.end(); ++ it) {
					int u = (*it) ; 
					if(u > r) break ; 
					int d = qry(u) ; 
					if(d < ll[u]) del.pb(u) ; 
					else pre[u] = Get(d) ; 
				}
				for(int v : del) S.erase(v) ; 
				Rebuild(Id[l]), Rebuild(Id[r]) ; 
			}
		} else {
			int u = l, v = r ; 
			while(Get(u) != Get(v)) {
				if(Get(u) < Get(v)) swap(u, v) ; 
				u = Get(u) ; 
			}
			while(u != v) {
				if(u < v) swap(u, v) ; 
				u = qry(u) ; 
			}
			printf("%lld\n", u ) ; 
		}
	}
	return 0 ;
}