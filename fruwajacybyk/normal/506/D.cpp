#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

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
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;
#define max_n 100005

int fup[max_n];

int find(int v){
	return v==fup[v] ? v : fup[v] = find(fup[v]);
}

vector<PII> edges[max_n];
map<int,int> comp[max_n];
map<PII,int> ansy;

int main(){
	make2(n,m);
	FOR(i,0,m){
		make3(a,b,c); a--,b--,c--;
		edges[c].pb(mp(a,b));
	}
	FOR(i,0,n) fup[i] = i;
	FOR(i,0,m){
		FORE(j,edges[i]){
			int u = j->st, v = j->nd;
			u = find(u), v = find(v);
			if(u!=v) fup[u] = v;
		}
		FORE(j,edges[i]){
			int u = j->st, v = j->nd;
			if(comp[u].find(i)==comp[u].end()) 
				comp[u].insert(mp(i,find(u)));
			if(comp[v].find(i)==comp[v].end()) 
				comp[v].insert(mp(i,find(v)));
		}
		FORE(j,edges[i]) fup[j->st] = j->st, fup[j->nd] = j->nd;
	}
	make(q);
	while(q--){
		make2(a,b); a--,b--;
		if(comp[a].size()>comp[b].size()) swap(a,b);
		if(ansy.find(mp(a,b))!=ansy.end()) 
			printf("%d\n",ansy[mp(a,b)]);
		else{
			int ans = 0;
			FORE(i,comp[a]){
				int col = i->st;
				if(comp[b].find(col)!=comp[b].end()){
					if(comp[b][col]==comp[a][col]) ans++;
				}
			}
			printf("%d\n",ans);
			ansy[mp(a,b)] = ans;
		}
	}

}