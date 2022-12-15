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

#define debug(x) {cout <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cout <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
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
#define jeb() fflush(stdout);

using namespace std;
const int max_n = 1e6 + 5;

int mod = 1e9 + 7;
int pm[max_n];
int inv[max_n];
int fac[max_n];
int ifac[max_n];
int pn[max_n];

int newton(int a, int b) {
	if (b > a) return 0;
	int ans = (fac[a] * 1LL * ifac[b])%mod;
	return (ans * 1LL * ifac[a-b])%mod;
}

int main() {
		make2(n, m);
		make2(a, b);
		pm[0] = 1;  pm[1] = m;
		fac[0] = 1; fac[1] = 1; 
		ifac[0] = 1; ifac[1] = 1; 
		inv[1] = 1; 
		pn[0] = 1; pn[1] = n;

		FOR(i,2,max(n,m)+1) {
			pm[i] = (pm[i-1] * 1LL * m) % mod;
			inv[i] = ((mod - (mod/i)) * 1LL * inv[mod%i])%mod;
			fac[i] = (fac[i-1] * 1LL * i) % mod;
			ifac[i] = (ifac[i-1] * 1LL * inv[i])%mod;
			pn[i] = (pn[i-1] * 1LL * n) % mod;
		}
		int ans = 0;
		FOR(i,1,n) {
			if (i > m) continue;
			int loc = (newton(m-1, i-1) * 1LL * pm[n-1-i]) % mod;

			int trees = 0;
			if (i == n-1) {
				trees = 1;
			} else {
				trees = ((i+1)*1LL*pn[n-(i+1)-1])%mod;
			}
			trees = (trees * 1LL * newton(n-2,i-1)) % mod;
			trees = (trees * 1LL * fac[i-1])%mod;
			ans = (ans + (trees * 1LL * loc)) % mod;
		}
		printf("%d\n", ans);
}