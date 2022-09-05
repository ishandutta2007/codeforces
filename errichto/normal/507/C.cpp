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

ll pot[nax];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	pot[0] = 1;
	RI(i, 200) pot[i] = pot[i-1] * 2LL;
	
	int h;
	ll n;
	scanf("%d%lld", &h, &n);
	--n;
	ll res = h;
	int ktory = 0;
	for(ll x = n + pot[h]; x > 1; x /= 2LL) {
		if(x % 2LL == (x / 2LL) % 2LL) {
			if(debug) printf("%lld\n", pot[ktory + 1] - 1LL);
			res += pot[ktory + 1] - 1LL;
		}
		++ktory;
	}
	printf("%lld\n", res);
	return 0;
}