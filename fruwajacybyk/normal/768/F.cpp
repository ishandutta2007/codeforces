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

#define max_n 200005

int mod = 1e9 + 7;

int powmod(int a, int n) {
	if (n == 0) return 1;
	int sq = powmod(a, n/2);
	sq = (sq * 1LL * sq) % mod;
	if (n%2==0) return sq;
	return (sq * 1LL * a) % mod;
}

int fac[max_n];
int ifac[max_n];

int spos(int a, int k) {
	if (k > a) return 0;
	if (a==0 && k==0) return 1;
	if (a==0 || k==0) return 0;
	int f1 = (fac[a-1]*1LL*ifac[k-1])%mod;
	return (f1*1LL*ifac[a-k])%mod;
}

int spos2(int a, int k, int h) {
	if (k*1LL*h+k > a) return 0;
	if (k == 0) return 0;
	return spos(a-h*k, k);
}

int main() {
	fac[0] = ifac[0] = 1; 
	FOR(i,1,2e5) fac[i] = (fac[i-1]*1LL*i)%mod;
	FOR(i,1,2e5) ifac[i] = powmod(fac[i], mod - 2);
	make3(f, w, h);
	if (w == 0) {
		printf("1\n");
		return 0;
	}
	int denom = 0;
	FOR(k,0,min(f,w)+2) {
		denom += (spos(f,k)*2LL*spos(w,k))%mod;
		denom %= mod;
		denom += (spos(f,k+1)*1LL*spos(w,k))%mod;
		denom %= mod;
		denom += (spos(f,k)*1LL*spos(w,k+1))%mod;
		denom %= mod;
	}
	int numer = 0;
	FOR(k,0,min(f,w)+2) {
		numer += (spos(f,k)*2LL*spos2(w,k,h))%mod;
		numer %= mod;
		numer += (spos(f,k+1)*1LL*spos2(w,k,h))%mod;
		numer %= mod;
		numer += (spos(f,k)*1LL*spos2(w,k+1,h))%mod;
		numer %= mod;
	}
	printf("%lld\n", (numer*1LL*powmod(denom, mod-2))%mod);
	
}