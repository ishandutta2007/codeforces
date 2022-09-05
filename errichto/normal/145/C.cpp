#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e5 + 5;
const int mod = 1e9 + 7;

int in[nax];
int heh[nax];
int fac[nax];
int dp[nax];

bool isLucky(int a) {
	while(a) {
		int cyf = a % 10;
		if(cyf != 4 && cyf != 7) return false;
		a /= 10;
	}
	return true;
}

int poteguj(int a, int b) {
	int r = 1;
	while(b) {
		if(b&1) r = ((ll) r * a) % mod;
		a = ((ll) a * a) % mod;
		b /= 2;
	}
	return r;
}

int odw(int a) {
	return poteguj(a, mod - 2);
}

int nt(int a, int b) {
	if(a < b || b < 0) return 0;
	int licznik = fac[a];
	int mianownik = ((ll) fac[b] * fac[a-b]) % mod;
	return ((ll) licznik * odw(mianownik)) % mod;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, k;
	scanf("%d%d", &n, &k);
	
	fac[0] = 1;
	RI(i, n) fac[i] = ((ll) fac[i-1] * i) % mod;
	
	REP(i, n) scanf("%d", &in[i]);
	sort(in, in + n);
	vi stos;
	REP(i, n) {
		if(isLucky(in[i])) {
			int licz = 1;
			while(i + 1 < n && in[i+1] == in[i]) {
				i++;
				licz++;
			}
			stos.pb(licz);
		}
	}
	int reszta = n;
	for(auto a : stos) reszta -= a;
	if(debug) {
		printf("n = %d\n", n);
		for(auto a : stos) printf("%d ", a);
		printf("\nreszta = %d\n", reszta);
	}
	int ile = sz(stos);
	dp[0] = 1;
	for(auto nowy : stos) {
		FORD(i, ile, 1) {
			dp[i] = (dp[i] + (ll) dp[i-1] * nowy) % mod;
		}
	}
	REP(i, nax) heh[i] = dp[i];
	
	int res = 0;
	
	if(debug) { REP(i, 5) printf("%d ", heh[i]); puts(""); }
	
	REP(zap, nax) if(heh[zap]) {
		int pom = ((ll) heh[zap] * nt(reszta, k - zap)) % mod;
		res = (res + pom) % mod;
	}
	printf("%d\n", res);
	return 0;
}