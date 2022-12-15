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

const int INF = 2e9;



void solve() {
	make(n);
	makev(v, n);
	int best = v[0];
	lint cost = 0;
	unordered_map<int, int> dupa;
	dupa[v[0]] = 0;
	dupa[-INF] = -1;
	FOR(i, 1, n) {
		unordered_map<int, int> dupa2;
		FORE(j, dupa) {
			dupa2.insert(mp(j->st + 1, j->nd));
		} dupa = dupa2;
		int maxileft = -INF;
		
		int minizero = INF;
		FORE(j, dupa) {
			if (j->nd >= 0) minizero = min(minizero, j->st);
		}
		cost += max(minizero-v[i], 0);
		
		FORE(j, dupa) {
			if (j->st < v[i]) {
				dupa[j->st] = j->nd - 1;
				maxileft = max(maxileft, j->st);
			} 
			if (j->st > v[i]) {
				dupa[j->st] = j->nd + 1;
			} 
			if (j->st == v[i]) {
				maxileft = v[i];
				dupa[j->st] += 1;
			}
		}
		if (dupa.find(v[i]) == dupa.end()) {
			dupa[v[i]] = dupa[maxileft] + 2;
		}
		int ans = INF;
		FORE(j, dupa) {
			if (j->nd >= 0) ans = min(ans, j->st);
			if (dupa[j->st] > 0) dupa[j->st] = 0;
		}
		

	}
	printf("%lld\n", cost);
}




int main() {
	int z = 1;
	// read(z);
	while (z--) {
		solve();
	}
}