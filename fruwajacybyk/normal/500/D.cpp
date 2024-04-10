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

vector<PII> edges;
VI costs;

vector<PII> g[max_n];
int tu[max_n];
double prob[max_n];
double act[max_n];

int dfs(int v,int par){
	int ile = 1;
	FOR(i,0,g[v].size()){
		if(g[v][i].st!=par){
			tu[g[v][i].nd] = dfs(g[v][i].st,v);
			ile+= tu[g[v][i].nd];
		}
	}
	return ile;
}

lint po3(lint u){
	return (u*(u-1)*(u-2))/6LL;
}

int main(){
	make(n);
	FOR(i,0,n-1){
		make3(a,b,l);
		a--; b--;
		edges.pb(mp(a,b));
		costs.pb(l);
		g[a].pb(mp(b,i));
		g[b].pb(mp(a,i));
	}
	dfs(0,-1);
	FOR(i,0,edges.size()){
		prob[i] = 2.*((po3(n)-po3(tu[i])-po3(n-tu[i]))*1.)/(po3(n)*1.);
	}
	double ans = 0.;
	FOR(i,0,edges.size()){
		act[i] = costs[i] *1.*prob[i];
		ans += act[i];
	}
	make(q);
	while(q--){
		make2(a,l);
		a--; 
		ans-= act[a];
		act[a] = prob[a]*1.*l;
		ans+= act[a];
		printf("%.17lf\n",ans);
	}
	
	

}