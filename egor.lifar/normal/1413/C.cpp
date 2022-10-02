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


int a[6];
int n;
int b[MAXN];
int c[MAXN][6];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	sort(a, a + 6);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			c[i][j] = b[i] - a[j];
		}
		sort(c[i], c[i] + 6);
	}
	vector<int> dd;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			dd.pb(c[i][j]);
		}
	}
	sort(all(dd));
	dd.resize(distance(dd.begin(), dd.end()));
	int ans = 2e9;
	set<pair<int, pair<int, int> > > s;
	int ks = 0;
	for (int i = 0; i < n; i++) {
		s.insert(mp(c[i][0], mp(i, 0)));
		chkmax(ks, c[i][0]);
	}
	for (auto x: dd) {
		bool bad = false;
		while (!s.empty()) {
			auto d = *s.begin();
			if (d.first < x) {
				if (d.second.second == 5) {
					bad = true;
					break;
				} 
				s.erase(d);
				chkmax(ks, c[d.second.first][d.second.second + 1]);
				s.insert(mp(c[d.second.first][d.second.second + 1], mp(d.second.first, d.second.second + 1)));
			} else {
				break;
			}
		}
		if (bad) {
			break;
		}
		chkmin(ans, ks - x);
	}
	cout << ans << '\n';
	return 0;
}