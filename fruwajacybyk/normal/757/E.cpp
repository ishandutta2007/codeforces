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

#define max_n 1000055

int minp[max_n];
int wyk[max_n];
int red[max_n];
int fac[max_n];
int ifac[max_n];

int mod = 1e9 + 7;

int powmod(int a, int n) {
	if (n==0) return 1;
	int sq = powmod(a, n/2);
	sq = (sq * 1LL * sq) % mod;
	if (n%2==0) return sq;
	return (sq * 1LL * a) % mod;
}

int newton(int a, int b) {
	if (b==0) return 1;
	if (b > a) return 0;
	int ans = (fac[a]*1LL*ifac[b])%mod;
	return (ans*1LL*ifac[a-b])%mod;
}

void rob(int r, int n) {
	if (n == 1) {
		printf("1\n");
		return;
	}
	int ans = 1;
	while (n != 1) {
		int w = wyk[n];
		int loc = 2;
		if (r != 0) {
			loc = (newton(w+(r-1),r-1)+2LL*newton(w+r-1, r))%mod;
		}
		ans = (ans * 1LL * loc) % mod;
		n = red[n];
	}
	printf("%d\n", ans);
}

int main() {
	fac[0] = 1;
	ifac[0] = 1;
	FOR(i,1,1e6+50) {
		fac[i] = (i*1LL*fac[i-1])%mod;
		ifac[i] = (ifac[i-1]*1LL*powmod(i, mod - 2))%mod;
	}
	FOR(i,1,1e6+1) minp[i] = i;
	for (int i=2; i < 1e6+1;i++) {
		if (minp[i] == i) {
			for (int j = i; j<= 1e6; j+= i) {
				minp[j] = i;
			}
		}
	}
	FOR(i,2,1e6+1) {
		int p = minp[i];
		int w = 0;
		int k = i;
		while (k%p == 0) {
			k = k/p;
			w++;
		}
		wyk[i] = w;
		red[i] = k;
	}
	make(q);
	while (q--) {
		make2(r, n);
		rob(r, n);
	}
}