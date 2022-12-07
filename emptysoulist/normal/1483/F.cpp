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
const int N = 2e6 + 5 ; 
struct Trie {
	int ch[27], fa, lk ; 
} t[N] ; 
int n, cnt, Ans, tree[N], ans[N], Bef[N], bef[N] ;
int dep[N], Id[N], Ed[N], L[N], R[N], idx ; 
string s[N] ; vector<int> G[N] ; queue<int> q ; 
void add(int x, int y) { G[x].pb(y) ; }
void build() {
	rep( i, 0, 25 ) 
		if(t[0].ch[i]) q.push(t[0].ch[i]) ; 
	while(!q.empty()) {
		int u = q.front() ; q.pop(), add(t[u].lk, u) ; 
		rep( i, 0, 25 ) {
			int x = t[u].ch[i] ; //if(x) printf("%d %d %c\n", u, x, i + 'a') ;
			if(!x) t[u].ch[i] = t[t[u].lk].ch[i] ;
			else t[x].lk = t[t[u].lk].ch[i], q.push(x) ; 
		}
	} 
} 
void dfs(int x, int fa) {
	L[x] = ++ idx ; bef[x] = (Ed[x]) ? x : bef[fa] ; 
	int o = (Ed[x]) ? x : Bef[x] ; 
//	printf("!! awa %d %d %d\n", x, bef[x], Bef[x] ) ; 
	for(int v : G[x]) Bef[v] = o, dfs(v, x) ; // printf("%d %d\n", x, v ) ; 
	R[x] = idx ;  
}
int lowbit(int x) { return (x & (-x)) ; }
void Add(int x, int k) {
	for(int i = x; i <= idx; i += lowbit(i)) tree[i] += k ; 
}
int query(int x) {
	int sum = 0 ; 
	for(int i = x; i; i -= lowbit(i)) sum += tree[i] ; 
	return sum ; 
}
int qry(int x) { return query(R[x]) - query(L[x] - 1) ; }
int st[N], top ; 
void check(int x, int type) {
	ans[x] += type, st[++ top] = x ; 
	if((qry(x) == ans[x])) ++ Ans ; 
}
signed main()
{
	n = gi(), cnt = 0 ; 
	rep( i, 1, n ) cin >> s[i] ; 
	rep( i, 1, n ) {
		int now = 0, ll = s[i].length() ; 
		for(int j = 0; j < ll; ++ j) {
			s[i][j] -= 'a' ; 
			if(!t[now].ch[(int)s[i][j]]) t[now].ch[(int)s[i][j]] = ++ cnt, t[cnt].fa = now ; 
			now = t[now].ch[(int)s[i][j]] ; 
		} Ed[now] = i, Id[i] = now ; 
	} 
	rep( i, 1, cnt ) dep[i]	= dep[t[i].fa] + 1 ; build(), dfs(0, 0) ; 
	rep( i, 1, n ) {
		int ll = s[i].length(), now = 0 ; 
		for(int j = 0; j < ll; ++ j) 
			now = t[now].ch[(int)s[i][j]], Add(L[now], 1) ; 
//			printf("now arrive %d %d %d\n", j, now, L[now] ) ; 
		now = 0 ; vector<int> ss ; ss.resize(ll + 1) ; 
		for(int j = 0; j < ll; ++ j) {
			now = t[now].ch[(int)s[i][j]] ; 
			int z = (j == ll - 1) ? Bef[now] : bef[now] ; 
			ss[j] = z ; 
		} int l = ll + 1 ; 
		for(int j = ll - 1; j >= 0; -- j) {
			if(ss[j]) {
				if(j - dep[ss[j]] < l) l = j - dep[ss[j]], check(ss[j], 1) ; 
			}
		}
		now = 0 ; 
		for(int j = 0; j < ll; ++ j) 
			now = t[now].ch[(int)s[i][j]], Add(L[now], -1) ;
		rep( j, 1, top ) ans[st[j]] = 0 ; top = 0 ; 
//		printf("now case %d %d\n", i, Ans ) ; 
	}
	cout << Ans << endl ; 
	return 0 ;
}
/*
4
aaabbb
ab
aabb
aaabb
*/