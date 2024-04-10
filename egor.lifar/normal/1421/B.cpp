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



int n;
string s[205];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	} 
	vector<pair<int, int> > st;
	bool was = false, was1 = false;
	if (s[0][1] != s[1][0]) {
		st.pb(mp(0, 1));
		was = true;
	}
	if (s[n - 1][n - 2] != s[n - 2][n - 1]) {
		st.pb(mp(n - 1, n - 2));
		was1 = true;
	}
	if (st.empty()) {
		if (s[0][1] == s[n - 1][n - 2]) {
			st.pb(mp(0, 1));
			st.pb(mp(1, 0));
		}
	} else {
		if (s[1][0] == s[n - 2][n - 1]) {
			if (was1) {
				st.pop_back();
				st.pb(mp(n - 2, n - 1));
			} else {
				st.pop_back();
				st.pb(mp(1, 0));
			}
		}
	}
	cout << sz(st) << '\n';
	for (auto x: st) {
		cout << x.first + 1 << ' ' << x.second + 1 << '\n';
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
}