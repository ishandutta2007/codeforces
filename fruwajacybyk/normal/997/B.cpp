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

#define CD complex<double>
#define PDD pair<double, double> 
using namespace std;

int moge[2000005];

int main() {
	make(n);
	if (49*1LL*n <= 2e6) {
		FOR(i,0,49*1LL*n+1) moge[i] = 1e9;
		moge[0] = 0;
		int ans = 1;
		FOR(i,1,49*n+1) {
			if (i-4 >= 0) moge[i] = min(moge[i-4]+1, moge[i]);
			if (i-9 >= 0) moge[i] = min(moge[i-9]+1, moge[i]);
			if (i-49 >= 0) moge[i] = min(moge[i-49]+1, moge[i]);
			if (moge[i] <= n) ans++;
		}
		printf("%d\n", ans);
	} else {
		FOR(i,0,1e5) moge[i] = 1e9+1;
		moge[0] = 0;
		lint ans = 1;
		FOR(i,1,1e5) {
			if (i-4 >= 0) moge[i] = min(moge[i-4]+1, moge[i]);
			if (i-9 >= 0) moge[i] = min(moge[i-9]+1, moge[i]);
			if (i-49 >= 0) moge[i] = min(moge[i-49]+1, moge[i]);
			if (moge[i] <= n) ans++;
		}
		ans += (49*1LL*n-200000);
		FOR(i,0,1e5+5) moge[i] = 0;
		FOR(x,0,9) {
			int bnd = 49;
			if (x != 0) bnd = 5;
			FOR(y,0,bnd) {
				FOR(z,x+y,min(n+1, (100000+4*x+9*y)/49 + 100)) {
					int ile = -4*x-9*y+49*z;
					if (ile >= 0 && ile <= 1e5) moge[ile] = 1; 
				}
			}
		}
		FOR(i,0,1e5+1) ans += moge[i];
		printf("%lld\n", ans);
	}
}