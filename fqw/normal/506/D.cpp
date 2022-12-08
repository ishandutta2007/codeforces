#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //

const int MAXN=100000;
const int MAXM=100000;

struct UF {
	int f[MAXN];
	UF() { fillchar(f, 0xff); }
	int find(int i) {
		return f[i]<0 ? i : f[i]=find(f[i]);
	}
	void unite(int i, int j) {
		i=find(i), j=find(j);
		if(i!=j) f[i]=j;
	}
};

struct BigG {
	UF uf;
	BigG(vector<PII> es) {
		forn(i, es.size()) uf.unite(es[i].fi, es[i].se);
	}
	bool conn(int i, int j) {
		return uf.find(i) == uf.find(j);
	}
};

map<PII, int> pairs;
struct SmallG {
	SmallG(vector<PII> es) {
		set<int> _nodes;
		forn(i, es.size()) {
			_nodes.insert(es[i].fi);
			_nodes.insert(es[i].se);
		}
		vector<int> nodes(all(_nodes));
		static UF uf;
		forn(i, es.size()) uf.unite(es[i].fi, es[i].se);
		forn(i, nodes.size()) forn(j, nodes.size()) {
			int x=nodes[i], y=nodes[j];
			if(uf.find(x)==uf.find(y))
				pairs[MP(x, y)] ++;
		}
		forn(i, nodes.size()) uf.f[nodes[i]]=-1;
	}
};

set<PII> es[MAXM];
vector<BigG *> bg;
vector<SmallG *> sg;
int n, m;

int main() {
	scanf("%d%d", &n,&m);
	forn(i, m) {
		int a, b, c; scanf("%d%d%d", &a,&b,&c);
		--a, --b, --c;
		es[c].insert(MP(a,b));
	}
	pairs.clear();
	forn(i, m) {
		if(es[i].size()>n/500)
			bg.PB(new BigG(vector<PII>(all(es[i]))));
		else
			sg.PB(new SmallG(vector<PII>(all(es[i]))));
	}
	int q; scanf("%d", &q);
	while(q--) {
		int a, b; scanf("%d%d", &a,&b);
		--a, --b;
		int ans=0;
		forn(i, bg.size()) if(bg[i]->conn(a, b)) ++ans;
		ans+=pairs[MP(a, b)];
		printf("%d\n", ans);
	}
	return 0;
}