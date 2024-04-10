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
const int nax = 25;

int dp[1 << 20];
char sl[nax][nax];
int cost[nax][nax];

int mi[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, (1 << 20)) dp[i] = inf;
	dp[0] = 0;
	REP(i, n) scanf("%s", sl[i]);
	REP(i, n) REP(j, m) scanf("%d", &cost[i][j]);
	REP(i, n) mi[i] = inf;
	REP(i, n) REP(j, m) mini(mi[i], cost[i][j]);
	REP(i, n) FORD(inny, (1 << 20) - 1, 0)
		mini(dp[inny|(1<<i)], dp[inny] + mi[i]);
	int zerowe = 0;
	REP(j, m) {
		//puts("");
		for(char znak = 'a'; znak <= 'z'; ++znak) {
			int maska = 0;
			int razem = 0;
			int big = -1;
			REP(i, n) if(sl[i][j] == znak) {
				maska += (1 << i);
				razem += cost[i][j];
				maxi(big, cost[i][j]);
			}
			if(big == -1) continue;
			razem -= big;
			//printf("%d %d\n", maska, razem);
			if(razem == 0) {
				REP(i, n) if(sl[i][j] == znak) zerowe |= (1 << i);
			}
			else FORD(inny, (1 << 20) - 1, 0)
				mini(dp[inny|maska], dp[inny] + razem);
		}
	}
	FORD(inny, (1 << 20) - 1, 0)
		mini(dp[inny|zerowe], dp[inny]);
	printf("%d\n", dp[(1 << n) - 1]);
	
	return 0;
}