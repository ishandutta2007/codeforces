#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;
const int pot = 128 * 1024;

vi w[nax], lis[nax];
int par[nax][20], h[nax], lim[nax];
vector<pii> zap[nax];
vi res[nax];

vi merge(const vi & A, const vi & B) {
	if(A.empty()) return B;
	if(B.empty()) return A;
	vi w;
	int a = 0;
	int b = 0;
	while(a < sz(A) && b < sz(B)) {
		if(A[a] == B[b]) ++a;
		else if(A[a] < B[b]) w.pb(A[a++]);
		else w.pb(B[b++]);
	}
	while(a < sz(A))
		w.pb(A[a++]);
	while(b < sz(B))
		w.pb(B[b++]);
	while(sz(w) > 10) w.pop_back();
	return w;
}

vi tr[2*pot];

void two(int a) {
	tr[pot+h[a]] = lis[a];
	for(int x = (pot+h[a]) / 2; x >= 1; x /= 2)
		tr[x] = merge(tr[2*x], tr[2*x+1]);
	for(pii p : zap[a]) {
		int h1 = h[p.st];
		int id = p.nd;
		res[id] = merge(res[id], tr[pot + h1]);
		for(int x = pot + h1; x > 1; x /= 2)
			if(x % 2 == 0)
				res[id] = merge(res[id], tr[x+1]);
	}
	for(int b : w[a]) if(b != par[a][0]) two(b);
	tr[pot+h[a]].clear();
	for(int x = (pot+h[a]) / 2; x >= 1; x /= 2)
		tr[x] = merge(tr[2*x], tr[2*x+1]);
}

void one(int a) {
	for(int i = 0; par[a][i]; ++i)
		par[a][i+1] = par[ par[a][i] ][i];
	for(int b : w[a]) if(b != par[a][0]) {
		h[b] = h[a] + 1;
		par[b][0] = a;
		one(b);
	}
}

int lca(int a, int b) {
	if(h[a] < h[b]) swap(a, b);
	for(int i = 0; h[a] > h[b]; ++i)
		if((h[a]-h[b]) & (1 << i))
			a = par[a][i];
	assert(h[a] == h[b]);
	if(a == b) return a;
	for(int i = 19; a != b && i >= 0; --i) {
		if(par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	a = par[a][0];
	b = par[b][0];
	assert(a == b && a != 0);
	return a;
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	REP(_, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		w[a].pb(b);
		w[b].pb(a);
	}
	RI(i, m) {
		int where;
		scanf("%d", &where);
		lis[where].pb(i);
	}
	RI(i, n) {
		sort(lis[i].begin(), lis[i].end());
		while(sz(lis[i]) > 10) lis[i].pop_back();
	}
	
	one(1);
	
	RI(i, q) {
		int u, v;
		scanf("%d%d%d", &u, &v, &lim[i]);
		int x = lca(u, v);
		zap[u].pb(mp(x,i));
		zap[v].pb(mp(x,i));
	}
	
	two(1);
	
	RI(i, q) {
		while(sz(res[i]) > lim[i]) res[i].pop_back();
		printf("%d ", sz(res[i]));
		for(int a : res[i]) printf("%d ", a);
		puts("");
	}
	
	return 0;
}