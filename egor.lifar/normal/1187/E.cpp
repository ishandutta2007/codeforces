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
    
     
using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; } 
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define next next228
#define rank rank228
#define prev prev228
#define y1 y1228                                                         
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
const string FILENAME = "input";
const int MAXN = 300228;


int n;
vector<int> g[MAXN];
int sz[MAXN];
long long sum = 0;
long long ans = 0;

void dfs(int u, int pr = -1) {
	sz[u] = 1;
	for (auto h: g[u]) {
		if (h == pr) continue;
		dfs(h, u);
		sz[u] += sz[h];
	}
}


long long diff = 0;

void dfs1(int u, int pr = -1) {
	chkmax(ans, sum - diff - sz[u] + n);
	for (auto h: g[u]) {
		if (h == pr) continue;
		diff += sz[u] - (n - sz[h]);
		dfs1(h, u);
		diff -= sz[u] - (n - sz[h]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}	
	dfs(1);	
	for (int i = 1; i <= n; i++) {
		sum += sz[i];
	}
	dfs1(1);
	cout << ans << endl;
	return 0; 			
}