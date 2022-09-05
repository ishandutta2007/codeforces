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
const int nax = 2e5 + 5;

vi in[nax];
int inv[nax];
vector<pii> w[nax];
bool res[nax];
bool vis[nax];
bool removed[nax];

bool ozn[nax];

void remove(int a) {
	removed[a] = true;
	ozn[a] = true;
	for(pii & e : w[a]) if(!removed[e.st]) {
		res[abs(e.nd)] = (e.nd < 0);
		remove(e.st);
	}
	//printf("remove %d\n", a);
}

bool las[nax];

void remove(vector<pii> we) {
	for(pii & e : we) {
		las[e.st] = removed[e.st];
		removed[e.st] = true;
	}
	for(pii & e : we) {
		if(!las[e.st]) {
		//printf("remove %d (i = %d)\n", e.st, e.nd);
		//if(!removed[e.st]) {
			res[abs(e.nd)] = (e.nd > 0);
			remove(e.st);
		}
	}
}

bool theSame(int a, int b) {
	return (a>0)==(b>0);
}

void dfs(int a, vector<pii> & kol, int par) {
	assert(!removed[a]);
	assert(!vis[a]);
	vis[a] = true;
	for(pii & e : w[a]) {
		if(removed[a]) break;
		int b = e.st;
		if(par == abs(e.nd)) continue;
		if(removed[b]) {
			assert(false);
		}
		//assert(!removed[b]);
		/*if(removed[b]) {
			res[abs(e.nd)] = !(e.nd > 0);
			remove(a);
			break;
		}*/
		if(vis[b]) {
			vector<pii> we;
			while(kol.back().st != b) {
				we.pb(kol.back());
				kol.pop_back();
			}
			reverse(we.begin(), we.end());
			we.pb(e);
			remove(we);
			break;
		}
		else {
			kol.pb(e);
			dfs(b, kol, abs(e.nd));
			kol.pop_back();
		}
	}
}

bool ta[nax];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	RI(i, n) {
		int k;
		scanf("%d", &k);
		REP(_, k) {
			int a;
			scanf("%d", &a);
			if(inv[abs(a)] != 0 && theSame(a, inv[abs(a)])) {
				removed[i] = true;
				removed[abs(inv[abs(a)])] = true;
				ta[i] = ta[abs(inv[abs(a)])] = true;
				//remove(i);
				//remove(abs(inv[abs(a)]));
				res[abs(a)] = (a > 0);
				inv[abs(a)] = 0;
			}
			else if(inv[abs(a)] != 0) {
				int he = abs(inv[abs(a)]);
				if(a > 0) {
					w[i].pb(mp(he,abs(a)));
					w[he].pb(mp(i,-abs(a)));
				}
				else {
					w[i].pb(mp(he,-abs(a)));
					w[he].pb(mp(i,abs(a)));
				}
				inv[abs(a)] = 0;
			}
			else {
				if(a > 0) inv[abs(a)] = i;
				else inv[abs(a)] = -i;
			}
		}
	}
	RI(i, max(n,m)) if(inv[i] != 0) if(!removed[abs(inv[i])]) {
		res[i] = (inv[i] > 0);
		remove(abs(inv[i]));
	}
	RI(i, max(n,m)) if(ta[i] && !ozn[i]) remove(i);
	// RI(i, 10) for(pii e : w[i]) printf("(%d,%d), ", e.st, e.nd); puts("");
	vector<pii> kol;
	RI(i, max(n,m)) if(!removed[i] && !vis[i]) {
		kol.pb(mp(i,0));
		dfs(i, kol, -1);
		kol.clear();
	}
	RI(i, n) if(!removed[i]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	RI(i,m) printf("%d", (int) res[i]);
	puts("");
	//RI(i, max(n,m)) dfs(i);
	return 0;
}