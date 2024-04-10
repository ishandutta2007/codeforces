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

const int max_n = 1e6+5;

lint wynik[max_n];

int main() {
	make2(n, k);
	make2(s, t);
	vector<PII> cars;
	FOR(i,0,n) {
		make2(a, b);
		cars.pb(mp(b, a));
	}
	makev(v, k);
	sort(all(v));
	int start = 0, meta = s;
	VI x;
	FOR(i,0,k) {
		if (i==0) x.pb(v[i]);
		else x.pb(v[i]-v[i-1]);
	}
	x.pb(meta-v[k-1]);
	sort(all(x));
	sort(all(cars));
	int best = 1e9 + 5;
	FOR(i,0,cars.size()) {
		if (cars[i].st < x.back()) continue;
		wynik[i] = 3LL*s - cars[i].st*1LL*x.size();
	}
	lint minus = 0;
	int ile = 0;
	int xpos = 0;
	FOR(i,0,cars.size()) {
		if (cars[i].st < x.back()) continue;
		while (xpos < x.size() && cars[i].st >= 2*x[xpos]) {
			ile++;
			minus += 2*x[xpos];
			xpos++;
		}
		wynik[i] += cars[i].st * 1LL * ile - minus;
		if (wynik[i] <= t) {
			best = min(best, cars[i].nd);
		}
	}
	if (best == 1e9 + 5) printf("-1\n");
	else printf("%d\n", best);
}