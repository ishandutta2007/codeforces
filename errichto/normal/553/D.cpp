#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<assert.h>
#include<set>
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

ll dobre[nax];
vi w[nax];
bool ok[nax];
bool del[nax];
bool ruszony[nax];

struct cmp {
	bool operator ()(int a, int b) {
		if(dobre[a] * sz(w[b]) == dobre[b] * sz(w[a]))
			return a < b;
		return dobre[a] * sz(w[b]) < dobre[b] * sz(w[a]);
	}
};

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	RI(i, n) ok[i] = true;
	while(k--) {
		int a;
		scanf("%d", &a);
		ok[a] = false;
	}
	while(m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	RI(a, n) if(ok[a]) for(int b : w[a]) if(ok[b]) ++dobre[a];
	set<int, cmp> s;
	RI(a, n) if(ok[a]) s.insert(a);
	pair<ll,ll> best = mp(0LL, 1LL);
	vi kol;
	while(!s.empty()) {
		int a = *s.begin();
		ruszony[a] = true;
		s.erase(s.begin());
		if(dobre[a] * best.nd > best.st * sz(w[a])) {
			best = mp(dobre[a], (ll) sz(w[a]));
			for(int b : kol) del[b] = true;
			kol.clear();
		}
		for(int b : w[a]) if(ok[b] && !ruszony[b]) {
			s.erase(b);
			dobre[b]--;
			s.insert(b);
		}
		kol.pb(a);
	}
	vi res;
	RI(i, n) if(ok[i] && !del[i]) res.pb(i);
	printf("%d\n", sz(res));
	for(int a : res) printf("%d ", a);
	
	return 0;
}