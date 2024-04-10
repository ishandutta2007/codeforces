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
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 300228;
const int BLOCK = 1500;

int n, q;
int a[MAXN];
vector<int> g[MAXN];
vector<int> order;
int jump[MAXN][20];
int in[MAXN];
int out[MAXN];
int p[MAXN];
bool special[MAXN];
int ans[MAXN];


void dfs(int u, int pr = -1) {
	order.pb(u);
	in[u] = sz(order) - 1;
	for (auto h: g[u]) {
		if (h != pr) {
			jump[h][0] = u; 
			dfs(h, u);
		}
	}
	order.pb(u);
	out[u] = sz(order) - 1;
}


bool ispr(int a, int b) {
	return in[a] <= in[b] && out[b] <= out[a];
}


int lca(int a, int b) {
	if (ispr(a, b)) {
		return a;
	}
	if (ispr(b, a)) {
		return b;
	}
	for (int k = 19; k >= 0; k--) {
		if (!ispr(jump[a][k], b)) {
			a = jump[a][k];
		}
 	}
 	return jump[a][0];
}

int l[MAXN], r[MAXN];
int li[MAXN], ri[MAXN];
vector<pair<int, int> > zg[MAXN];


void add(int ls, int rs, int id) {
	li[id] = ls;
	ri[id] = rs;
	zg[ls / BLOCK].pb(mp(rs, id));
}


int cnt[MAXN];
int cp[MAXN];
int cnte[MAXN];
int cnte1[MAXN];

void add(int pos) {
	int u = order[pos];
	cnt[order[pos]]++;
	if ((cnt[order[pos]] & 1) == 1) {
		cp[a[u]]++;
	if (cp[a[u]] & 1) {
		cnte[a[u]] = true;
	cnte1[a[u] >> 9]++;
	} else {
		cnte[a[u]] = false;
	cnte1[a[u] >> 9]--;
	}
	} else {
		cp[a[u]]--;
	if (cp[a[u]] & 1) {
		cnte[a[u]] = true;
	cnte1[a[u] >> 9]++;
	} else {
		cnte[a[u]] = false;
	cnte1[a[u] >> 9]--;
	}
	}
}


void del(int pos) {
	int u = order[pos];
	cnt[order[pos]]--;
	if ((cnt[order[pos]] & 1) == 1) {
		cp[a[u]]++;
	if (cp[a[u]] & 1) {
		cnte[a[u]] = true;
	cnte1[a[u] >> 9]++;
	} else {
		cnte[a[u]] = false;
	cnte1[a[u] >> 9]--;
	}
	} else {
		cp[a[u]]--;
	if (cp[a[u]] & 1) {
		cnte[a[u]] = true;
	cnte1[a[u] >> 9]++;
	} else {
		cnte[a[u]] = false;
	cnte1[a[u] >> 9]--;
	}
	}
}


void tryans(int l, int r, int id) {
	if (r - l + 1 <= 512) {
		for (int i = l; i <= r; i++) {
			if (cnte[i]) {
				ans[id] = i;
				return;
			}
		}
	} else {
		int fl = (l >> 9) + 1;
		int fr = (r >> 9) - 1;
		for (int it = fl; it <= fr; it++) {
			if (cnte1[it]) {
				for (int j = (it << 9); ; j++) {
					if (cnte[j]) {
						ans[id] = j;
						return;
					}
				}
				return;
			}
		}
		for (int j = l; j < (fl << 9); j++) {
			if (cnte[j]) {
				ans[id] = j;
				return;
			}
		}
		for (int j = (fr << 9) + 512; j <= r; j++) {
			if (cnte[j]) {
				ans[id] = j;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//     read(FILENAME);
   	cin >> n >> q;
   	for (int i = 0; i < n; i++) {
   		cin >> a[i];
   	}
   	for (int it = 0; it < n - 1; it++) {
   		int a, b;
   		cin >> a >> b;
   		a--, b--;
   		g[a].pb(b);
   		g[b].pb(a);
   	}
   	dfs(0);
   	for (int k = 1; k <= 19; k++) {
   		for (int i = 0; i < n; i++) {
   			jump[i][k] = jump[jump[i][k - 1]][k - 1];
   		}
   	}
   	for (int it = 0; it < q; it++) {
   		ans[it] = -1;
   		int u, v;
   		cin >> u >> v;
   		cin >> l[it] >> r[it];
   		u--, v--;
   		if (in[u] > in[v]) {
   			swap(u, v);
   		}
   		p[it] = lca(u, v);
   		if (p[it] == u) {
   			add(in[u], in[v], it);
   		} else {
   			special[it] = true;
   			add(out[u], in[v], it);
   		}
   	}
   	int curl = -1, curr = -1;
   	for (int i = 0; i <= (sz(order) - 1) / BLOCK; i++) {
   		if (zg[i].empty()) {
   			continue;
   		}
   		sort(all(zg[i]));
   		if (i % 2 == 1) {
   			reverse(all(zg[i]));
   		}
   		for (auto h: zg[i]) {
   			int id = h.second;
   			if (curl == -1) {
   				for (int j = li[id]; j <= ri[id]; j++) {
   					add(j);
   				}
   				curl = li[id];
   				curr = ri[id];
   			} else {
   				if (curr < ri[id]) {
   					for (int j = curr + 1; j <= ri[id]; j++) {
   						add(j);
   					}
   					curr = ri[id];
   				}
   				if (curl > li[id]) {
   					for (int j = curl - 1; j >= li[id]; j--) {
   						add(j);
   					}
   					curl = li[id];
   				}
   				if (curr > ri[id]) {
   					for (int j = curr; j > ri[id]; j--) {
   						del(j);
   					}
   					curr = ri[id];
   				}
   				if (curl < li[id]) {
   					for (int j = curl; j < li[id]; j++) {
   						del(j);
   					}
   					curl = li[id];
   				}
   			}
   			if (special[id]) {
   				add(in[p[id]]);
   			}
   			tryans(l[id], r[id], id);
   			if (special[id]) {
   				del(in[p[id]]);
   			}
   		}
   	}
   	for (int it = 0; it < q; it++) {
   		cout << ans[it] << '\n';
   	}
   	return 0;
}