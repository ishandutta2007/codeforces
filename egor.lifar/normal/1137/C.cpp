/*
 



















 
 */
#pragma comment(linker, "/STACK:36777216")
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
const string FILENAME = "input";
const int MAXN = 100228;


int n, m, d;
vector<int> g[MAXN ];
bool who[MAXN * 50];
int res = 0;
vector<int> rg[MAXN];
vector<bool> used[102];






vector<int> ord;
int used1[MAXN * 50];
int st[MAXN * 50];
int id[MAXN * 50];
int nxt[MAXN * 50];
int lst[MAXN * 50];
int uks = 0;
int kek[MAXN * 50];

void add(int a, int b) {
	if (st[a] == 0) {
		uks++;
		st[a] = uks;
		id[uks] = b;
		lst[a] = uks;
		nxt[uks] = -1;
	} else {
		uks++;
		nxt[lst[a]] = uks;
		nxt[uks] = -1;
		lst[a] = uks;
		id[uks] = b;
	}
}
void dfs1(int u, int t) {
	used1[u * d + t] = true;
	for (auto h: g[u]) {
		if (!used1[h * d + (t + 1) % d]) {
			dfs1(h, (t + 1) % d);
		}
	}
	ord.pb(u * d + t);
}


int used2[MAXN];


void dfs2(int u, int t, int c) {
	used1[u * d + t] = c;
	if (who[u * d + t]) {
		if (used2[u] != c) {
			kek[c]++;
			used2[u] = c;
		}
	}
	//cout << who[u * d + t] << ' ' << c << endl;
	for (auto h: rg[u]) {
		if (!used1[h * d + (t - 1 + d) % d]) {
			dfs2(h, (t - 1 + d) % d, c);
		}
	}
}



int  main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);	
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
		rg[v].pb(u);
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < d; j++) {
			if (s[j] == '1') {
				who[i * d + j] = true;
				//cout << i * d + j << endl;
			}
		}
	}
	for (int i = 0; i < n * d; i++) {
		if (!used1[i]) {
			dfs1(i / d, i % d);
		}
	}
	memset(used1, 0, sizeof(used1));
	int cur = 1;
	reverse(all(ord));
	for (auto x: ord) {
		if (!used1[x]) {
			dfs2(x / d, x % d, cur);
			cur++;
		}
	} 
	for (int i  = 0; i < n * d; i++) {
		//cout << i << ' ' << col[i] << endl;
		for (auto x: g[i / d]) {
			int f = (i % d + 1) % d;
			if (used1[i] != used1[x * d + f]) {
				add(used1[i], used1[x * d + f]);
			//	v[used1[i]].pb(used1[x * d + f]);
			}
		}
	}
	int ff = used1[0];
	for (int x = cur - 1; x >= 1; x--) {
		//cout << x << endl;
		int dp = 0;
		int cur = st[x];
		if (cur) {
			while (cur != -1) {
				chkmax(dp, kek[id[cur]]);
				cur = nxt[cur];
			}
		}
		//cout << dp << ' ' << x << endl;
		kek[x] += dp;
	}
	cout << kek[ff] << endl;
 	return 0; 
}