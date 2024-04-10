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
const int nax = 2e6 + 5;

ll pref[nax];
int n;
pii dp[nax][2];
ll t[nax];

int te() {
	ll ogr;
	scanf("%lld", &ogr);
	if(pref[n] <= ogr) return 1;
	int prawy = 1;
	RI(i, n) REP(j, 2) dp[i][j] = mp(inf, inf);
	RI(i, n) if(pref[i-1] < ogr) dp[i][0] = mp(0, i);
	int res = inf;
	RI(lewy, n) {
		//REP(j, 2) printf("(%d, %d),  ", dp[lewy][j].st, dp[lewy][j].nd); puts("");
		while(pref[prawy+1] - pref[lewy-1] <= ogr) ++prawy;
		//printf("%d %d\n\n", lewy, prawy);
		if(prawy + 1 > n) {
			REP(j, 2) if(dp[lewy][j].st != inf && prawy >= n + dp[lewy][j].nd - 1) {
				mini(res, 1 + dp[lewy][j].st);
				//if(res == 2) printf("%d %d\n", lewy, prawy);
				//if(res == 2) return 0;
			}
		}
		else {
			REP(j, 2) if(dp[lewy][j].st != inf) {
				int ile = dp[lewy][j].st + 1;
				int on = prawy + 1;
				pii na = mp(ile, dp[lewy][j].nd);
				if(dp[on][0].st > ile) {
					dp[on][1] = dp[on][0];
					dp[on][0] = na;
				}
				else if(dp[on][0].st == ile)
					mini(dp[on][0], na);
				else mini(dp[on][1], na);
			}
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int q;
	scanf("%d%d", &n, &q);
	RI(i, n) scanf("%lld", &t[i]);
	RI(i, n) t[n+i] = t[i];
	RI(i, 2 * n) pref[i] = pref[i-1] + t[i];
	while(q--) printf("%d\n", te());
	
	return 0;
}