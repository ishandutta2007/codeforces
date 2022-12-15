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

const int max_n = 1e3+5;

VI primes;
char s[100];


int main() {
	FOR(i,2,100) {
		bool ok = true;
		for(int j=2;j<i;j++) if(i%j==0) ok = false;
		if(ok) primes.pb(i);
	}
	debugv(primes);
	int u = primes.size();
	int minp = -1;
	int ind = -1;
	FOR(i,0,u) {
		if (primes[i] > 11) break;
		printf("%d\n", primes[i]);
		fflush(stdout);
		scanf("%s", s);
		if (s[0]=='y') {
			minp = primes[i];
			ind = i;
			break;
		} 
	}
	if (minp == -1) {
		printf("prime\n");
		fflush(stdout);
	} else {
		bool zle = false;
		FOR(j,ind, primes.size()) {
			int d = primes[ind] * primes[j];
			if (d > 100) break;
			printf("%d\n", d);
			fflush(stdout);
			scanf("%s", s);
			if (s[0]=='y') {
				zle = true;
				break;
			} 
		}
		if (zle) printf("composite\n");
		else printf("prime\n");
		fflush(stdout);
	}
}