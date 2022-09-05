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
const int mod = 1e9 + 7;

char sl[nax];
int d[nax];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	scanf("%s", sl);
	REP(i, n) d[int(sl[i])]++;
	int m = 0;
	REP(i, 5000) maxi(m, d[i]);
	int ile = 0;
	REP(i, 5000) if(d[i] == m) ++ile;
	ll r = 1;
	REP(_, n) {
		r = (r * ile) % mod;
	}
	printf("%lld\n", r);
	
	return 0;
}