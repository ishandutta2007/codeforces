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

int dp[1005][105];
int pot[1005];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, k, mod;
	scanf("%d%d%d", &n, &k, &mod);
	if(mod == 1) {
		puts("0");
		return 0;
	}
	dp[0][0] = 2 % mod;
	
	pot[0] = 1;
	RI(i, 1004) pot[i] = (pot[i-1] * 10) % k;
	
	REP(i, n) REP(r, k) REP(d, 10) if(d > 0 || i < n-1) {
		if(debug) printf("%d %d  ->  %d %d\n", i, r, i+1, (r + pot[i] * d) % k);
		if(r == 0) dp[i+1][(r + pot[i] * d) % k] = (dp[i+1][(r + pot[i] * d) % k] + 1) % mod;
		else dp[i+1][(r + pot[i] * d) % k] = (dp[i+1][(r + pot[i] * d) % k] + dp[i][r]) % mod;
		if(debug) printf("%d\n", dp[i+1][(r + pot[i] * d) % k]);
	}
	
	pot[0] = 1;
	pot[1] = 9;
	FOR(i, 2, 1004) pot[i] = ((ll) pot[i-1] * 10LL) % (ll) mod;
	ll res = 0;
	RI(i, n) res = (res + (ll)((ll)dp[i][0]+((i == n) ? 0 : (mod-1))) * (ll) pot[n-i]) % (ll) mod;
	printf("%lld\n", res);
	return 0;
}