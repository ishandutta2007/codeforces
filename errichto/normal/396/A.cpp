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
#define _st first
#define nd second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 1e6 + 5;
const int mod = 1e9 + 7;

#include<map>
map<int, int> m;
int n;

int pot(ll a, int b) {
	ll r = 1;
	while(b) {
		if(b&1) r = (r * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return (int) r;
}
ll odw(ll a) { return pot(a, mod - 2); }

ll fac[nax];
ll f(int a) {
	ll licznik = fac[n - 1 + a];
	ll mianownik = fac[a] * fac[n-1] % mod;
	return licznik * odw(mianownik) % mod;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	fac[0] = 1;
	RI(i, nax - 1) fac[i] = (fac[i-1] * i) % mod;
	
	scanf("%d", &n);
	REP(_, n) {
		int a;
		scanf("%d", &a);
		for(int i = 2; i * i <= a; ++i)
			while(a % i == 0) {
				m[i]++;
				a /= i;
			}
		if(a > 1) m[a]++;
	}
	ll r = 1;
	for(auto p : m) r = (r * f(p.nd)) % mod;
	printf("%d\n", (int) r);
	
	return 0;
}