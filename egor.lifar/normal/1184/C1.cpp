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



int n;
int x[300], y[300];


bool check(vector<pair<int, int> > g) {
	int xl = 1e9;
	int xr = -1e9;
	int yr = -1e9;
	int yl = 1e9;
	for (auto x: g) {
		chkmax(xr, x.first);
		chkmin(xl, x.first);
		chkmax(yr, x.second);
		chkmin(yl, x.second);
	}
	if (xr - xl != yr - yl) {
		return false;
	}
	int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (auto x: g) {
		if (x.first == xl || x.first == xr || x.second == yl || x.second == yr) {
			if (x.first == xl) {
				cnt++;
			}
			if (x.first == xr) {
				cnt1++;
			}
			if (x.second == yl) {
				cnt2++;
			}
			if (x.second == yr) {
				cnt3++;
			}
			continue;
		}
		return false;
	}
	if (cnt < n || cnt1 < n || cnt2 < n || cnt3 < n) {
		return false;
	}
	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < 4 * n + 1; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < 4 * n + 1; i++) {
		vector<pair<int, int> > st;
		for (int j = 0; j < 4 * n + 1; j++) {
			if (j != i) {
				st.pb({x[j], y[j]});
			}
		}
		if (check(st)) {
			cout << x[i] << ' ' << y[i] << '\n';
			return 0;
		}
	}
	return 0;
}