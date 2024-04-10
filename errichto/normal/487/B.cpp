#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#ifdef LOK
#define debug printf
#else
#define debug if(0)printf
#endif
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll inf = 1e12 + 5;
const int nax = 1e5 + 5;
const int pot = 128 * 1024;

ll t[nax];
ll mi[2 * pot + 5];
ll ma[2 * pot + 5];
int res[nax];
ll s;
int n, L;

bool ok(int a, int b) {
	a += pot; b += pot;
	ll small = min(mi[a], mi[b]), big = max(ma[a], ma[b]);
	while(a < b - 1) {
		if(a % 2 == 0) {
			mini(small, mi[a + 1]);
			maxi(big, ma[a + 1]);
		}
		if(b % 2) {
			mini(small, mi[b - 1]);
			maxi(big, ma[b - 1]);
		}
		a /= 2;
		b /= 2;
	}
	debug("%lld %lld\n", big, small);
	return big - small <= s;
}

int jak_daleko(int i) {
	int low = i;
	int high = n - 1;
	while(low < high) {
		int med = (low + high + 1) / 2;
		if(ok(i, med)) low = med;
		else high = med - 1;
	}
	return low;
}

int main() {
	scanf("%d%lld%d", &n, &s, &L);
	REP(i, n) scanf("%lld", &t[i]);
	REP(i, 2 * pot + 5) {
		mi[i] = inf;
		ma[i] = -inf;
	}
	t[n] = inf;
	FOR(i, 0, n) mi[i + pot] = ma[i + pot] = t[i];
	FORD(i, pot - 1, 1) {
		mi[i] = min(mi[i * 2], mi[i * 2 + 1]);
		ma[i] = max(ma[i * 2], ma[i * 2 + 1]);
	}
	set<int> zle;
	RI(i, n) zle.insert(i);
	zle.insert(1e9 + 5);
	// 0 nie jest zle
	set<int> przerob;
	przerob.insert(0);
	//debug("%d\n", jak_daleko(0));
	//if(ok(0, 6)) debug("niepowinno\n");
	while(!przerob.empty()) {
		int a;
		{
			auto it = przerob.end();
			--it;
			a = *it;
			przerob.erase(it);
		}
		// a jest najwieksze
		if(a == n) continue;
		int b = jak_daleko(a);
		if(b - a + 1 < L) continue;
		int low = a + L, high = b + 1;
		auto it = zle.lower_bound(low);
		while(*it <= high) {
			int cyk = *it;
			res[cyk] = res[a] + 1;
			przerob.insert(cyk);
			zle.erase(it);
			it = zle.lower_bound(low);
		}
	}
	FOR(i,0,n) debug("%d ", res[i]);
	debug("\n");
	if(res[n] == 0) res[n] = -1;
	printf("%d\n", res[n]);
	return 0;
}