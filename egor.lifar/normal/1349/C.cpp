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
const int MAXN = 1005;



int n, m, t;
string s[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int parent[MAXN * MAXN];
int cnt[MAXN * MAXN];
int mind[MAXN][MAXN];


int findset(int v) {
	if (v == parent[v]) {
		return v;
	}
	return parent[v] = findset(parent[v]);
}


void unite(int a, int b) {
	a = findset(a);
	b = findset(b);
	if (a == b) {
		return;
	}
	parent[a] = b;
	cnt[b] += cnt[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 //	read(FILENAME);	
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)  {
    	cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		parent[i * m + j] = i * m + j;
    		cnt[i * m + j] = 1;
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		for (int k = 0; k < 4; k++) {
    			int i1 = i + dx[k];
    			int j1 = j + dy[k];
    			if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
    				continue;
    			}
    			if (s[i][j] == s[i1][j1]) {
    				unite(i * m + j, i1 * m + j1);
    			}
    		}
    	}
    }
    queue<pair<int, int> > q;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (cnt[findset(i * m + j)] >= 2) {
    			q.push(mp(i, j));
    			mind[i][j] = 0;
    		} else {
    			mind[i][j] = -1;
    		}
    	}
    }
    while (!q.empty()) {
    	auto a = q.front();
    	q.pop();
    	for (int k = 0; k < 4; k++) {
			int i1 = a.first + dx[k];
			int j1 = a.second + dy[k];
			if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
				continue;
			}
			if (mind[i1][j1] == -1) {
				q.push(mp(i1, j1));
				mind[i1][j1] = mind[a.first][a.second] + 1;
			}
		}
    }
    for (int it = 0; it < t; it++) {
    	int i, j;
    	ll p;
    	cin >> i >> j >> p;
    	i--, j--;
    	if (mind[i][j] == -1) {
    		cout << s[i][j] << '\n';
    	} else {
    		int t = mind[i][j];
    		if (t >= p) {
    			cout << s[i][j] << '\n';
    		} else {
    			int k = (p - t) & 1;
    			if (k == 0) {
    				cout << s[i][j] << '\n';
    			} else {
    				cout << char(1 - (s[i][j] - '0') + '0') << '\n';
    			}
    		}
    	}
    }
}