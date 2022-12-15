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

const int max_n = 2e5 + 5;

int n;
VI v;

int lft[max_n];
int rght[max_n];
lint pref[max_n];

lint ask(int p1, int p2) {
	return pref[p2] - pref[p1-1];
}

int fl(int x) {
	return (lft[x] == x) ? x : lft[x] = fl(lft[x]);
}

int fr(int x) {
	return (rght[x] == x) ? x : rght[x] = fr(rght[x]);
}

int main() {
	read(n);
	v.pb(0);
	readv(v, n);
	pref[0] = 0;
	FOR(i,0,n) pref[i+1] = pref[i] + v[i+1];
	makev(kol,n);
	FOR(i,0,n+2) lft[i] = rght[i] = i;
	lint best = 0;
	vector<lint> ans;
	ans.pb(0);
	reverse(all(kol));
	FOR(i,0,n - 1) {
		int ja = kol[i];
		lft[ja] = fl(ja - 1);
		rght[ja] = fr(ja + 1);
		best = max(best, ask(lft[ja]+1, rght[ja] - 1));
		ans.pb(best);
	}
	FORD(i,n-1,0) {
		printf("%lld\n", ans[i]);
	}
}