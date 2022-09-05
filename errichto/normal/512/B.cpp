#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<cstring>
#include<assert.h>
#include<unordered_map>
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
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;

unordered_map<int, int> mapa;
int jeb[nax];
int d[nax], cost[nax];
unordered_set<int> s;

void ustaw(int a, int c) {
	if(a < nax) mini(jeb[a], c);
	else {
		auto it = mapa.find(a);
		if(it == mapa.end()) {
			mapa[a] = c;
			s.insert(a);
		}
		else {
			int d = (*it).nd;
			if(d > c) mapa[a] = c;
		}
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	REP(i, nax) jeb[i] = inf;
	
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &d[i]);
	REP(i, n) scanf("%d", &cost[i]);
	REP(i, n) ustaw(d[i], cost[i]);
	
	REP(i, n) {
		vector<pii > w;
		FOR(g, 2, nax-1) if(jeb[g] != inf) w.pb(mp(__gcd(g, d[i]), jeb[g] + cost[i]));
		for(auto a : s) w.pb(mp(__gcd(a, d[i]), cost[i] + mapa[a]));
		for(auto p : w) ustaw(p.st, p.nd);
	}
	if(jeb[1] == inf) jeb[1] = -1;
	printf("%d\n", jeb[1]);
	
	return 0;
}