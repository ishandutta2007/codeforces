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
const int nax = 1e5 + 5;
const int cost_max = 4000;
const int n_max = 4000;

vector<pii > item[nax];
int n, p;
vector<pii > zap[nax];
int res[nax];
int dp[4005][4005];
int dp2[4005];
int pom[nax];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	scanf("%d%d", &n, &p);
	REP(i, n) {
		int a,b,c;
		scanf("%d%d%d", &a, &b, &c);
		item[c].pb({a,b});
	}
	#define cost first
	#define happy second
	int q;
	scanf("%d", &q);
	REP(i, q) {
		int tim, money;
		scanf("%d%d", &tim, &money);
		zap[tim].pb({money, i});
	}
	#define money first
	#define id second
	for(int T = 0; T < nax / 2; T += p) {
		int wsk = 0;
		FOR(t, T, T + p - 1) {
			for(auto & ite : item[t]) {
				++wsk;
				RI(i, cost_max) {
					dp[wsk][i] = dp[wsk-1][i];
					if(i >= ite.cost) maxi(dp[wsk][i], dp[wsk-1][i-ite.cost] + ite.happy);
				}
			}
			for(auto & pyta : zap[t])
				pom[pyta.id] = wsk;
		}
		bool cos_sie_stalo = false;
		FORD(t, T, T-p+1) {
			if(t >= 0 && t != T) for(auto & ite : item[t]) {
				cos_sie_stalo = true;
				FORD(i, cost_max, ite.cost)
					maxi(dp2[i], dp2[i-ite.cost] + ite.happy);
			}
			for(auto & pyta : zap[t + p - 1]) {
				int gdzie = pom[pyta.id];
				FOR(i, 0, pyta.money)
					maxi(res[pyta.id], dp2[i] + dp[gdzie][pyta.money - i]);
			}
		}
		if(cos_sie_stalo) REP(i, cost_max + 2) dp2[i] = 0;
		RI(k, wsk) REP(i, cost_max + 2) dp[k][i] = 0;
	}
	REP(i, q) printf("%d\n", res[i]);
	return 0;
}