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
#define jeb fflush(stdout)
 
 
using namespace std;

const int max_n = 3e5+5;
const int mod = 1e9 + 7;

int maska[35];
int maska2[35];

int rob2(int a, int b, int k) {
	if (b < a) return rob2(b, a, k);
	int ans = 0;
	FOR(i,0,30) {
		if (!(a & (1<<i))) continue;
		FOR(j,0,30) {
			if (!(b & (1<<j))) continue;
			int dowolnych = max(i,j);
			int pocz = ((a^(1<<i)) & maska2[dowolnych])^((b^(1<<j)) & maska2[dowolnych]);
			pocz = pocz & maska2[dowolnych];
			int mam = 1<<min(i,j);
			if (pocz < (k&maska2[dowolnych])) {
				int kutas =  ((1<<dowolnych) * 1LL * mam) % mod;
				ans += (kutas * 1LL * pocz) % mod;
				ans %= mod;
				kutas = ((((1<<(dowolnych))*1LL*((1<<dowolnych) - 1)))/2)%mod;
				ans += (kutas * 1LL * mam) % mod;
				ans %= mod;
				ans += ((1<<dowolnych) * 1LL * mam)%mod;
				ans %= mod;
			}else {
				if ((k&maska2[dowolnych]) == pocz) {
					int reszta = k&maska[dowolnych];
					int kutas = ((reszta+1) * 1LL * mam) % mod;
					ans += (kutas * 1LL * pocz) % mod;
					ans %= mod;
					kutas = ((reszta * 1LL * (reszta+1))/2 )%mod;
					ans += (kutas * 1LL * mam) % mod;
					ans %= mod;
					ans += ((reszta + 1) * 1LL * mam) % mod;
					ans %= mod;
				}
			}
		}
	}
	return ans;
}

int rob(int a, int b, int k) {
	if (a==0 || b==0) return 0;
	return rob2(a, b, k - 1);
}


int main() {
	maska[0] = 0;
	FOR(i,1,32) maska[i] = maska[i-1] + (1<<(i-1));
	FOR(i,0,31) maska2[i] = maska[i] ^ maska[31];
	make(q);
	while (q--) {
		make2(x1, y1);
		make2(x2, y2);
		make(k);
		int ans1 = (rob(x2,y2,k)+rob(x1-1,y1-1,k))%mod;
		int ans2 = (rob(x1-1,y2,k)+rob(x2,y1-1,k)) % mod;
		if (ans1 < 0 ) ans1 += mod;
		printf("%d\n", (ans1 + mod - ans2)%mod);
	}
}