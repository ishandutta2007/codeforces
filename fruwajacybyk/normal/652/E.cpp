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

const int max_n = 3e5+5;

int n, m;
int s, t;
VI g1[max_n], g2[max_n];
int lev[max_n], low[max_n];
int par[max_n];

int dfs(int v, int l) {
	low[v] = l;
	FORE(i, g1[v]) {
		int w = *i;
		if (lev[w]==-1) {
			par[w] = v;
			lev[w] = l+1;
			dfs(w, l+1);
			low[v] = min(low[v], low[w]);
		} else if (w!=par[v]) {
			low[v] = min(low[v], low[w]);
		}
	}
	FORE(i, g2[v]) {
		int w = *i;
		if (lev[w]==-1) {
			par[w] = v;
			lev[w] = l+1;
			dfs(w, l+1);
			low[v] = min(low[v], low[w]);
		} else if (w!=par[v]){
			low[v] = min(low[v], low[w]);
		}
	}
}

int kolor2[max_n];

bool dfs2(int v);

bool rowne() {
	FOR(i,0,n) kolor2[i] = 0;
	return dfs2(s);
}

bool dfs2(int v) {
	kolor2[v] = 1;
	FORE(i,g1[v]) {
		int w = *i;
		if (kolor2[w]==1) continue;
		if (par[w]==v && low[w]==lev[w]) continue;
		if (par[v]==w && low[v]==lev[v]) continue;
		if(dfs2(w)) return true;
	}
	FORE(i,g2[v]) {
		int w = *i;
		if (par[w]==v && low[w]==lev[w]) continue;
		if (par[v]==w && low[v]==lev[v]) continue;
		return true;
	}
	return false;
}

set<PII> dobre_mosty;

bool czy_dobry(int v, int w) {
	if (par[v]!=w && par[w]!=v) return true;
	if (par[v]==w && low[v]==lev[v]) {
		if (dobre_mosty.find(mp(w,v))!=dobre_mosty.end()) return true;
		return false;
	} 
	if (par[w]==v && low[w]==lev[w]) {
		if (dobre_mosty.find(mp(v,w))!=dobre_mosty.end()) return true;
		return false;
	} 	
	return true;
}

bool dfs3(int v);

bool rozne() {
	int x = t;
	while (x!=s) {
		int y = par[x];
		if (low[x]==lev[x]) dobre_mosty.insert(mp(y,x));
		x = y;
	}
	
	FOR(i,0,n) kolor2[i] = 0;
	return dfs3(s);
}

bool dfs3(int v) {
	kolor2[v] = 1;
	bool ok = false;
	FORE(i,g1[v]) {
		int w = *i;
		if (kolor2[w]==1) continue;
		if (czy_dobry(v, w)) {
			if(dfs3(w)) return true;
		}
	}
	FORE(i,g2[v]) {
		int w = *i;
		if (czy_dobry(v, w)) {
			return true;
		}
	}
	return false;
}


int main() {
	read2(n, m);
	FOR(i,0,m) {
		make3(a, b, c);
		a--; b--;
		if (c==0) g1[a].pb(b), g1[b].pb(a);
		else  g2[a].pb(b), g2[b].pb(a);
	}
	read2(s, t); s--; t--;
	FOR(i,0,n) lev[i] = -1;
	lev[s] = 0; par[s] = -1;
	dfs(s, 0);
	if (s==t) {
		if (rowne()) printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	if (rozne()) printf("YES\n");
	else printf("NO\n");
}