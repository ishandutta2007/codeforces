#include <bits/stdc++.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()
 
#define PII pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define pb push_back
#define lint long long int
#define VI vector<int>
 
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

const int max_n = 5e5 + 5;

int N;
VI v;
VI w[max_n];
VI goscie;

// USAGE:
// add_vertex(side) (dodaj wierzchoek po lewej 0 lub prawej stronie 1)
// add_edge(u,v) dodaj krawedz
// matching oblicz

struct TurboMatching{  
	int n = 0;
	VI g[max_n];   
	VI left;
	int m1[max_n], m2[max_n];   
	bool c[max_n];

	void add_vertex(int side){
		if(side == 0) left.pb(n);
		n++;
	}

	void add_edge(int u,int v){
		g[u].pb(v);
		g[v].pb(u);
	}

	bool dfs(int u) {
    if (u<0) return true;
    if (c[u]) return false; else c[u]=true;
    FORE(v, g[u]) 
        if (dfs(m2[*v])) { m1[u] = *v; m2[*v] = u; return true; }
    return false;
	}

	void clear() {
		FOR(i,0,n) g[i].clear();
		n = 0;
		left.clear();
	}

	int matching() {
    FOR(i,0,n) m1[i]=-1;
    FOR(i,0,n) m2[i]=-1;
    bool changed;
    do {
        changed = 0;
        FORE(i,left) c[*i]=false;
        FORE(i,left) if (m1[*i]<0) changed |= dfs(*i);
    } while(changed);
    int siz = 0;
    FORE(i,left) siz += (m1[*i]!=-1);
    return siz;
	}
};


TurboMatching TM;

bool check(int x) {
	TM.clear();
	FOR(i,0,N) TM.add_vertex(0);
	FOR(i,0,x+1) TM.add_vertex(1);
	FOR(i,0,N) {
		FOR(j,0,w[i].size()) {
			if (w[i][j] > x) break;
			else TM.add_edge(i, w[i][j] + N);
		}
	}
	if (TM.matching() == N) return true;
	else return false;
}

int main() {
	read(N);
	readv(v, N);
	set<int> dupa;
	FOR(i,0,N) {
		int ja = v[i];
		while (ja != 0) {
			w[i].pb(ja);
			dupa.insert(ja);
			ja = ja/2;
		}
		sort(all(w[i]));
	}
	FORE(i, dupa) goscie.pb(*i);
	unordered_map<int, int> dupka;
	FOR(i,0, goscie.size()) dupka[goscie[i]] = i;
	FOR(i,0,N) {
		FOR(j,0,w[i].size()) w[i][j] = dupka[w[i][j]];
	}
	
	int lewo = N-1;
	int prawo = goscie.size() - 1;
	while (prawo - lewo > 1) {
		int mid = (prawo + lewo) / 2;
		if (check(mid)) prawo = mid;
		else lewo = mid;
	}
	if (check(lewo));
	else check(lewo + 1);
	FOR(i,0,N) {
		printf("%d ",goscie[TM.m1[i]-N]);
	}
	printf("\n");
}