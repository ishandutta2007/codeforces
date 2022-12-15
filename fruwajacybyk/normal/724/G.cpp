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

const int max_n = 1e5 + 5;
const lint mod = 1e9 + 7;

int n, m;
vector<pair<int, lint> >  g[max_n];
lint ans = 0;
int kolor[max_n];
map<int, lint> cyc;
map<int, lint> odl;

void dodaj_cykl(lint z) {
	lint loc = z;
	FOR(i,0,61) {
		if ( (loc & (1LL<<i)) && cyc.find(i) == cyc.end()) {
			cyc[i] = loc;
			return;
		} else if (loc & (1LL<<i)) {
			loc ^= cyc[i];
		}
	}
}


void dfs_visit(int v, lint sofar) {
	kolor[v] = 1;
	odl[v] = sofar;
	FORE(i, g[v]) {
		int w = i->st;
		lint psiu = i->nd;
		if (kolor[w] == 0) {
			dfs_visit(w, psiu ^ sofar);
		} else {
			dodaj_cykl(psiu ^ sofar ^ odl[w]);
		}
	}
}

lint e1[100];
lint e0[100];
int jest[100];
lint half = (mod + 1)/2;

void DFS(int v) {
	cyc.clear();
	odl.clear();
	dfs_visit(v, 0);
	FOR(i,0,61) e1[i] = e0[i] = jest[i] = 0;
	FORE(i, odl) {
		lint z = i->nd;
		FOR(j,0,61) if (z&(1LL<<j)) e1[j]++; else e0[j]++;
	}
	FORE(j, cyc) {
		lint x = j->nd;
		FOR(i,0,61) if(x&(1LL<<i)) jest[i] = 1;
	}
	int mocz = cyc.size();
	FOR(i,0,61) {
		lint war = (1LL<<i) % mod;
		lint ile0 = (e0[i] * 1LL * e0[i] + e1[i] * 1LL * e1[i]) % mod;
		ile0 = (ile0 + (mod - e0[i]) + (mod - e1[i])) % mod;
		ile0 = (ile0 * 1LL * half) % mod;
		lint ile1 = (e1[i] * 1LL * e0[i]) % mod;


		if (jest[i]) {
			ans += (((1LL<<i)%mod) * 1LL * ((((1LL<<(mocz-1)) % mod) * 1LL * (ile0 + ile1))%mod))%mod;
			ans %= mod;
		} else {
			lint sz = (1LL<<mocz) % mod;
			ans += (((1LL<<i)%mod) * 1LL * ((sz * 1LL * ile1) % mod)) % mod;
			ans %= mod;
		}
	}
}



int main() {
	read2(n, m);
	FOR(i,0,m) {
		make2(a, b);
		a--; b--;
		lint t; scanf("%lld", &t);
		g[a].pb(mp(b, t));
		g[b].pb(mp(a, t));
	}
	FOR(i,0,n) kolor[i] = 0;
	FOR(i,0,n) {
		if(kolor[i] == 0) DFS(i);
	}
	printf("%d\n", ans);
}