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
const int nax = 1005;

bool ta[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	char sl [nax][nax];
	int h, w;
	scanf("%d%d", &h, &w);
	REP(y, h) scanf("%s", sl[y]);
	int r = 0;
	REP(y, h - 1) REP(x, w - 1) {
		REP(i, 300) ta[i] = false;
		REP(dy, 2) REP(dx, 2) ta[(int)sl[y+dy][x+dx]] = true;
		if(ta[(int)'f'] && ta[(int)'a'] && ta[(int)'c'] && ta[(int)'e']) ++r;
	}
	printf("%d\n", r);
	
	return 0;
}