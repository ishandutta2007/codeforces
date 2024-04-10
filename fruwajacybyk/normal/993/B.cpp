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

int n, m;
set<int> dupa[11][11];
set<int> dupa2[11][11];


int main() {
	read2(n, m);
	set<PII> v, w;
	FOR(i,0,n) {
		make2(a, b); v.insert(mp(a,b));
		v.insert(mp(b,a));
	}
	FOR(i,0,m) {
		make2(a, b); w.insert(mp(a,b));
		w.insert(mp(b,a));
	}
	vector<pair<PII, int> > pos;
	set<int> wsp;
	FOR(i,1,10) FOR(j,1,10) FOR(k,1,10) {
		if (i == j || j == k || i == k) continue;
		if (v.find(mp(i,j)) != v.end() && w.find(mp(j,k)) != w.end()) {
			pos.pb(mp(mp(i,k),j));
			wsp.insert(j);
		}
	}
	if (wsp.size() == 1) {
		printf("%d\n", *wsp.begin());
		return 0;
	} else {
		bool ok = true;
		FOR(u,0,pos.size()) {
			int i = pos[u].st.st;
			int j = pos[u].nd;
			int k = pos[u].st.nd;
			dupa[i][j].insert(j);
			dupa[j][i].insert(j);
			dupa2[j][k].insert(j);
			dupa2[k][j].insert(j);
			if (dupa[i][j].size() > 1) ok = false;
			if (dupa[j][i].size() > 1) ok = false;
			if (dupa2[k][j].size() > 1) ok = false;
			if (dupa2[j][k].size() > 1) ok = false;
		}
		if (ok) {
			printf("0\n");
			return 0;
		}
	}
	printf("-1\n");
}