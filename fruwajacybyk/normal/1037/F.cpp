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

const int max_n = 1000005;

int mod = 1e9 + 7;
int n, k;
VI v;
int lewo[max_n];
int prawo[max_n];

//int dupa[max_n];

int licz(int l, int p) {
	int m1 = l/(k-1);
	int m2 = p/(k-1);
	int m3 = (l+p)/(k-1);

	lint a1 = (m1 + ((m1*1LL*(m1+1)*1LL*(k-1))/2)) % mod;
	lint a2 = ((m2 - m1) * 1LL * (l+1))%mod;
	lint a3 = (m3-m2)*1LL*(p+l+1) - ((k-1)*1LL*(m3-m2)*1LL*(m3+m2+1))/2;
	a3 %= mod;
	return (a1 + a2 + a3) % mod;
}

int main() {
	read2(n, k);
	v.pb(1e9+1);
	readv(v, n);
	vector<PII> stos;
	stos.pb({1e9+1,0});
	FOR(i,1,n+1) {
		PII ja = {v[i], i};
		while (stos.back() < ja) {
			stos.pop_back();
		}
		lewo[i] = stos.back().nd;
		stos.pb(ja);
	}
	stos.clear();
	stos.pb({1e9+1,n+1});
	FORD(i,n,1) {
		PII ja = {v[i], i};
		while (stos.back() < ja) {
			stos.pop_back();
		}
		prawo[i] = stos.back().nd;
		stos.pb(ja);
	}
	/*int u = k;
	while (u <= n) {
		for (int w = u; w <= n; w+= u) {
			dupa[w]++;
		}
		u += k-1;
	}
	FOR(i,1,n+1) {
		dupa[i] += dupa[i-1];
		if (dupa[i] >= mod) dupa[i]-= mod;
	}*/
	lint ans = 0;
	FOR(i,1,n+1) {
		int l = i-lewo[i] - 1;
		int p = prawo[i] - i - 1;
		int dupa = licz(min(l,p), max(l,p));
		ans = (ans + dupa*1LL*v[i]) % mod;	
	}
	printf("%lld\n", ans);
	return 0;
}