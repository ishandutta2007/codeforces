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

int n, w, h;
int g[max_n];
int p[max_n];
int t[max_n];
map<int, VI> mapa[2];

PII ans[max_n];
VI kij;
void dodaj(int nr, int co, int kto) {
	if (mapa[nr].find(co) == mapa[nr].end()) {
		VI v; v.pb(kto);
		mapa[nr].insert(mp(co, v));
	} else {
		mapa[nr][co].pb(kto);
	}
}

set<int> done;

int main() {
	read3(n, w, h);
	kij.pb(w); kij.pb(h);
	FOR(i,0,n) {
		make3(a, b, c);
		g[i] = a; p[i] = b; t[i] = c;
		dodaj(g[i] - 1, t[i]-p[i], i);
	}
	FOR(i,0,n) {
		if (done.find(t[i]-p[i]) != done.end()) continue;
		bool juz = false;
		FOR(j,0,2) {
			if (mapa[j][t[i]-p[i]].size() == 0) {
					juz = true;
					FORE(u, mapa[1-j][t[i]-p[i]]) {
						if (j == 1) ans[*u] = mp(p[*u],h);
						else ans[*u] = mp(w, p[*u]);
					}
			}
		}
		if (!juz) {
			vector<pair<PII,int> > moi;
			vector<PII > wyniki;
			FORE(j, mapa[0][t[i]-p[i]]) {
				moi.pb(mp(mp(-p[*j], 0), *j));
				wyniki.pb(mp(-p[*j], h));
			}
			FORE(j, mapa[1][t[i]-p[i]]) {
				moi.pb(mp(mp(0, p[*j]),*j));
				wyniki.pb(mp(-w, p[*j]));
			}
			sort(all(moi));
			sort(all(wyniki));
			FOR(j,0,moi.size()) {
				ans[moi[j].nd] = wyniki[j];
			}
		}
		done.insert(t[i]-p[i]);
	}
	FOR(i,0,n) {
		printf("%d %d\n", abs(ans[i].st), ans[i].nd);
	}
}