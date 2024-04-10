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
const int MAXN = 305;


int n, m;
int a[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	bool bad = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int i1 = i + dx[k];
				int j1 = j + dy[k];
				if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
					continue;
				} 
				cnt++;
			}
			if (cnt < a[i][j]) {
				bad = true;
			} 
			a[i][j] = cnt;
		}
	}
	if (bad) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
	return 0;	 	
}