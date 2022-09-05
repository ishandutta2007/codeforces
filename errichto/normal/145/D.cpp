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
const int nax = 1e5 + 5;

bool fisLucky(int a) {
	while(a) {
		int cyf = a % 10;
		if(cyf != 4 && cyf != 7) return false;
		a /= 10;
	}
	return true;
}

int in[nax];
bool isLucky[nax];
vi w;
#include<set>
#include<map>
vi odw[nax];
int gr[nax];
bool vis[nax];
set<int> ss;
int n;
ll glob;

ll pomik(int a) {
	return (ll) a * (a + 1) / 2;
}

void check() {
	return; // wykomentowane
	ll licz = 0;
	vi jeb;
	for(auto a : ss) jeb.pb(a);
	REP(i, sz(jeb) - 1) licz += pomik(jeb[i+1]-jeb[i]-1);
	assert(licz == glob);
}

void dodaj(int a) {
	auto it = ss.insert(a).st;
	if(it == ss.begin()) {
		int tera = *it;
		++it;
		int ne = *it;
		glob += pomik(ne - tera - 1);
		return;
	}
	int tera = *it;
	--it;
	int pop = *it;
	++it; ++it;
	int ne = *it;
	glob += pomik(tera - pop - 1) + pomik(ne - tera - 1) - pomik(ne - pop - 1);
	check();
}
void usun_pierwszy() {
	auto it = ss.begin();
	int tera = *it;
	++it;
	int ne = *it;
	glob -= pomik(ne - tera - 1);
	ss.erase(ss.begin());
	check();
}

ll pref[nax];

ll f(int start) { // wyjebane na poczatek, startujemy rowno w w[start]
	REP(i, sz(w) + 5) vis[i] = false;
	ll RES = 0;
	ss.clear();
	ss.insert(n + 1);
	glob = 0;
	FOR(kon, start, sz(w) - 1) {
		while(*(ss.begin()) <= w[kon]) usun_pierwszy();
		int g = gr[w[kon]];
		if(!vis[g]) {
			vis[g] = true;
			for(auto i : odw[g]) if(i > w[kon]) dodaj(i);
		}
		
		ll bru = 0;
		int ogr = ((kon + 1 == sz(w)) ? n + 1 : w[kon+1]);
		int low = *ss.begin() - (ogr-1) - 1;
		int high = *ss.begin() - w[kon] - 1;
		maxi(low, 1);
		if(low <= high) bru = pref[high] - pref[low-1];
		int on = (kon + 1 == sz(w) ? n + 1 : w[kon+1]);
		int ja = w[kon];
		RES += glob * (on - ja) + bru;
		//printf("%d %d - ", w[start], w[kon]);
		//for(auto a : ss) printf("%d ", a); printf("  %lld\n", glob);
	}
	
	return RES;
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	scanf("%d", &n);
	
	RI(i, n + 1) pref[i] = pref[i-1] + pomik(i);
	
	RI(i, n) scanf("%d", &in[i]);
	RI(i, n) isLucky[i] = fisLucky(in[i]);
	RI(i, n) if(isLucky[i]) w.pb(i);
	set<int> s;
	RI(i, n) if(isLucky[i]) s.insert(in[i]);
	map<int, int> m;
	int L = 0;
	for(auto a : s) m[a] = ++L;
	RI(i, n) if(isLucky[i]) {
		gr[i] = m[in[i]];
		odw[gr[i]].pb(i);
	}
	ll RES = 0;
	REP(i, sz(w)) {
		ll pom = f(i) * (w[i] - (i ? w[i-1] : 0));
		//printf("%lld\n", pom);
		RES += pom;
	}
	w.pb(n + 1);
	REP(i, sz(w)) {
		int ne = w[i];
		int pop = (i ? w[i-1] : 0);
		FOR(kon, pop + 1, ne - 1) RES += (ll) (kon - pop) * pomik(n - kon);
	}
	printf("%lld\n", RES);
	
	return 0;
}