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

#include<set>

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int h[2], n;
	scanf("%d%d%d", &h[0], &h[1], &n);
	set<int> s[2];
	REP(i, 2) s[i].insert(h[i]);
	REP(i,2) s[i].insert(0);
	multiset<int> m[2];
	REP(i, 2) m[i].insert(h[i]);
	while(n--) {
		char sl[3];
		scanf("%s", sl);
		int rodz = sl[0] == 'H' ? 1 : 0;
		int gdzie;
		scanf("%d", &gdzie);
		set<int> :: iterator it = s[rodz].insert(gdzie).st;
		int a = *it;
		--it;
		int pop = *it;
		++it; ++it;
		int nast = *it;
		//printf("%d %d %d\n", a, pop, nast);
		m[rodz].erase(m[rodz].find(nast-pop));
		m[rodz].insert(a-pop);
		m[rodz].insert(nast-a);
		auto it2 = m[0].end();
		it2--;
		ll r = *it2;
		it2 = m[1].end();
		--it2;
		printf("%lld\n", r * *it2);
	}
	
	return 0;
}