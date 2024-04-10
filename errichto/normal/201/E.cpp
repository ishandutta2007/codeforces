#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
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
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;



bool ok(ll n, ll m, ll dni) {
	ll s = 0;
	ll nt = 1;
	ll i = 1;
	ll dupuj = 0;
	while(nt && s + nt <= n) {
		if(debug) printf("%lld %lld\n", s, nt);
		dupuj += (i - 1) * nt;
		s += nt;
		nt = nt * (dni + 1 - i) / i;
		++i;
		if(nt == 0LL && s < n) return false;
	}
	dupuj += (i - 1) * (n - s);
	return dupuj <= dni * m;
}

int ttt() {
	ll n, m;
	scanf("%lld%lld", &n, &m);
	if(n == 1LL) return 0;
	if(m == 1LL) return (int) n - 1;
	ll low = 1, high = n;
	while(low < high) {
		ll med = (low + high) / 2;
		if(ok(n, m, med)) high = med;
		else low = med + 1;
	}
	return (int) low;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int z;
	scanf("%d", &z);
	while(z--) printf("%d\n", ttt());
	
	return 0;
}