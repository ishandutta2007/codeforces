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

int n, k;

int mod = 1e9+7;

int ile[1000005];
int fac[1000005];
int ifac[1000005];
int phi[1000005];
int ans = 0;

int powmod(int a, int n) {
	if (n==0) return 1;
	int sq = powmod(a, n/2);
	sq = (sq * 1LL * sq) % mod;
	if (n % 2 == 0) return sq;
	return (sq * 1LL * a) % mod;
}

int minp[1000005];
int wykp[1000005];
int rest[1000005];

int newton(int u, int v) {
	if (v > u) return 0;
	int x = (fac[u]*1LL*ifac[v])%mod;
	x = (x*1LL*ifac[u-v])%mod;
	return x;
}

void sito() {
	FOR(i,1,1000001) minp[i] = i;
	FOR(i,2,1000001) {
		if(minp[i]==i) {
			for(lint j = i*1LL*i; j<= 1000000; j+=i) {
				minp[j] = i;
			}
		}
	}
	phi[1] = 1;
	FOR(i,2,1000001) {
		int p = minp[i];
		int wyk = 0;
		int act = i;
		int pw = 1;
		while (act % p==0) {
			wyk++;
			act = act/p;
			pw = pw*p;
		}
		wykp[i] = wyk;		
		rest[i] = act;
		phi[i] = (phi[act]*1LL*(pw-(pw/p)));
	}
}

void rob(int d) {
	int bylo = newton(ile[d],k);
	int jest = newton(ile[d]+1,k);
	ile[d]++;
	int diff = (jest-bylo+mod)%mod;
	ans = (ans + (diff*1LL*phi[d])%mod)%mod;
}

void dzielniki(int x, int sofar) {
	if(x==1) rob(sofar);
	else {
		int r = rest[x];		
		int pw = 1;
		int p = minp[x];
		FOR(j,0,wykp[x]+1) {
			dzielniki(r, pw*sofar);
			pw = pw*p;
		}
	}
}



int main() {
	fac[0] = 1; ifac[0] = 1;
	FOR(i,1,1000001) fac[i] = (fac[i-1]*1LL*i)%mod;
	FOR(i,1,1000001) ifac[i] = powmod(fac[i], mod-2);
	sito();
	read2(n, k);
	ans = 0;
	make(q);
	FOR(i,0,n) {
		make(a); dzielniki(a,1);
	}
	FOR(i,0,q) {
		make(a); dzielniki(a,1);
		printf("%d\n", ans);
	}	
}