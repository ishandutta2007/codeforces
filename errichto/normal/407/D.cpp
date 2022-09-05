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
const int nax = 405;
const int L = 160005;

short m[L][nax];
int t[nax][nax];
short dp[2][nax][nax];

int odw(int a) { return 1 - a; }

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int H, W;
	scanf("%d%d", &H, &W);
	
	RI(y, H) RI(x, W) scanf("%d", &t[x][y]);
	REP(a,L)REP(b,nax) m[a][b] = W;
	
	int lvl = 0;
	int res = 0;
	FORD(x, W, 1) {
		RI(d, H) RI(low, H - d + 1) {
			int high = low + d - 1;
			auto & tera = dp[lvl][low][high];
			if(low == high) {
				if(x == W) tera = W;
				else tera = min(dp[odw(lvl)][low][high], m[ t[x][low] ][low]);
			}
			else {
				tera = min(dp[lvl][low + 1][high], dp[lvl][low][high-1]);
				if(x != W)
					mini(tera, dp[odw(lvl)][low][high]);
				mini(tera, m[t[x][low]][high]);
				mini(tera, m[t[x][high]][low]);
				if(t[x][low] == t[x][high])
					tera = x - 1;
			}
			if(debug) printf("%d %d\n", high - low + 1, tera - x + 1);
			maxi(res, (high - low + 1) * (tera - x + 1));
		}
		RI(y, H) mini(m[t[x][y]][y], short(x-1));
		lvl = odw(lvl);
	}
	printf("%d\n", res);
	return 0;
}