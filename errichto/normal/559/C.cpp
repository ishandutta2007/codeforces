#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define sz(w) (int) w.size()
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const ll INF = (ll) inf * inf;
const int nax = 2e5 + 15;
const int mod = 1e9 + 7;

ll fac[nax], odw[nax];

ll pot(ll a, int b) {
	ll r = 1;
	while(b) {
		if(b%2) r = r * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return r;
}

ll nt(int a, int b) { return fac[a]*odw[b]%mod*odw[a-b]%mod; }

pii p[nax];

ll safe[nax];

ll whatever(int i, int j) {
	assert(i <= j);
	int a = p[j].x-p[i].x;
	int b = p[j].y-p[i].y;
	if(a < 0 || b < 0) return 0;
	return nt(a+b,a);
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	fac[0] = 1;
	RI(i, nax - 1) fac[i] = fac[i-1] * i % mod;
	REP(i, nax) odw[i] = pot(fac[i], mod - 2);
	
	int h, w, n;
	scanf("%d%d%d", &h, &w, &n);
	RI(i, n) scanf("%d%d", &p[i].y, &p[i].x);
	sort(p + 1, p + n + 1);
	p[0] = mp(1,1);
	p[n+1] = mp(w,h);
	safe[0] = 1;
	RI(j, n + 1) {
		safe[j] = whatever(0,j);
		RI(i, j-1) {
			safe[j] -= safe[i] * whatever(i,j) % mod;
			while(safe[j] < 0) safe[j] += mod;
		}
	}
	printf("%lld\n", safe[n+1]);
	
	return 0;
}