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
const ll INF = (ll) inf * inf;
const int nax = 30123;

ll t[nax];
ll pref[nax];
ll mpref[nax];
ll minusmpref[nax];
ll doda[nax], minu[nax];
ll c_suma[205], c_roz[205], c_suma2[205], c_roz2[205], tak[205], nie[205];

ll s(int a, int b) { return pref[b] - pref[a-1]; }

//ll brut[nax][205];

//ll f(int n, int K) {
//	REP(i, nax) RI(k, K) dp[i][k] = -INF;
//	REP(k, K) RI(a, n) FOR(b, a, n) maxi(dp[b][k+1], 

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, K;
	scanf("%d%d", &n, &K);
	RI(i, n) scanf("%lld", &t[i]);
	RI(i, n) pref[i] = pref[i-1] + t[i];
	mpref[1] = pref[1];
	minusmpref[1] = -pref[1];
	FOR(i, 2, n) mpref[i] = max(mpref[i-1] + t[i], t[i]);
	FOR(i, 2, n) minusmpref[i] = max(minusmpref[i-1] - t[i], -t[i]);
	
	doda[n] = t[n];
	minu[n] = -t[n];
	FORD(i, n - 1, 1) doda[i] = max(doda[i+1] + t[i], t[i]);
	FORD(i, n - 1, 1) minu[i] = max(minu[i+1] - t[i], -t[i]);
	
	REP(i, 205) c_suma[i] = c_roz[i] = c_suma2[i] = c_roz2[i] = tak[i] = nie[i] = -INF;
	
	ll RES = -INF;
	
	RI(i, n) FORD(k, K-1, 1) {
		
		if(k == 1) {
			c_suma[k] = mpref[i];
			c_roz[k] = minusmpref[i];
		}
		maxi(c_suma2[k], tak[k]);
		maxi(c_roz2[k], nie[k]);
		
		tak[k] -= 2 * t[i];
		nie[k] += 2 * t[i];
		
		maxi(c_suma[k], c_suma2[k] + 2 * pref[i]);
		maxi(c_suma[k+1], c_suma[k]);
		maxi(c_roz2[k+1], c_suma[k] + 2 * pref[i]);
		maxi(nie[k+1], c_suma[k] + 2 * pref[i]);
		
		
		maxi(c_roz[k], c_roz2[k] - 2 * pref[i]);
		maxi(c_roz[k+1], c_roz[k]);
		maxi(c_suma2[k+1], c_roz[k] - 2 * pref[i]);
		maxi(tak[k+1], c_roz[k] - 2 * pref[i]);
		
		if(k == K-1 && i < n) {
			maxi(RES, c_suma[k] + minu[i + 1]);
			maxi(RES, c_roz[k] + doda[i+1]);
		}
	}
	
	printf("%lld\n", RES);
	
	
	return 0;
}