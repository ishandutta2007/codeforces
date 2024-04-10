#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
#include<set>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,(n))
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
const int nax = 1e5 + 5;
const ll INF = (ll) inf * inf;

int f(char a) { return int(a - 'a'); }

set<int> pocz[26], kon[26];
char sl[nax];

int usun(int low, int high, int i) {
	int r = 0;
	while(true) {
		auto prawy = kon[i].lower_bound(low);
		if(prawy == kon[i].end()) break;
		auto lewy = pocz[i].upper_bound(*prawy);
		--lewy;
		int a = *lewy, b = *prawy;
		if(a > high) break;
		pocz[i].erase(lewy);
		kon[i].erase(prawy);
		int doda = min(high, b) - max(low, a) + 1;
		assert(doda > 0);
		r += max(doda, 0);
		if(a < low) {
			pocz[i].insert(a);
			kon[i].insert(low-1);
		}
		if(b > high) {
			pocz[i].insert(high+1);
			kon[i].insert(b);
		}
	}
	return r;
}

int pom[26];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", sl);
	REP(i, n) {
		if(i == 0 || sl[i-1] != sl[i]) pocz[f(sl[i])].insert(i+1);
		if(i == n-1 || sl[i+1] != sl[i]) kon[f(sl[i])].insert(i+1);
	}
	while(q--) {
		int low, high, rodz;
		scanf("%d%d%d", &low, &high, &rodz);
		REP(i, 26) pom[i] = usun(low, high, i);
		if(rodz == 1) { // inc
			int wsk = low;
			REP(i, 26) if(pom[i]) {
				pocz[i].insert(wsk);
				kon[i].insert(wsk + pom[i] - 1);
				wsk += pom[i];
			}
		}
		else {
			int wsk = low;
			FORD(i, 25, 0) if(pom[i]) {
				pocz[i].insert(wsk);
				kon[i].insert(wsk + pom[i] - 1);
				wsk += pom[i];
			}
		}
	}
	REP(i, 26) {
		while(!pocz[i].empty()) {
			int a = *pocz[i].begin();
			int b = *kon[i].begin();
			pocz[i].erase(pocz[i].begin());
			kon[i].erase(kon[i].begin());
			FOR(j, a, b) sl[j-1] = 'a' + i;
		}
	}
	printf("%s\n", sl);
	return 0;
}