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

const int max_n = 1e3 + 5;

int n, m, s, t, L;

vector<PII> dodatkowe;
vector<PII> g[max_n];

int dist[max_n];
int poprz[max_n];

void dijkstra() {
	FOR(i,0,n) dist[i] = 1e9 + 1;
	dist[s] = 0;
	HEAP<PII> q;
	q.push(mp(0,s));
	while (!q.empty()) {
		int v = q.top().nd;
		q.pop();
		FORE(j, g[v]) {
			if (dist[j->st] > dist[v] + j->nd) {
				dist[j->st] = dist[v] + j->nd;
				poprz[j->st] = v;
				q.push(mp(-dist[j->st], j->st));
			}
		}
	}
}

map<PII, int> dst;

void solve() {
	read3(n, m, L);
	read2(s, t);
	vector<PII> krawedzie;
	FOR(i,0,m) {
		make3(a, b, c);
		krawedzie.pb(mp(a,b));
		if (c == 0) dodatkowe.pb(mp(a,b));
		else {
			g[a].pb(mp(b,c));
			g[b].pb(mp(a,c));
			dst[mp(a,b)] = c;
			dst[mp(b,a)] = c;
		}
	}
	dijkstra();
	if (dist[t] < L) { printf("NO\n"); return ;}
	if (dist[t] == L) {
		printf("YES\n");
		FORE(i, krawedzie) {
			if (dst.find(*i) != dst.end())
				printf("%d %d %d\n", i->st, i->nd, dst[*i]);
			else printf("%d %d %d\n", i->st, i->nd, L+1);
		}
		return;
	}
	map<PII, PII> gdzie;
	FORE(j, dodatkowe) {
		g[j->st].pb(mp(j->nd, 1));
		g[j->nd].pb(mp(j->st, 1));
		gdzie[*j] = mp(g[j->st].size() - 1, g[j->nd].size() - 1);
		gdzie[mp(j->nd, j->st)] = mp(g[j->nd].size() - 1, g[j->st].size() - 1);
		dst[mp(j->st, j->nd)] = 1;
		dst[mp(j->nd, j->st)] = 1;
	}
	dijkstra();
	if (dist[t] > L) {
		printf("NO\n");
		return;
	}
	if (dist[t] == L) {
		printf("YES\n");
		FORE(i, krawedzie) printf("%d %d %d\n", i->st, i->nd, dst[*i]);
		return;
	}
	printf("YES\n");
	while (1) {
		int act = t;
		int pact = poprz[t];
		int sofar = 0;
		while (gdzie.find(mp(act, pact)) == gdzie.end()) {
			sofar += dst[mp(act, pact)];
			act = pact;
			pact = poprz[pact];
		}
		int niu = L - dist[pact] - sofar;
		dst[mp(act, pact)] = niu;
		dst[mp(pact, act)] = niu;
		PII zzz = gdzie[mp(act, pact)];
		g[act][zzz.st] = mp(g[act][zzz.st].st, niu);
		g[pact][zzz.nd] = mp(g[pact][zzz.nd].st, niu);
		dijkstra();
		if (dist[t] == L) {
			FORE(i, krawedzie) printf("%d %d %d\n", i->st, i->nd, dst[*i]);
			return;
		}
	}

}

int main() {
	srand(time(NULL));
	int z = 1;
	// read(z);
	while (z--) {
		solve();
	}
}