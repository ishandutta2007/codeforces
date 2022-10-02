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
const int MAXN = 100228;


int n;
vector<int> g[MAXN];
int mincnt = 0, maxcnt = 0;
int deep[MAXN];
int cnt[2];


void dfs(int u, int pr = -1) {
	int kek = 0;
	for (auto h: g[u]) {
		if (h != pr) {
			kek++;
			maxcnt++;
			deep[h] = deep[u] + 1;
			dfs(h, u);
		}
	}
	if (kek == 0) {
		cnt[deep[u] % 2]++;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n;
    for (int i = 0; i <n - 1; i++) {
    	int a, b;
    	cin >> a >> b;
    	a--, b--;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
    	if (sz(g[i]) != 1) {
    		root = i;
    	}
    }
    for (int i = 0; i < n; i++) {
    	if (sz(g[i]) != 1) {
    		int cnt = 0;
    		vector<int> st, st1;
    		for (auto h: g[i]) {
    			if (sz(g[h]) == 1) {
    				cnt++;
    				st1.pb(h);
    			} else {
    				st.pb(h);
    			}
    		}
    		g[i] = st;
    		if (cnt) {
    			g[i].pb(st1[0]);
    		}
    	}
    }
    dfs(root);
    if (cnt[0] && cnt[1]) {
    	mincnt = 3;
    } else {
    	mincnt = 1;
    }
    cout << mincnt << ' ' << maxcnt << '\n';
}