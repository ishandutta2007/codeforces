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

const int max_n = 1e6+5; 
int mod = 998244353;

int powmod(int a, int n) {
	if (a == 0 && n == 0) return 1;
	if (a== 0) return 0;
	if (n == 0) return 1;
	int sq = powmod(a, n/2);
	sq = (sq * 1LL * sq) % mod;
	if (n % 2 == 0) return sq;
	return (sq * 1LL * a) % mod;
}
int fac[max_n];
int ifac[max_n];
lint col[max_n];

int main() {
	make(n);
	fac[0] = 1; ifac[0] = 1;
	FOR(i,1,max_n) fac[i] = (fac[i-1]*1LL*i) % mod;
	FOR(i,1,max_n) ifac[i] = powmod(fac[i], mod - 2);
	lint ans = 0;
	//i-ty wiersz
	int p3 = powmod(3, n);
	FOR(i,0,n) {
		int q3 = (p3+mod-3)%mod;
		lint loc = (powmod(q3, i) * 3LL * powmod(p3, n-1-i)) % mod;
		ans = (ans + loc ) % mod;
	}
	// rozne wiersze ale i kolumn tych samych
	FOR(i,1,n+1) {
		int newton = (fac[n] * 1LL * ifac[i])%mod;
		newton = (newton * 1LL * ifac[n-i])%mod;
		lint loc = 0;
		// te same kolory
		lint xxx = (3LL*newton)%mod;
		lint q = (powmod(3,n-i)-1+mod)%mod;
		xxx = (xxx * 1LL * powmod(q,n))%mod;
		loc = (loc + xxx)%mod;
		// co najmniej dwa kolory rozne
		
		if (i >= 2) {
			xxx = (powmod(3,i)-3+mod)%mod;
			xxx = (xxx*1LL*newton)%mod;
			q = powmod(3,n-i);
			xxx = (xxx*1LL*powmod(q, n))%mod;
			loc = (loc + xxx) % mod;
		}
		col[i] = loc;
	}
	int sgn = 1;
	FOR(i,1,n+1) {
		ans = (ans + sgn*col[i]) % mod;
		if (ans < 0) ans+=mod;
		sgn = -sgn;
	}
	printf("%d\n", ans);
}