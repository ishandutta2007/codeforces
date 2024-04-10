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
const int nax = 1e6 + 5;

vector<bool> vis[nax];
vi t[nax];
int max_x[nax], max_y[nax];
map<int, vector<pii>> m;
vector<pii> odw_x[nax], odw_y[nax];
int maksu;
vector<pii> kol;

bool zbieraj(vector<pii> & w, pii & p) {
	while(!w.empty()) {
		p = w.back();
		w.pop_back();
		if(!vis[p.st][p.nd]) {
			vis[p.st][p.nd] = true;
			return true;
		}
	}
	return false;
}

void dfs(int x, int y) {
	// printf("dfs %d,%d\n", x, y);
	kol.pb(mp(x,y));
	maxi(maksu, max(max_x[x], max_y[y]));
	pii p;
	while(zbieraj(odw_x[x], p)) dfs(p.st, p.nd);
	while(zbieraj(odw_y[y], p)) dfs(p.st, p.nd);
	//assert(odw_x[x].empty());
	//assert(odw_y[y].empty());
}

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	REP(i, h) {
		REP(j, w) {
			int a;
			// a = rand() % 10000;
			scanf("%d", &a);
			t[j].pb(a);
			m[a].pb(mp(j,i)); // x, y
			vis[j].pb(false);
		}
	}
	// assert(!vis[0][840]);
	for(const pair<int, vector<pii>> & lul : m) {
		// printf("> %d\n", lul.st);
		// puts("a");
		const vector<pii> & lista = lul.nd;
		for(const pii & p : lista) {
			odw_x[p.st].pb(p);
			odw_y[p.nd].pb(p);
		}
		// puts("b");
		for(const pii & init_p : lista) if(!vis[init_p.st][init_p.nd]) {
		// 	printf("(%d,%d)\n", init_p.st, init_p.nd);
		// 	puts("one");
			pii p_tmp;
			assert(zbieraj(odw_x[init_p.st], p_tmp));
		// 	printf("zebralem %d,%d\n", p_tmp.st, p_tmp.nd);
			
			// start dfs()
			maksu = 0;
			kol.clear();
			dfs(p_tmp.st, p_tmp.nd);
			// puts("two");
			// result dfs()
			++maksu;
			// printf("%d\n", maksu);
			for(pii & p : kol) {
				// printf("%d %d %d\n", p.st, p.nd, maksu);
				assert(vis[p.st][p.nd]);
				assert(odw_y[p.nd].empty());
				t[p.st][p.nd] = maksu;
				maxi(max_x[p.st], maksu);
				maxi(max_y[p.nd], maksu);
			}
		//	assert(vis[init_p.st][init_p.nd]);
			//assert(odw_x[init_p.st].empty());
			//assert(odw_y[init_p.nd].empty());
		// 	puts("three");
		}
	// 	puts("c");
		/*for(const pii & p : lista) {
			assert(vis[p.st][p.nd]);
			assert(odw_x[p.st].empty());
		// 	if(odw_y[p.nd].size()) printf("zle %d,%d\n", p.st, p.nd);
			assert(odw_y[p.nd].empty());
		}*/
	}
	// puts("dupa");
	REP(y, h) {
		REP(x, w) printf("%d ", t[x][y]);
		puts("");
	}
	return 0;
}