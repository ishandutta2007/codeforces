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
 
const int max_n = 2e6+5;

int n;
VI g[max_n];
set<int> g2[max_n];
int deg[max_n];
int lab[max_n];
int ex[max_n];
int znak[max_n];
int znak2[max_n];
VI dupa[max_n];

inline bool poloczone(int u, int v) {
	return (g2[v].find(u) != g2[v].end());
}

void dfs(int v) {
	FORE(i, g[v]) {
		int w = *i;
		if (lab[w] == -1) {
			int myl = lab[v];
			if (ex[myl-1] != -1 && ex[myl-2]!=-1) {
				bool b1 = poloczone(w, ex[myl-1]);
				bool b2 = poloczone(w, ex[myl-2]);
				if (b1 && b2) lab[w] = myl-1;
				if (b1 && !b2) lab[w] = myl;
				if (!b1) lab[w] = myl+1;
				ex[lab[w]] = w;
			} else if (ex[myl+1] != -1 && ex[myl+2]!=-1) {
				bool b1 = poloczone(w, ex[myl+1]);
				bool b2 = poloczone(w, ex[myl+2]);
				if (b1 && b2) lab[w] = myl+1;
				if (b1 && !b2) lab[w] = myl;
				if (!b1) lab[w] = myl-1;
				ex[lab[w]] = w;
			} else if (ex[myl+1] != -1 && ex[myl-1] != -1) {
				bool b1 = poloczone(w, ex[myl-1]);
				bool b2 = poloczone(w, ex[myl+1]);
				if (b1 && b2) lab[w] = myl;
				else if (b1) lab[w] = myl-1;
				else lab[w] = myl+1;
				ex[lab[w]] = w;
			}
			dfs(w);
		}
	}
}

void check() {
	FOR(i,0,n) {
		FORE(j, g[i]) {
			int v = *j;
			if (lab[v]-lab[i] > 1 || lab[i]-lab[v] > 1) {
				printf("NO\n");
				return ;
			}
		}
	}
	int maxlab = lab[0];
	int minlab = lab[1];
	FOR(i,0,n) {
		maxlab = max(maxlab, lab[i]);
		minlab = min(minlab, lab[i]);
		dupa[lab[i]].pb(i);
	}
	FOR(i,minlab, maxlab+1) {
		FORE(j, dupa[i]) {
			int v = *j;
			FOR(ki, -1,2) {
				FORE(u, dupa[i+ki]) {
					int w = *u;
					if (w == v) continue;
					if (!poloczone(w, v)) {
						printf("NO\n");
						return;
					}
				}
			}
		}
	}
	

	printf("YES\n");
	FOR(i,0,n) {
		printf("%d ", lab[i]);
	}
	printf("\n");
}

int main() {
	read(n);
	make(m);
	FOR(i,0,m) {
		make2(a, b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
		g2[a].insert(b);
		g2[b].insert(a);
		deg[a]++; deg[b]++;
	}
	int OFF = 1e6;
	FOR(i,0,n) lab[i] = -1;
	FOR(i,OFF-n-10,OFF+n+10) ex[i] = -1;
	int maxdeg = 0;
	int dla = -1;
	FOR(i,0,n) {
		if (deg[i] > maxdeg) {
			maxdeg = max(maxdeg, deg[i]);
			dla = i;
		}
	}
	if (maxdeg == n-1) {
		FOR(i,0,n) if (deg[i] == n-1) lab[i] = 0 + OFF;
		int gosc = -1;
		FOR(i,0,n) {
			if (deg[i] != n-1) gosc = i;
		}
		if (gosc == -1) {
			FOR(i,0,n) lab[i] = 0+OFF;
		} else {
			FOR(i,0,n) if (deg[i] == n-1) lab[i] = 0+OFF;
			lab[gosc] = 1 + OFF;
			FORE(j, g[gosc]) {
				int v = *j;
				if (lab[v] != 0 + OFF) lab[v] = 1 + OFF;
			}
			FOR(i,0,n) {
				if (lab[i] == -1) lab[i] = -1 + OFF;
			}
		}
		check();
	} else {
		lab[0] = 0+OFF;
		ex[lab[0]] = 0;
		FOR(i,0,n) znak[i] = znak2[i] = -1;
		znak[0] = 0;
		FORE(i, g[0]) {
			znak[*i] = 1;
			FORE(j, g[*i]) {
				znak2[*j] = *i;
			}
		}
		int gosc1 = -1;
		int gosc2 = -2;
		FOR(i,0,n) {
			if (znak[i] == -1 && znak2[i]!=-1) {
				gosc2 = i;
				gosc1 = znak2[i];
				break;
			}
		}
		lab[gosc1] = 1 + OFF;
		lab[gosc2] = 2 + OFF;
		ex[lab[gosc1]] = gosc1;
		ex[lab[gosc2]] = gosc2;
		dfs(0); dfs(gosc1); dfs(gosc2);
		check();
	}
		

}