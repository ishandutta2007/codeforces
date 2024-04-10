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

#define max_n 200005

VI vx, vy;
int xi1, yi1, xi2, yi2;

lint dist1(int u) {
	return (vx[u]-xi1) * 1LL *(vx[u]-xi1) + (vy[u]-yi1) * 1LL * (vy[u]-yi1);
}

lint dist2(int u) {
	return (vx[u]-xi2) * 1LL *(vx[u]-xi2) + (vy[u]-yi2) * 1LL * (vy[u]-yi2);
}


int main() {
	make(n);
	read2(xi1, yi1);
	read2(xi2, yi2);

	FOR(i,0,n) {
		make2(x,y);
		vx.pb(x); vy.pb(y);
	}

	lint ans = 1e9 *1LL*1e9;
	lint xxx = 0;
	FOR(i,0,n) xxx = max(xxx, dist2(i));
	ans = xxx;
	FOR(i, 0, n) {
		lint d1 = dist1(i);
		lint d2 = 0;
		FOR(j,0,n) {
			if(dist1(j) > d1) d2 = max(d2, dist2(j));
		}
		ans = min (ans, d1 + d2);
	}
	printf("%I64d\n", ans);

}