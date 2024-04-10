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

int magic = 3 * 1000 * 1000; 
ll res;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	ll ogr, daje[2], cost[2];
	scanf("%lld%lld%lld%lld%lld", &ogr, &daje[0], &daje[1], &cost[0], &cost[1]);
	REP(_, 2) {
		REP(i, magic) {
			ll zostalo = ogr - cost[0] * i;
			if(zostalo < 0) break;
			maxi(res, daje[0] * i + daje[1] * (zostalo / cost[1]));
		}
		swap(daje[0], daje[1]);
		swap(cost[0], cost[1]);
	}
	printf("%lld\n", res);
	
	return 0;
}