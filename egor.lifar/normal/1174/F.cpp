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
template<class T1, class T2> inline void chkmin(T1 &x, const T2 &y) {if (x > y) x = y;}
template<class T1, class T2> inline void chkmax(T1 &x, const T2 &y) {if (x < y) x = y;}
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define mp make_pair
#define pb push_back
#define read(FILENAME) freopen((string(FILENAME) + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((string(FILENAME) + ".out").c_str(), "w", stdout);
const int MAXN = 200228;


int n;
vector<int> g[MAXN];
bool can[MAXN];
int deep[MAXN];
int cnts[MAXN];
bool used[MAXN];
int dist[MAXN];
vector<int> v[MAXN];
bool useds[MAXN];


void dfs(int u, int pr = -1) {
	can[u] = true;
	for (auto h: g[u]) {
		if (h != pr) {
			v[u].pb(h);
			deep[h] = deep[u]  + 1;
			dfs(h, u);
		}
	}
}


void recalc(int u) {
	cnts[u] = can[u];
 	for (auto h: v[u]) {
		recalc(h);
		cnts[u] += cnts[h];
	}
}


queue<int> q;


void makethempay(int u, int dists) {
	for (int i = 0; i < n; i++) {
		used[i] = false;
		dist[i] = 0;
	}
	q.push(u);
	used[u] = true;
	while (!q.empty()) {
		auto a = q.front();
		q.pop();
		can[a] &= (dist[a] == dists);
		for (auto h: g[a]) {
			if (!used[h]) {
				used[h] = true;
				dist[h] = dist[a] + 1;
				q.push(h);
 			}
		}
	}	
	recalc(0);	
}



int getdist(int u) {
	cout << 'd' << ' ' << u + 1 << endl;
	int res;
	cin >> res;
	if (res == -1) {
		exit(0);
	}
	return res;
} 

mt19937 as;
vector<int> st;


void get(int u) {
	st.pb(u);
	for (auto h: v[u]) {
		get(h);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	//read("input");
	cin >> n;
	as.seed(time(NULL));
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);	
	useds[0] = true;
	int u = 0;
	int need = getdist(u);
	makethempay(u, need);
	int level = 0;
	while (true) {
		if (level == need) {
			cout << '!' << ' ' << u + 1 << endl;
			return 0;
		}
		while (true) {
			int kek = 0;
			int ress = 0;
			int ft = 0;
			int pos = -1;
			int who;
			for (auto h: v[u]) {
				if (cnts[h]) {
					chkmax(kek, cnts[h]);
					ress += cnts[h];
					ft++;
					pos = h;
					if (kek == cnts[h]) {
						who = h;
					}
				}
		 	}
		 	assert(ft != 0);
		 	if (ft == 1) {
		 		u = pos;
		 		level++;
		 		break;
		 	}
		 	if (kek * 2 <= ress) {
		 		cout << 's' << ' ' << u + 1 << endl;
		 		int res;
		 		cin >> res;
		 		if (res == -1) {
		 			exit(0);
		 		}
		 		res--;
		 		u = res;
		 		level++;
		 		break;
		 	}
		 	st.clear();
		 	get(who);
		 	int f = st[as() % sz(st)];
		 	while (useds[f]) {
		 		f = st[as() % sz(st)];
		 	}
		 	useds[f] = true;
 		 	makethempay(f, getdist(f));
		}
	}
	return 0;
}