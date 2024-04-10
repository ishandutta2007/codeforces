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
const int N = 3e5 + 5 ; 
int n, ans, num, l[N], r[N], dfn[N], idx ; 
vi G[N], E[N] ; 
void dfs2(int x) {
	l[x] = ++ idx, dfn[idx] = x ; 
	for(int v : E[x]) dfs2(v) ;
	r[x] = idx ; 
}
set<int>::iterator it ; 
set<int> S ; 
void dfs1(int x) {
	it = S.lower_bound(l[x]) ; 
	int flag = 0, del = 0, chk1 = 0 ; 
	if(it == S.end()) chk1 = 1 ; 
	else {
		int u = dfn[(*it)] ; 
		if(r[u] > r[x]) chk1 = 1 ; 
	}
	if(chk1) {
		if(it != S.begin()) {
			-- it ; int u = dfn[(*it)] ; 
			if(l[u] <= l[x] && r[x] <= r[u]) 
				flag = (*it), S.erase(it), S.insert(l[x]), del = l[x] ; 
			else S.insert(l[x]), del = l[x], ++ num ; 
		} else S.insert(l[x]), del = l[x], ++ num ; 
	}
	ans = max(ans, num) ; 
	for(int v : G[x]) 
		dfs1(v) ; 
	if(flag) S.insert(flag), ++ num ;  
	if(del) S.erase(del), -- num ; 
}
void solve() { 
	n = gi() ; int a, b ; num = 0, idx = 0, ans = 0 ; 
	rep( i, 2, n ) a = gi(), G[a].pb(i) ;
	rep( i, 2, n ) b = gi(), E[b].pb(i) ; 
	dfs2(1), dfs1(1) ; 
	printf("%d\n", ans ), S.clear() ; 
	rep( i, 1, n ) G[i].clear(), E[i].clear() ; 
}
signed main()
{
	int t = gi() ; 
	while( t-- ) solve() ; 
	return 0 ;
}