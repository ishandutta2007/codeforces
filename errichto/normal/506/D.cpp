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
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

int ojc[nax];
vector<pii > kr[nax], w[nax];
map<pii, int> res;

int find(int a) { return ojc[a] == a ? a : ojc[a] = find(ojc[a]); }

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	int n, m;
	scanf("%d%d", &n, &m);
	RI(i, n) ojc[i] = i;
	REP(_, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		kr[c].pb({a,b});
	}
	
	RI(col, m) {
		for(auto & p : kr[col])
			ojc[find(p.st)] = find(p.nd);
		
		for(auto & p : kr[col])
			for(auto & a : {p.st, p.nd})
				if(w[a].empty() || w[a].back().st != col)
					w[a].pb({col, find(a)});
		
		for(auto & p : kr[col]) for(auto & a : {p.st, p.nd})
			ojc[a] = a;
	}
	RI(i, n) sort(w[i].begin(), w[i].end());
	
	if(debug) for(auto p : w[1]) printf("col = %d, gr = %d\n", p.st, p.nd);
	
	int q;
	scanf("%d", &q);
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(w[a].size() > w[b].size()) swap(a, b);
		if(res.find({a,b}) != res.end()) {
			printf("%d\n", res[{a,b}]);
			continue;
		}
		int r = 0;
		for(auto & p : w[a]) {
			auto it = lower_bound(w[b].begin(), w[b].end(), p);
			if(it != w[b].end() && *it == p)
				++r;
		}
		res[{a,b}] = r;
		printf("%d\n", r);
	}
	
	return 0;
}