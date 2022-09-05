#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
#include<map>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mp make_pair
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const ll mod = 1e9 + 9;

map<pii, int> m;
pii p[nax];
int ile_synow[nax];
set<int> s;
bool vis[nax];
vi res;

void ogarnij(int a) {
	s.erase(a);
	if(vis[a]) return;
	FOR(d, -1, 1) {
		int pom = m[mp(p[a].st + d, p[a].nd + 1)];
		if(pom > 0 && !vis[pom] && ile_synow[pom] == 1) return;
	}
	s.insert(a);
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	RI(i, n) {
		scanf("%d%d", &p[i].st, &p[i].nd);
		m[p[i]] = i;
	}
	RI(a, n) {
		FOR(d, -1, 1) {
			int pom = m[mp(p[a].st + d, p[a].nd + 1)];
			if(pom) ile_synow[pom]++;
		}
	}
	RI(a, n) ogarnij(a);
	
	REP(iter, n) {
		int a;
		if(iter % 2 == 0) {
			// duza
			auto it = s.end();
			--it;
			a = *it;
		}
		else {
			a = *(s.begin());
		}
		res.pb(a - 1);
		s.erase(a);
		vis[a] = true;
		FOR(d, -1, 1) {
			int pom = m[mp(p[a].st + d, p[a].nd + 1)];
			if(pom > 0 && (!vis[pom])) ile_synow[pom]--;
		}
		FOR(dy, 0, 1)
			FOR(d, -2, 2) {
				int pom = m[mp(p[a].st + d, p[a].nd - dy)]; // ten sam poziom
				if(pom > 0 && !vis[pom]) ogarnij(pom);
			}
	}
	ll r = 0;
	for(auto a : res) r = (r * n + a) % mod;
	printf("%lld\n", r);
	return 0;
}