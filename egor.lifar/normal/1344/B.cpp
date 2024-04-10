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
const int MAXN = 1028;


int n, m;
string s[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool used[MAXN][MAXN];


void dfs(int i, int j) {
	used[i][j] = true;
	for (int k = 0; k < 4; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 0 && i1 <  n && j1 >= 0 && j1 < m && s[i1][j1] == '#') {
			if (!used[i1][j1]) {
				dfs(i1, j1);
			}
		}
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   // read(FILENAME);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (s[i][j] == '#') {
    			cnt++;
    		}
    	}
    }
    int cnts = 0;
    for (int i = 0; i < n; i++) {
    	bool was = false;
    	int posl;
    	for (int j = 0; j < m; j++) {
    		if (s[i][j] == '#') {
    			was = true;
    			posl = j;
    			break;
    		}
    	}
    	if (was) {
    		int posr;
    		for (int j = m - 1; j >= 0; j--) {
    			if (s[i][j] == '#') {
    				posr = j;
    				break;
    			}
    		}
    		for (int j = posl; j <= posr; j++) {
    			if (s[i][j] != '#') {
    				cout << -1 << '\n';
    				exit(0);
    			}
    		}
    	} else {
    		cnts++;
    	}
    }
    int cnts1 = 0;
    for (int i = 0; i < m; i++) {
    	bool was = false;
    	int posl;
    	for (int j = 0; j < n; j++) {
    		if (s[j][i] == '#') {
    			was = true;
    			posl = j;
    			break;
    		}
    	}
    	if (was) {
    		int posr;
    		for (int j = n - 1; j >= 0; j--) {
    			if (s[j][i] == '#') {
    				posr = j;
    				break;
    			}
    		}
    		for (int j = posl; j <= posr; j++) {
    			if (s[j][i] != '#') {
    				cout << -1 << '\n';
    				exit(0);
    			}
    		}
    	} else {
    		cnts1++;
    	}
    }
    if (n == 1 || m == 1) {
    	if (cnt == 0) {
    		cout << 0 << '\n';
    		return 0;
    	}
    	if (cnt == n * m) {
    		cout << 1 << '\n';
    		return 0;
    	}
    	cout << -1 << '\n';
    	return 0;
    }
    if (cnts && !cnts1) {
    	cout << -1 << '\n';
    	return 0;
    }
    if (cnts1 && !cnts) {
    	cout << -1 << '\n';
    	return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		if (s[i][j] == '#') {
    			if (!used[i][j]) {
    				dfs(i, j);
    				ans++;
    			}
    		}
    	}
    }
    cout << ans << '\n';
}