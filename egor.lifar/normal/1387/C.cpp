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
using ll = long long;
using ull = unsigned long long;
using ld = long double; 
const string FILENAME = "input";
const unsigned long long INF = (1ULL << 63);
const int MAXN = 55;
const int MAXG = 205;
const int MAXM = 100228;



int nG, G;
int n, m;
vector<vector<int> > d;
vector<vector<pair<int, int> > > d1;
vector<vector<int> > antis;
int uk;
int go[MAXN][2];
int link[MAXN];
bool terminal[MAXN];
vector<int> g[MAXM];
vector<pair<int, int> > gl[MAXM], gr[MAXM]; 


int addGene() {
	d.pb(vector<int>());
	d1.pb(vector<pair<int, int> >());
	return G++;
}


int node() {
	for (int it = 0; it < 2; it++) {
		go[uk][it] = -1;
	}
	return uk++;
}


void add(vector<int> s) {
	int cur = 0;
	for (int i = 0; i < sz(s); i++) {
		if (go[cur][s[i]] == -1) {
			go[cur][s[i]] = node();
		}
		cur = go[cur][s[i]];
	}
	terminal[cur] = true;
}


struct noda {
	ull t;
	int u;
	int l, r;
};

 
bool operator <(const noda& a, const noda& b) {
	return mp(a.t, mp(a.u, mp(a.l, a.r))) < mp(b.t, mp(b.u, mp(b.l, b.r)));
}
 

multiset<noda> s;
ull dist[MAXG][MAXN][MAXN];
bool used[MAXG][MAXN][MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> nG >> n >> m;
	G = nG;
	d.resize(G);
	d1.resize(G);
	for (int i = 0; i < n; i++) {
		int a, k;
		cin >> a >> k;
		if (k == 1) {
			int b;
			cin >> b;
			d[a].pb(b);
		} else {
			for (int j = 0; j < k - 2; j++) {
				int a1 = addGene();
				int b;
				cin >> b;
				d1[a].pb(mp(b, a1));
				a = a1;
			}
			int b1, b2;
			cin >> b1 >> b2;
			d1[a].pb(mp(b1, b2));
		}
	}
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int> cur;
		cur.resize(k);
		for (int j = 0; j < k; j++) {
			cin >> cur[j];
		}
		antis.pb(cur);
	}
	for (int it = 0; it < 2; it++) {
		go[0][it] = -1;
	}
	node();
	for (auto s: antis) {
		add(s);
	}
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (terminal[link[v]]) {
			terminal[v] = true;
		}
		for (int c = 0; c < 2; c++) {
			if (go[v][c] == -1) {
				go[v][c] = (v == 0 ? 0: go[link[v]][c]);
			} else {
				q.push(go[v][c]);
				link[go[v][c]] = (v == 0 ? 0: go[link[v]][c]);
			}
		}
	}
	for (int i = 0; i < G; i++) {
		for (auto v: d[i]) {
			g[v].pb(i);
		}
		for (auto h: d1[i]) {
			gl[h.first].pb(mp(h.second, i));
			gr[h.second].pb(mp(h.first, i));
		}
	}
	for (int i = 0; i < G; i++) {
		for (int l = 0; l < uk; l++) {
			for (int r = 0; r < uk; r++) {
				dist[i][l][r] = INF;
			}
		}
	}
	for (int i = 0; i < uk; i++) {
		for (int it = 0; it < 2; it++) {
			if (!terminal[i] && !terminal[go[i][it]]) {
				s.insert({1, it, i, go[i][it]});
				dist[it][i][go[i][it]] = 1;
			}
		}
	}
	while (!s.empty()) {
		noda x = (*s.begin());
		s.erase(x);
		int u = x.u;
		int l = x.l;
		int r = x.r;
		ull t = x.t;
		if (used[u][l][r]) {
			continue;
		}
		used[u][l][r] = true;
		for (auto h: g[u]) {
			if (dist[h][l][r] > t) {
				dist[h][l][r] = t;
				s.insert({dist[h][l][r], h, l, r});
			}
		}
		for (auto x: gl[u]) {
			int h = x.first, h1 = x.second;
			for (int rs = 0; rs < uk; rs++) {
				ull nval = dist[h][r][rs] + t;
				if (!terminal[rs] && dist[h1][l][rs] > nval) {
					dist[h1][l][rs] = nval;
					s.insert({dist[h1][l][rs], h1, l, rs});
				}
			}
		}
		for (auto x: gr[u]) {
			int h = x.first, h1 = x.second;
			for (int ls = 0; ls < uk; ls++) {
				ull nval = dist[h][ls][l] + t;
				if (!terminal[ls] && dist[h1][ls][r] > nval) {
					dist[h1][ls][r] = nval;
					s.insert({dist[h1][ls][r], h1, ls, r});
				}
			}
		}
	}
	for (int i = 2; i < nG; i++) {
		ull opt = INF;
		for (int j = 0; j < uk; j++) {
			if (!terminal[j]) {
				chkmin(opt, dist[i][0][j]);
			}
		}
		if (opt == INF) {
			cout << "YES\n";
		} else {
			cout << "NO" << ' ' << opt << '\n';
		}
	}
}