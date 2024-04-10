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
const int mod = 1e9 + 7;

map<PII, vector<PII> > mapka;

void add(int x, int y, int z, int i) {
	if (mapka.find(mp(x,y)) != mapka.end()) {
		mapka[mp(x,y)].pb(mp(z,i));
	}
	else {
		vector<PII> dupa; dupa.pb(mp(z,i));
		mapka[mp(x,y)] = dupa;
	}
}

int main() {
	make(n);
	int ans1 = 0;
	int dla1 = 0;
	for (int i = 0; i < n; i++) {
		makev(v, 3);
		sort(all(v));
		if (v[0] > ans1) {
			ans1 = v[0];
			dla1 = i+1;
		}
		add(v[0], v[1], v[2],  i + 1);
		if (v[0] == v[2]) continue;
		add(v[1], v[2], v[0],  i + 1);
		if (v[0] == v[1] || v[1] == v[2]) continue;
		add(v[0], v[2], v[1],  i + 1);
	}
	int ans2 = 0;
	PII dla2;
	FORE(i, mapka) {
		if (i->nd.size() > 1) {
			sort(all(i->nd), greater<PII>());
			int myns = min(i->st.st, i->nd[1].st+i->nd[0].st);
			if (myns > ans2) {
				ans2 = myns;
				dla2 = mp(i->nd[0].nd, i->nd[1].nd);
			}
		}
	}
	if (ans1 > ans2) {
		printf("1\n%d\n", dla1);
	} else {
		printf("2\n%d %d\n", dla2.st, dla2.nd);
	}
}