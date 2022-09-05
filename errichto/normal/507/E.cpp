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
const int nax = 1e5 + 5;
const int MIL = 1000 * 1000;
const ll INF = (ll) inf * inf;

pair<ll, int> d[nax];

struct cmp {
	bool operator()(int a, int b) {
		if(d[a] != d[b]) return d[a] < d[b];
		return a < b;
	}
};

vector<pii > w[nax];
set<int, cmp> s;
bool vis[nax];
set<pii > ma;
int t[nax][3];

int main(int argc, char * argv[]) {
	debug = argc > 1;
	int n, m;
	scanf("%d%d", &n, &m);
	RI(te, m) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		w[a].pb({b, MIL - c});
		w[b].pb({a, MIL - c});
		t[te][0] = a;
		t[te][1] = b;
		t[te][2] = c;
	}
	d[1] = {0, 0};
	FOR(i, 2, n) d[i] = {INF, 0};
	RI(i, n) s.insert(i);
	while(!s.empty()) {
		int a = *s.begin();
		s.erase(s.begin());
		vis[a] = true;
		for(auto p : w[a]) {
			int b = p.st;
			if(!vis[b]) if(d[b].st > d[a].st + (ll) p.nd) {
				s.erase(b);
				d[b] = {d[a].st + (ll) p.nd, a};
				s.insert(b);
			}
		}
	}
	int x = n;
	while(x != 1) {
		if(debug) printf("%d ", x);
		int b = d[x].nd;
		ma.insert({min(b,x), max(b,x)});
		x = b;
	}
	if(debug) puts("");
	
	int licz = 0;
	RI(te, m) {
		pii p = {min(t[te][0], t[te][1]), max(t[te][0], t[te][1])};
		int uzyta = (ma.find(p) != ma.end());
		if(uzyta != t[te][2]) ++licz;
	}
	printf("%d\n", licz);
	RI(te, m) {
		pii p = {min(t[te][0], t[te][1]), max(t[te][0], t[te][1])};
		int uzyta = (ma.find(p) != ma.end());
		if(uzyta != t[te][2]) printf("%d %d %d\n", t[te][0], t[te][1], 1 - t[te][2]);
	}
	
	return 0;
}