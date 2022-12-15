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

const int max_n = 3e5+5;

int mod = 1e9+7;

int n;
VI v;

int minp[300005];
int wykp[300005];
int rest[300005];

void sito() {
	FOR(i,1,300005) minp[i] = i;
	FOR(i,2,300001) {
		if(minp[i]==i) {
			for(lint j = i*1LL*i; j<=300000; j+=i) minp[j] = i;
		}
	}
	rest[1] = 1;
	FOR(i,2,300001) {
		int p = minp[i];
		int wyk = 0;
		int mask = i;
		while (mask%p==0) {
			mask = mask/p;
			wyk++;	
		}
		rest[i] = mask;
		wykp[i] = wyk;
	}
}

vector<PII> prim;

int powmod(int a, int n) {
	if (n==0) return 1;
	int sq = powmod(a, n/2);
	sq = (sq * 1LL * sq) % mod;
	if (n%2==0) return sq;
	return (sq * 1LL * a) % mod;
}

int powers[max_n];
int prefs[max_n];
int fac[max_n];
int ifac[max_n];


int newton(int a, int b) {
	if (b > a) return 0;
	int x = (fac[a]*1LL*ifac[b])%mod;
	return (x*1LL*ifac[a-b])%mod;
}

int rob(int n1, int n2) {
	if(n1==n2) return 0;
	int ns = prefs[n2-1];
	int ujm = (n1==0 ? 0 : prefs[n1-1]);
	return (ns+(mod-ujm))%mod;
}

int main() {
	sito();
	read(n); readv(v, n);
	fac[1] = 1; FOR(i,2,n+1) fac[i] = (fac[i-1]*1LL*i)%mod;
	ifac[1] = 1; FOR(i,2,n+1) ifac[i] = powmod(fac[i], mod-2);
	FOR(i,0,n) {
		int x = v[i];
		while(x!=1) {
			int p = minp[x];
			int wyk = wykp[x];
			prim.pb(mp(p,wyk));
			x = rest[x];
		}
	}
	powers[0] = (mod+1-powmod(2, n-1))%mod;
	prefs[0] = powers[0];
	FOR(i,1,n) {
		powers[i] = (powers[i-1]+newton(n,i))%mod;
		prefs[i] = (prefs[i-1]+powers[i])%mod;
	}
	sort(all(prim));
	int ans = 0;
	int i = 0;
	int p = prim[0].st;
	int dupa[20];
	FOR(i,0,20) dupa[i] = 0;
	while (i < prim.size()) {
		if (prim[i].st==p) {
			dupa[prim[i].nd]++;
			i++;
		} else {
			int sum = 0;
			FOR(j,0,20) sum += dupa[j];
			dupa[0] = n-sum;
			
			int act = 0;
			FOR(j,0,20) {
				ans += (j*1LL*rob(act, act+dupa[j]))%mod;
				ans %= mod;
				act = act+dupa[j];
			}
			FOR(j,0,20) dupa[j] = 0;
			p = prim[i].st;
			dupa[prim[i].nd]++;
			i++;
		}
	}
			int sum = 0;
			FOR(j,0,20) sum += dupa[j];
			dupa[0] = n-sum;
			
			int act = 0;
			FOR(j,0,20) {
				ans += (j*1LL*rob(act, act+dupa[j]))%mod;
				ans %= mod;
				act = act+dupa[j];
			}

		printf("%d\n", ans);

}