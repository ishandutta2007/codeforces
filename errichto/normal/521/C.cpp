#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const ll mod = 1e9 + 7;

char sl[nax];
ll res;
ll t[nax], s[nax];
int k;
ll facto[nax];

ll f(int a, int b) {
	return (mod + s[b] - (a ? s[a-1] : 0)) % mod;
}

ll pot(ll a, int b) {
	ll r = 1;
	while(b) {
		if(b&1) r = r * a % mod;
		a = a * a % mod;
		b /= 2;
	}
	return r;
}

ll odw(ll a) {
	assert(a != 0);
	return pot(a, mod - 2);
}

ll nt(int a, int b) {
	if(a < b || b < 0) return 0;
	return facto[a] * odw(facto[b]) % mod * odw(facto[a-b]) % mod;
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n;
	scanf("%d%d", &n, &k);
	scanf("%s", sl);
	facto[0] = 1;
	RI(i, n) facto[i] = facto[i-1] * i % mod;
	REP(i, n) t[i] = sl[i] - '0';
	REP(i, n) s[i] = ((i ? s[i-1] : 0) + t[i]) % mod;
	ll mnoz = 1;
	RI(i, n) {
		res += mnoz * (t[n - i] * nt(n - i, k) % mod + f(0, n - i - 1) * nt(n - i - 1, k - 1) % mod) % mod;
		res %= mod;
		mnoz = mnoz * 10 % mod;
	}
	printf("%lld\n", res);
	return 0;
}