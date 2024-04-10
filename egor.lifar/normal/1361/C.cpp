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
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 1200228;



int n;
int a[MAXN], b[MAXN];
int as[MAXN], bs[MAXN];
vector<pair<int, int> > g[MAXN];
int deg[MAXN];
int parent[MAXN];
bool used[MAXN];
vector<int> k[MAXN];
map<pair<int, int>, vector<int> > who;


int findset(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = findset(parent[v]);
}


vector<int> str;


void dfs(int u) {
	while (!g[u].empty()) {
		auto x = g[u].back();
		g[u].pop_back();
		if (used[x.second]) {
			continue;
		}
		used[x.second] = true;
		if (x.first != u) {
			dfs(x.first);
		}
	}
	str.pb(u);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int t = 20; t >= 0; t--) {
		memset(deg, 0, sizeof(deg));
		int f = (1 << t) - 1;
		for (int i = 0; i < n; i++) {
			as[i] = a[i] & f;
			bs[i] = b[i] & f;
		}
		for (int i = 0; i < n; i++) {
			deg[as[i]]++;
			deg[bs[i]]++;
		}
		bool bad = false;
		for (int i = 0; i < (1 << 20); i++) {
			parent[i] = i;
			if (deg[i] & 1) {
				bad = true;
				break;
			}
		}
		if (bad) {
			continue;
		}
		for (int i = 0; i < n; i++) {
			parent[findset(as[i])] = findset(bs[i]);
		}
		for (int i = 0; i < n; i++) {
			if (findset(as[i]) != findset(as[0])) {
				bad = true;
				break;
			}
		}
		if (bad) {
			continue;
		}
		if (!bad) {
			cout << t << '\n';
			for (int i = 0; i < n; i++) {
				g[as[i]].pb(mp(bs[i], i));
				g[bs[i]].pb(mp(as[i], i));
				who[mp(as[i], bs[i])].pb(i);
				who[mp(bs[i], as[i])].pb(i);
				if (as[i] == bs[i]) {
					k[as[i]].pb(i);
				}
			}
			dfs(as[0]);
			reverse(all(str));
			vector<int> st;
			if (sz(str) == 1) {
				for (auto x: k[str[0]]) {
					st.pb(x);
				}
				k[str[0]].clear();
			}
			for (int i = 0; i < sz(str) - 1; i++) {
				for (auto x: k[str[i]]) {
					st.pb(x);
				}
				k[str[i]].clear();
				st.pb(who[mp(str[i], str[i + 1])].back());
				who[mp(str[i], str[i + 1])].pop_back();
				who[mp(str[i + 1], str[i])].pop_back();
			}
			//reverse(all(st));
			int cur = as[0];
			for (int i = 0; i < sz(st); i++) {
				if (as[st[i]] == cur) {
					cout << st[i] * 2 + 1 << ' ' << st[i] * 2 + 2 << ' '; 
					cur = bs[st[i]];
				} else {
					assert(bs[st[i]] == cur);
					cout << st[i] * 2 + 2 << ' ' << st[i] * 2 + 1 << ' '; 
					cur = as[st[i]];
				}
			}
			cout << '\n';
			return 0;
		}
	}
	return 0; 	
}