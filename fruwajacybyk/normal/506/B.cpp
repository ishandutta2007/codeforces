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

const int N = 100005;
const int NIL = (-1);

// scc by UJ
int n;              // INPUT
vector<int> g[N];   // INPUT

int t, in[N], low[N];
stack<int> s;
bool stacked[N];

int scc[N], scc_n;  // OUTPUT (SCC)

void tarjan(int u) {
    low[u] = in[u] = t++;
    s.push(u);
    stacked[u] = true;
    FORE(v, g[u]) {
        if (in[*v]==NIL) {
            tarjan(*v);
            low[u] = min(low[u], low[*v]);
        } else if (stacked[*v]) low[u] = min(low[u], in[*v]);
    }
    if (low[u]==in[u]) {
        for(;;) {
            int v = s.top(); s.pop();
            stacked[v] = false;
            scc[v] = scc_n;
            if (v==u) break;
        }
        scc_n++;
    }
}

void tarjan_scc() {
	FOR(i,0,n) { in[i] = low[i] = NIL; stacked[i] = false; }
	scc_n = t = 0;
	FOR(i,0,n) if(in[i]==NIL) tarjan(i);
}
//

int sajzy[max_n];
int dobre[max_n];

int matka = -1;
set<int> g2[max_n];
int color[max_n];
int reale[max_n];

void dfsMamy(int v){
	color[v] = 1;
	FORE(i,g2[v]){
		if(color[*i]==-1){
			reale[*i] = matka;
			dfsMamy(*i);
		}
	}
}


int fu[max_n];

int fufind(int u){
	return  u == fu[u] ? u : fu[u] = fufind(fu[u]);
}

void funion(int u, int v){
	u = fufind(u), v = fufind(v);
	fu[u] = v;
}

int main(){
	vector<PII> edges;
	read(n);
	make(m);
	FOR(i,0,m){
		make2(a,b); a--; b--;
		g[a].pb(b);
		edges.pb(mp(a,b));
	}
	tarjan_scc();
	int ans = 0;
	
	FOR(i,0,scc_n) sajzy[i] = 0;
	FOR(i,0,n){
		sajzy[scc[i]]++;
	}
	FOR(i,0,n) 
		if(sajzy[scc[i]]>=2) matka = scc[i];
	
	FOR(i,0,n){
		if(sajzy[scc[i]]>=2) scc[i] = matka;
	}
	if(matka!=-1){
		FOR(i,0,m){
			int a =edges[i].st, b = edges[i].nd;
			if(scc[a]!=scc[b]){
				g2[scc[b]].insert(scc[a]);
				g2[scc[a]].insert(scc[b]);
			}
	}
		FOR(i,0,scc_n) color[i] = -1,reale[i] = i;
		dfsMamy(matka);

		FOR(i,0,scc_n) scc[i] = reale[scc[i]];
		FOR(i,0,n) if(scc[i] == matka) ans++;
	}
	debug(ans);
	FOR(i,0,n) fu[i] = i;
	FOR(i,0,m){
		int a =edges[i].st, b = edges[i].nd;
		if(fufind(scc[a])!=fufind(scc[b])){
			ans++;
			funion(scc[a],scc[b]);
		}
	}
	

	


	
	printf("%d\n",ans);
}