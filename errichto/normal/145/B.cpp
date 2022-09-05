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

void nie() {
	puts("-1");
	exit(0);
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int cel4, cel7, cel47, cel74;
	scanf("%d%d%d%d", &cel4, &cel7, &cel47, &cel74);
	if(abs(cel47 - cel74) > 1) nie();
	if(cel47 == cel74) {
		if(cel4 == cel47) {
			// 74747
			int k = cel47;
			if(cel7 <= k) nie();
			REP(i, k) printf("74");
			REP(_, cel7 - k) printf("7");
			return 0;
		}
		if(cel4 < cel47) nie();
		assert(cel4 > cel47);
		if(cel7 < cel47) nie();
		int k = cel47;
		REP(_, cel4 - k) printf("4");
		REP(_, k - 1) printf("74");
		REP(_, cel7 - k + 1) printf("7");
		printf("4");
		return 0;
	}
	if(cel47 < cel74) {
		// 7474
		int k = cel74;
		assert(k >= 2);
		if(cel4 - k + 1 < 1) nie();
		if(cel7 - k + 1 < 1) nie();
		printf("7");
		REP(_, cel4 - k + 1) printf("4");
		REP(_, k - 2) printf("74");
		REP(_, cel7 - k + 1) printf("7");
		printf("4");
		return 0;
	}
	// 4747
	int k = cel47;
	assert(k >= 2);
	if(cel4 - k + 1 < 1) nie();
	if(cel7 - k + 1 < 1) nie();
	REP(_, cel4 - k + 1) printf("4");
	REP(_, k - 1) printf("74");
	REP(_, cel7 - k + 1) printf("7");
	return 0;
}