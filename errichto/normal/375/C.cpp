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
const int nax = 22;

const int NIC = 0;
const char BOMB = 'B';
int H, W;
int t[nax][nax];
int dp[nax][nax][1050];
pii start;
char rodz[10];
int counter, ile_skarbow;
vector<pair<pii, int> > bfs[(int) 1e6];
int val[10];
int RES;

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	scanf("%d%d", &H, &W);
	RI(y, H) {
		char sl[25];
		scanf("%s", sl);
		RI(x, W) {
			char znak = sl[x-1];
			if(znak == 'S') start = {x, y};
			if(znak == BOMB || (znak >= '1' && znak <= '9')) {
				t[x][y] = ++counter;
				rodz[counter] = znak;
				if(znak != BOMB) ile_skarbow++;
			}
			if(znak == '#') t[x][y] = -1;
		}
	}
	RI(i, ile_skarbow) scanf("%d", &val[i]);
	REP(i,nax) REP(j, nax) REP(k, 1050) dp[i][j][k] = inf;
	dp[start.st][start.nd][0] = 0;
	bfs[0].pb({start, 0});
	for(int k = 0; !bfs[k].empty(); ++k)
		for(auto & stan : bfs[k]) {
			auto p = stan.st;
			int m = stan.nd;
			if(debug) printf("((%d,%d),%d)\n", p.st,p.nd,m);
			
			// aktualizuj wynik
			bool ok = true;
			if(p != start) ok = false;
			int res = -k;
			RI(i, counter) if(m & (1 << i)) {
				if(rodz[i] == BOMB) ok = false;
				else res += val[rodz[i] - '0'];
			}
			if(ok) maxi(RES, res);
			
			// nakurwiaj na boki
			FOR(dx, -1, 1) FOR(dy, -1, 1) if(abs(dx) + abs(dy) == 1) {
				int x = p.st + dx, y = p.nd + dy;
				if(x < 1 || x > W || y < 1 || y > H) continue;
				if(t[x][y] != NIC) continue;
				int m2 = m;
				if(dx != 0) {
					int cyc = min(x, p.st);
					FOR(y2, y + 1, H) if(t[cyc][y2] > 0) m2 ^= (1 << t[cyc][y2]);
				}
				if(debug && m2 != m) printf("m2 = %d\n", m2);
				if(dp[x][y][m2] == inf) {
					dp[x][y][m2] = dp[p.st][p.nd][m] + 1;
					bfs[k + 1].pb({{x,y}, m2});
				}
			}
				
		}
	if(debug) {
		int m = (1 << 1) + (1 << 2) + (1 << 4) + (1 << 5);
		puts("");
		RI(y, H) {
			RI(x, W) printf("%d ", dp[x][y][m]);
			puts("");
		}
		puts("");
	}
	printf("%d\n", RES);
	return 0;
}