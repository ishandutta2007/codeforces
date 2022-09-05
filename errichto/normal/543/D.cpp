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
const int nax = 2e5 + 5;
const ll mod = 1e9 + 7;

#include<map>
map<pii, pii> m;
vi w[nax];
const pii NIC = mp(-1,-1);
int res[nax];

pii daj(pii p) {
	auto it = m.find(p);
	if(it == m.end()) return NIC;
	return (*it).nd;
}

int dol[nax];
void mnoz(int & a, int b) {
	a = (ll) a * b % mod;
}

int pot(int a, int b) {
	int pom = 1;
	while(b) {
		if(b%2) mnoz(pom, a);
		b /= 2;
		mnoz(a, a);
	}
	return pom;
}

int odw(int a) {
	return pot(a, mod - 2);
}

void dfs(int a) {
	dol[a] = 1;
	for(auto b : w[a]) if(b > a) {
		dfs(b);
		mnoz(dol[a], 1 + dol[b]);
	}
}

void dfs2(int a, int gora) {
	if(gora >= mod) gora -= mod;
	vi licz;
	for(auto b : w[a])
		if(b > a)
			if((dol[b] + 1) % mod == 0)
				licz.pb(b);
	if(sz(licz) >= 2) {
		res[a] = 0;
		for(auto b : w[a]) if(b > a) dfs2(b, 1);
	}
	else if(sz(licz) == 1) {
		res[a] = 0;
		int spec = licz[0];
		for(auto b : w[a]) if(b > a && b != spec)
			mnoz(gora, dol[b] + 1);
		dfs2(spec, gora + 1);
		for(auto b : w[a]) if(b > a && b != spec)
			dfs2(b, 1);
	}
	else {
		for(auto b : w[a])
			if(b > a)
				mnoz(gora, dol[b] + 1);
		res[a] = gora;
		for(auto b : w[a])
			if(b > a) {
				mnoz(gora, odw(dol[b] + 1));
				dfs2(b, 1 + gora);
				mnoz(gora, dol[b] + 1);
			}
	}
}

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	assert(50LL * odw(50) % mod == 1);
	
	int n;
	scanf("%d", &n);
	for(int i = 2; i <= n; ++i) {
		int b;
		scanf("%d", &b);
		w[i].pb(b);
		w[b].pb(i);
	}
	dfs(1);
	dfs2(1, 1);
	RI(i, n) printf("%d ", res[i]);
	puts("");
	
	return 0;
}