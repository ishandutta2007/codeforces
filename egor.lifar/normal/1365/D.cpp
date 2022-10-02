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
const int MAXN = 51;


int n, m;
string s[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool used[MAXN][MAXN];


void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int cnt = 0;
	bool bad = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			used[i][j] = false;
			if (s[i][j] == 'G') {
				cnt++;
			} else if (s[i][j] == 'B') {
				for (int k = 0; k < 4; k++) {
					int i1 = i + dx[k];
					int j1 = j + dy[k];
					if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
						continue;
					}
					if (s[i1][j1] == '.') {
						s[i1][j1] = '#';
					} else if (s[i1][j1] == 'G') {
						bad = true;
					}
				}
			}	
		}
	}
	if (s[n - 1][m - 1] == 'B' || bad) {
		cout << "No\n";
		return;
	}
	queue<pair<int, int> > q;
	if (s[n - 1][m - 1] != '#') {
		q.push(mp(n - 1, m - 1));
	}
	used[n - 1][m - 1] = true;
	if (s[n - 1][m - 1] == 'G') {
		cnt--;
	}
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int i1 = x.first + dx[k];
			int j1 = x.second + dy[k];
			if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
				continue;
			}
			if (s[i1][j1] != '#') {
				if (!used[i1][j1]) {
					if (s[i1][j1] == 'G') {
						cnt--;
					}
					used[i1][j1] = true;
					q.push(mp(i1, j1));
				}
			}
		}
	}
	if (cnt == 0) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
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