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
const int nax = 1e6 + 5;

int cykl[2], sta[2];

void NIE() { puts("-1"); exit(0); }

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int m;
	scanf("%d", &m);
	REP(i, 2) {
		int h, cel;
		scanf("%d%d", &h, &cel);
		int x, y;
		scanf("%d%d", &x, &y);
		REP(j, nax) {
			if(h == cel) break;
			sta[i]++;
			h = ((ll)h*x+y)%m;
			if(j == nax-1) NIE();
		}
		h = ((ll)h*x+y)%m;
		cykl[i]=1;
		REP(j, nax) {
			if(h == cel) break;
			cykl[i]++;
			h = ((ll)h*x+y)%m;
			if(j == nax-1) cykl[i] = -1;
		}
	}
	if(cykl[0] == -1 && cykl[1] == -1) {
		if(sta[0] == sta[1]) printf("%d\n", sta[0]);
		else NIE();
		return 0;
	}
	REP(_, 2) {
		if(cykl[0] == -1) {
			assert(cykl[1] != -1);
			if(sta[0] >= sta[1] && (sta[0]-sta[1])%cykl[1]==0) printf("%d\n", sta[0]);
			else NIE();
			return 0;
		}
		swap(cykl[0],cykl[1]);
		swap(sta[0],sta[1]);
	}
	REP(j, 2 * nax) {
		ll pom = sta[0] + (ll) j * cykl[0];
		if(pom >= sta[1] && (pom-sta[1])%cykl[1]==0) {
			printf("%lld\n", pom);
			return 0;
		}
	}
	NIE();
	
	return 0;
}