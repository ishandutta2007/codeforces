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
#define REP(i,n) FOR(i,0,(n))
 
using namespace std;

const int max_n = 3005;

int n, m;
VI g[max_n];

int dist[max_n][max_n];
vector<PII> najg[max_n];
vector<PII> najg2[max_n];

void bfs(int v) {
	FOR(i,0,n) dist[v][i] = 5005;
	dist[v][v] = 0;
	VI w; w.pb(v);
	int j = 0;
	while (j!=w.size()) {
		int u = w[j];
		FORE(i,g[u]) {
			int u2 = *i;
			if (dist[v][u2] > dist[v][u] + 1) {
				dist[v][u2] = dist[v][u] + 1;
				w.pb(u2);
			}
		}
		j++;
	}
}

int main() {
	read2(n, m);
	FOR(i,0,m) {
		make2(a, b);
		a--; b--;
		if (a==b) continue;
		g[a].pb(b);
	}
	FOR(i,0,n) bfs(i);
	FOR(i,0,n) FOR(j,0,n) if(dist[i][j]==5005) dist[i][j] = -1e6;
	FOR(i,0,n) {
		FOR(j,0,n) {
			if (i==j || dist[i][j] < 0) continue;
			najg[i].pb(mp(dist[i][j],j));
			int k = najg[i].size();
			FORD(u,k-1,1) {
				if (najg[i][u].st > najg[i][u-1].st) swap(najg[i][u], najg[i][u-1]);
			}
			if (najg[i].size() > 3) najg[i].pop_back();
		}
	}
	FOR(i,0,n) {
		FOR(j,0,n) {
			if (i==j || dist[j][i]<0) continue;
			najg2[i].pb(mp(dist[j][i],j));
			int k = najg2[i].size();
			FORD(u,k-1,1) {
				if (najg2[i][u].st > najg2[i][u-1].st) swap(najg2[i][u], najg2[i][u-1]);
			}
			if (najg2[i].size() > 3) najg2[i].pop_back();
		}
	}
	int best = -1;
	VI dla;
	FOR(i,0,n) {
		FOR(j,0,n) {
			if (i==j) continue;
			FOR(k,0,najg2[i].size()) FOR(l,0,najg[j].size()) {
				int u1 = najg2[i][k].nd, u2 = najg[j][l].nd;
				if (u1==u2 || u1==i || u1==j || u2==i || u2==j) continue;
				int loc = dist[u1][i] + dist[i][j] + dist[j][u2];
				if (loc > best) {
					best = loc;
					dla.clear();
					dla.pb(u1); dla.pb(i); dla.pb(j); dla.pb(u2);
				}
			}
		}
	}
	//printf("%d\n", best);
	FOR(i,0,dla.size()) {
		printf("%d ", dla[i]+1);
	}
	printf("\n");


}