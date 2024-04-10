 /*
 



















 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
const string FILENAME = "input";
const int MAXN = 500228;


int n, m;
int a[MAXN];
vector<int> g[MAXN];
bool used[MAXN];
int tin[MAXN], fup[MAXN];
int timer = 0;
unordered_map<int, bool> br[MAXN];
long long cost[MAXN];
vector<int> v[MAXN];
int who[MAXN];


void dfs(int u, int pr = -1) {
	used[u] = true;
	timer++;
	tin[u] = timer;
	fup[u] = timer;
	for (auto h: g[u]) {
		if (h == pr) {
			continue;
		}
		if (!used[h]) {
			dfs(h, u);
			chkmin(fup[u], fup[h]);
			if (fup[h] > tin[u]) {
				br[u][h] = true;
				br[h][u] = true;
			}
		} else {
			chkmin(fup[u], tin[h]);
		}
	}
}


void dfs1(int u, int c) {
	used[u] = true;
	who[u] = c;
	for (auto h: g[u]) {
		if (!br[u][h] && !used[h]) {
			dfs1(h, c);
		}
	}
}



long long dist[MAXN];
int cnt[MAXN];



long long ans = 0;
bool good[MAXN];


void dfs3(int u) {
	used[u] = true;
	chkmax(ans, dist[u]);
	for (auto h: v[u]) {
		if (!used[h]) {
			dist[h] = dist[u] + cost[h];
			dfs3(h);
		}
	}	
}



int in[MAXN], out[MAXN];
int jump[MAXN][20];


void dfst(int u) {
	used[u] = true;
	timer++;
	in[u] = timer;
	for (auto h: v[u]) {
		if (used[h]) {
			continue;
		}
		jump[h][0] = u;;
		dfst(h);
	}
	timer++;
	out[u] = timer;
}


bool isparent(int a, int b) {
	return in[a] <= in[b] && out[b] <= out[a];
}


int lca(int a, int b) {
	if (isparent(a, b)) {
		return a;
	}
	if (isparent(b, a)) {
		return b;
	}
	for (int k = 19; k >= 0; k--) {
		if (!isparent(jump[a][k], b)) {
			a = jump[a][k];
		}
	}
	return jump[a][0];
}


int add[MAXN];


void proceed(int a, int b){
	if (!isparent(a, b)) {
		swap(a, b);
	}
	if (isparent(a, b)) {
		add[b]++;
		if (a != 1) {
			add[jump[a][0]]--;
		}
	} else {
		int c = lca(a, b);
		add[a]++;
		add[b]++;
		if (c != 1) {
			add[jump[c][0]] -= 2;
		}
	}
}


void dfst1(int u) {
	used[u] = true;
	for (auto h: v[u]) {
		if (used[h]) {
			continue;
		}
		dfst1(h);
		add[u] += add[h];
	}
	if (add[u] != 0) {
		good[u] = true;
	}
}



long long keks[MAXN];
long long keks1[MAXN][2];


void dfst2(int u, int pr) {
	//cout << u << ' ' << cost[u] << endl;
	used[u] = true;
	long long ft = 0, ft1 = 0;
	for (auto h: v[u]) {
		if (used[h]) {
			continue;
		}
		if (h != pr) {
			dfst2(h, u);
			chkmax(keks[u], keks[h]);
			chkmax(keks1[u][1], keks1[h][1] + cost[u]);
			if (ft < keks1[h][0]) {
				ft1 = ft;
				ft = keks1[h][0];
			} else {
				chkmax(ft1, keks1[h][0]);
			}
		}
	}
	keks[u] += cost[u];
	keks1[u][0] = keks[u];
	chkmax(keks1[u][1], keks[u]);
	chkmax(keks1[u][1], cost[u] + ft + ft1);
}


long long tkeks[MAXN][2];
long long kekr[MAXN];
int special;
long long fadd = -1e18;

bool dfst4(int u, int pr, long long cur = 0) {
	tkeks[u][1] = -1e18;
	used[u] = true;
	bool good = false;
	long long curmx = 0;
	long long wasp = -1e18;
	for (auto h: v[u]) {
		if (used[h]) {
			continue;
		}
		if (h != pr) {
			if (dfst4(h, u, cur + cost[u])) {
				chkmax(fadd, tkeks[h][0] + wasp);
				good = true;
				chkmax(fadd, kekr[special] + curmx);
				wasp = kekr[special];
			} else {
				chkmax(fadd, tkeks[h][0] + wasp);
			}
			chkmax(curmx, tkeks[h][0]);
			for (int g = 0; g < 2; g++) {
				chkmax(tkeks[u][g], tkeks[h][g]);
			}
		}
	}
	for (int g = 0; g < 2; g++) {
		tkeks[u][g] += cost[u];
	}
	if (u == special) {
		chkmax(tkeks[u][1], cost[u]);
		chkmax(fadd, cur + tkeks[u][0]);
		kekr[u] = cur + cost[u];
		return true;
	}
	if (good) {
		return true;
	} 
	return false;
}



int deg[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	cin >> n >> m;
 	for (int i = 0; i < n; i++) {
 		cin >> a[i];
 	}
 	for (int i = 0; i < m; i++) {
 		int a, b;
 		cin >> a >> b;
 		a--, b--;
 		g[a].pb(b);
 		g[b].pb(a);
 	}
 	int s;
 	cin >> s;
 	s--;
 	dfs(0);
 	memset(used, 0, sizeof(used));
 	int c = 0;
 	for (int i = 0; i < n; i++) {
 		if (!used[i]) {
 			c++;
 			dfs1(i, c);
 		}
 	}
 	special = who[s];
 	for (int i = 0; i < n; i++) {
 		cost[who[i]] += a[i];
 		cnt[who[i]]++;
 	}
 	for (int i = 0; i < n; i++) {
 		for (auto x: g[i]) {
 			if (who[i] != who[x]) {
 				v[who[i]].pb(who[x]);
 			}
 		}
 	}
 	{
 		int pos = special;
	 	dist[pos] = cost[pos];
	 	memset(used, 0, sizeof(used));
	 	dfs3(pos);
	 	memset(used, 0, sizeof(used));
 	}
 	bool was = false;
 	for (int i = 1; i <= c; i++) {
 		if (cnt[i] > 1) {
 			good[i] = true;
 			was = true;
 		}
 	}
 	if (!was) {
 		cout << ans << endl;
 		return 0;
 	}
 	set<pair<int, int> > sss;
 	for (int i = 1; i <= c; i++) {
 		if (!good[i]) {
 			deg[i] = sz(v[i]);
 			sss.insert({sz(v[i]), i});
 		}
 	}
 	while (!sss.empty()) {
 		auto x = *sss.begin();
 		if (x.first > 1 || x.first < 1) {
 			break;
 		}
 		int g = x.second;
 		sss.erase(x);
 		for (auto y: v[g]) {
 			if (!good[y]) {
 				if (sss.find({deg[y], y}) != sss.end()) {
 					sss.erase({deg[y], y});
 					deg[y]--;
 					sss.insert({deg[y], y});
 				}
 			}
 		}
 	}
 	for (auto x: sss) {
 		good[x.second] = true;
 	}
 	long long res = 0;
 	for (int i = 1; i <= c; i++) {
 		if (good[i]) {
 			res += cost[i];
 		}
 	}
 	memset(used, 0, sizeof(used));
 	if (good[special]) {
 		long long cura = 0;
 		long long adds = 0;
	 	for (int i = 1; i <= c; i++) {
	 		if (good[i]) {
	 			used[i] = true;
	 			for (auto x: v[i]) {
	 				if (!good[x]) {
	 					dfst2(x, i);
	 					long long a = keks[x];
	 					chkmax(adds, a);
	 				}
	 			}
	 		}
	 	}
	 	chkmax(ans, res + adds);
	} else {
		long long cura[2] = {0, -1000000000000000000LL};
		long long adds = 0;
		for (int i = 1; i <= c; i++) {
	 		if (good[i]) {
	 			used[i] = true;
	 			for (auto x: v[i]) {
	 				if (!good[x]) {
	 					fadd = -1e18;
	 					dfst4(x, i);
	 					long long a1 = tkeks[x][1];
	 					long long a0 = tkeks[x][0];
	 					//cout << fadd << endl;
	 					chkmax(adds, fadd);
	 					chkmax(adds, a0 + cura[1]);
	 					chkmax(adds, a1 + cura[0]);
	 					chkmax(cura[0], a0);
	 					chkmax(cura[1], a1);
	 				}
	 			}
	 		}
	 	}
	 	chkmax(ans, res + adds);
	}
 	cout << ans << '\n';
	return 0; 	
}