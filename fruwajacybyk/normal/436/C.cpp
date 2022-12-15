#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 100005

int d[1005][1005];
char s[1005][15][15];

int fup[1005];

int fu(int x){
	return x==fup[x] ? x : fup[x] = fu(fup[x]);
}

void fuN(int x,int y){
	int xx = fu(x), yy = fu(y);
	fup[xx] = yy;
}

VI g[1005];
int byl[1005];
int mod = 0;

void dfs(int u){
	byl[u] = 1;
	FORE(i,g[u]){
		if(byl[*i]==0){
			printf("%d %d\n",(*i)+1,(u+1)%mod);
			dfs(*i);	
		}
	}
}

int main(){
	make2(n,m);
	make2(k,w);
	mod = k+1;
	FOR(i,0,k){
		FOR(j,0,n) scanf("%s",s[i][j]);
	}

	FOR(i,0,k) FOR(j,0,k) d[i][j] = 0;

	FOR(i,0,k) FOR(j,i+1,k){
		FOR(u,0,n) FOR(v,0,m) 
			if(s[i][u][v]!=s[j][u][v]) d[i][j]+=w,d[j][i]+=w;
	}
	FOR(i,0,k) d[i][k] = d[k][i] = n*m;
	vector<pair<int,PII> > edges;
	FOR(i,0,k+1) FOR(j,i+1,k+1) edges.pb(mp(d[i][j],mp(i,j)));
	sort(edges.begin(),edges.end());
	
	FOR(i,0,k+1) fup[i] = i;
	int ans = 0;
	FOR(j,0,edges.size()){
		int x1 = edges[j].nd.st;
		int x2 = edges[j].nd.nd;
		if(fu(x1)!=fu(x2)){
			fuN(x1,x2);
			ans+= edges[j].st;
			g[x1].pb(x2);
			g[x2].pb(x1);
		}
	}
	FOR(j,0,k+1) byl[j] = 0;
	printf("%d\n",ans);
	dfs(k);

	return 0;
}