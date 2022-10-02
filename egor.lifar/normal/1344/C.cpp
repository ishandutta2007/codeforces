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
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
const string FILENAME = "input";
const int MAXN = 200228;

int n, m;
vector<int> g[MAXN];
bool used[MAXN];
vector<int> st;
int pos[MAXN];
vector<int> rg[MAXN];
bool bad[MAXN];
int mind[MAXN];


void dfs(int u) {
	used[u] = true;
	for (auto h: g[u]) {
		if (!used[h]) {
			dfs(h);
		}
	}
	st.pb(u);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
   	cin >> n >> m;
   	for (int i = 0; i < m; i++) {
   		int a, b;
   		cin >> a >> b;
   		a--, b--;
   		g[a].pb(b);
   		rg[b].pb(a);
   	}
   	for (int i = 0; i < n; i++) {
   		if (!used[i]) {
   			dfs(i);
   		}
   	}
   	int it = 0;
   	for (auto x: st) {
   		pos[x] = it;
   		it++;
   	}
   	for (auto x: st) {
   		for (auto y: g[x]) {
   			if (pos[y] > pos[x]) {
   				cout << -1 << '\n';
   				return 0;
   			}
   		}
   	}
   	for (int it = 0; it < 2; it++) {
   		st.clear();
   		memset(used, 0, sizeof(used));
   		for (int i = 0; i < n; i++) {
	   		if (!used[i]) {
	   			dfs(i);
	   		}
	   	}
	   	reverse(all(st));
	   	for (int i = 0 ; i < n; i++) {
	   		mind[i] = i;
	   	}
	   	for (auto x: st) {
	   		if (mind[x] < x) {
	   			bad[x] = true;
	   		}
	   		for (auto h: g[x]) {
	   			chkmin(mind[h], mind[x]);
	   		}
	   	}
   		for (int i = 0 ; i < n; i++) {
   			g[i] = rg[i];
   		}
   	} 
   	string s;
   	int cnt = 0;
   	for (int i = 0; i < n; i++) {
   		if (!bad[i]) {
   			s += 'A';
   			cnt++;
   		} else {
   			s += 'E';
   		}
   	}
   	cout << cnt << '\n';
   	cout << s << '\n';
}