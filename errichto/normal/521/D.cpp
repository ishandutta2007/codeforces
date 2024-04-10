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
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const ll INF = (ll) inf * inf * 2;

ll start[nax];
vector<pii > add[nax];
pii assign[nax];
vector<pair<pii, int> > all;
int rodz[nax];

bool cmp(pair<pii, int> a, pair<pii, int> b) {
	pii p1 = a.st, p2 = b.st;
	bool spec = false;
	if(p1.st && p2.nd && INF / p1.st < p2.nd) spec = true;
	if(p2.st && p1.nd && INF / p2.st < p1.nd) spec = true;
	assert(!spec);
	if(spec) return (ld) p1.st * p2.nd > (ld) p2.st * p1.nd;
	return (ll) p1.st * p2.nd > (ll) p2.st * p1.nd;
}

bool cmp2(int i1, int i2) {
	if(rodz[i1] == rodz[i2]) return i1 < i2;
	return rodz[i1] < rodz[i2];
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	int k, n, hajs;
	scanf("%d%d%d", &k, &n, &hajs);
	RI(i, k) scanf("%lld", &start[i]);
	RI(id, n) {
		int i, b;
		scanf("%d%d%d", &rodz[id], &i, &b);
		if(rodz[id] == 1) maxi(assign[i], mp((ll)b, (ll)id));
		else if(rodz[id] == 2) add[i].pb(mp(b, id));
		else all.pb(mp(    mp(b - 1, 1)   , id));
	}
	#define n GOWNO_apsdfjaosdfpasd
	RI(i, k) if(assign[i].st > start[i])
		add[i].pb(mp((ll)assign[i].st - start[i],(ll) assign[i].nd));
	RI(i, k) {
		sort(add[i].rbegin(), add[i].rend());
		for(auto p : add[i]) {
			int id = p.nd;
			int b = p.st;
			all.pb(mp(   mp(b, start[i]), id));
			start[i] += b;
		}
	}
	sort(all.begin(), all.end(), cmp);
	
	mini(hajs, (int) all.size());
	
	vi res;
	REP(i, hajs) res.pb(all[i].nd);
	sort(res.begin(), res.end(), cmp2);
	
	printf("%d\n", hajs);
	for(auto a : res) printf("%d ", a);
	puts("");
	
	return 0;
}