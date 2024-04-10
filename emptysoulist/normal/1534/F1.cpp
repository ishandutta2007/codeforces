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
const int N = 4e5 + 5 ; 
int n,m,color,deg[N],col[N],dfn[N],low[N],idx,top,st[N];
string s[N] ; 
vector<int>a[N],G[N];
set<int>S;
set<int>::iterator it ; 
void add(int x, int y){
	G[x].pb(y);
	//printf("%d %d\n",x, y);
	//printf("(%d,%d) -> (%d,%d)\n", (x-1)/m+1,(x-1)%m+1,(y-1)/m+1,(y-1)%m+1);
}
void tarjan(int x) {
	low[x] = dfn[x] = ++ idx, st[++ top] = x ; 
	for(int v : G[x]) {
		if(!dfn[v]) tarjan(v), low[x] = min(low[x], low[v]) ;
		else if(!col[v]) low[x] = min(low[x], dfn[v]) ; 
	}
	if(low[x] != dfn[x]) return ; ++color;
	while(st[top] != x) col[st[top]] = color, -- top ; col[x] = color, -- top ;
}
int Id(int x, int y){
	return (x-1)*m+y;
}
signed main() {
	n = gi(), m = gi() ; 
	rep(i,1,n)cin>>s[i];
	rep(i,0,n)a[i].resize(m+1);
	rep(i,1,n)rep(j,1,m)
		a[i][j]=(s[i][j-1]=='#');
	rep(j,1,m){
		rep(i,1,n)if(a[i][j]){
			it = S.lower_bound(i);
			if(it!=S.end())add(Id(i,j),Id((*it),j-1));
		}S.clear();
		rep(i,1,n)if(a[i][j])S.insert(i);
		rep(i,1,n)if(a[i][j]){
			it=S.upper_bound(i);
			if(it!=S.end())add(Id(i,j),Id((*it),j));
			if(a[i-1][j])add(Id(i,j),Id(i-1,j));
		}
		rep(i,1,n)if(a[i][j-1]){
			it=S.lower_bound(i);
			if(it!=S.end())add(Id(i,j-1),Id((*it),j));
		}
	}
	rep(i,1,n)rep(j,1,m)
	if(!dfn[Id(i,j)] && a[i][j]) tarjan(Id(i,j));
	rep(i,1,n)rep(j,1,m)if(a[i][j]){
		int u=col[Id(i,j)];
	//	cout<<Id(i,j)<<" -belong to "<< u<<endl;
		for(int v:G[Id(i,j)])
		if(col[v]!=u)++deg[col[v]];
	}int ans=0;
	rep(i,1,color)if(!deg[i]) ++ans;
	cout<<ans<<endl;
	return 0 ;
}