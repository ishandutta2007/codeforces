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
const int MAXN = 100228;
 
 
 
int n;
int a[MAXN];
 
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<pair<int, int> > res;
	int uk = 1;
	vector<pair<int, int> > st, st1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == 0) {
			continue;
		}
		if (a[i] == 1) {
			res.pb(mp(i + 1, uk));
			st.pb(mp(i + 1, uk));
			uk++;
		} else if (a[i] == 2) {
			if (st.empty()) {
				cout << -1 << '\n';
				return 0;
			}
			auto x = st.back();
			st.pop_back();
			res.pb(mp(i + 1, x.second));
			st1.pb(mp(i + 1, x.second));
		} else if (a[i] == 3) {
			if (st.empty() && st1.empty()) {
				cout << -1 << '\n';
				return 0;
			}
			pair<int, int> x;
			if (!st1.empty()) {
				x = st1.back();
				st1.pop_back();
			} else {
				x = st.back();
				st.pop_back();
			}
			res.pb(mp(i + 1, uk));
			res.pb(mp(x.first, uk));
			st1.pb(mp(i + 1, uk));
			uk++;
		} 
	}
	cout << sz(res) << '\n';
	for (auto x: res) {
		cout << n - x.second + 1 << ' ' << x.first << '\n';
	}
}