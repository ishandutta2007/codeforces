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
const int MAXN = 2005;


int n, m;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int val[MAXN];
int nval[MAXN];
bool used[MAXN];
bool good[MAXN];
bitset<1505> kill[MAXN];
bitset<1505> restore[MAXN];
bitset<1505> need;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //read(FILENAME);
 	cin >> n >> m;
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < m; j++) {
 			cin >> a[i][j];
 		}
 	}
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < m; j++) {
 			cin >> b[i][j];
 		}
 	}
 	bool was = false;
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < m; j++) {
 			if (a[i][j] != b[i][j]) {
 				was = true;
 			}
 		}
 	}
 	if (!was) {
 		cout << 0 << '\n';
 		return 0;
 	}
 	vector<vector<int> > t;
 	for (int i = 0; i < n; i++) {
 		vector<int> d;
 		for (int j = 0; j < m; j++) {
 			d.pb(a[i][j]);
 		}
 		t.pb(d);
 	}
 	for (int i = 0; i < n; i++) {
 		vector<int> d;
 		for (int j = 0; j < m; j++) {
 			d.pb(b[i][j]);
 		}
 		t.pb(d);
 	}
 	sort(all(t));
 	t.resize(distance(t.begin(), unique(all(t))));
 	for (int i = 0; i < n; i++) {
 		vector<int> d;
 		for (int j = 0; j < m; j++) {
 			d.pb(a[i][j]);
 		}
 		val[i] = lower_bound(all(t), d) - t.begin();
 	}
 	for (int i = 0; i < n; i++) {
 		vector<int> d;
 		for (int j = 0; j < m; j++) {
 			d.pb(b[i][j]);
 		}
 		nval[i] = lower_bound(all(t), d) - t.begin();
 	}
 	vector<int> f, f1;
 	for (int i = 0; i < n; i++) {
 		f.pb(val[i]);
 		f1.pb(nval[i]);
 	}
 	sort(all(f));
 	sort(all(f1));
 	if (f != f1) {
 		cout << -1 << '\n';
 		exit(0);
 	}
	for (int j = 0; j < m; j++) {
		vector<pair<int, int> > f;
		for (int i = 0; i < n; i++) {
			f.pb(mp(t[val[i]][j], i));
		}	
		sort(all(f));
		bool bad = false;
		for (int i = 0; i < n; i++) {
			if (val[f[i].second] != nval[i]) {
				bad = true;
			}
		}
		if (!bad) {
			cout << 1 << '\n';
			cout << j + 1 << '\n';
			return 0;
		}
	}
	vector<pair<int, int> > st;
	for (int i = 0; i < n - 1; i++) {
		if (nval[i] != nval[i + 1]) {
			st.pb(mp(nval[i], nval[i + 1]));
		}
	}
	for (int j = 0; j < m; j++) {
		int it = 0;
		for (auto y: st) {
			int a = t[y.first][j];
			int b = t[y.second][j];
			if (a == b) {
				it++;
				continue;
			}
			if (a > b) {
				kill[j][it] = true;
			} else {
				restore[j][it] = true;
			}
			it++;
		}
	}
	for (int i = 0; i < sz(st); i++) {
		need[i] = true;
	}
	vector<int> ans;
	while (need.count()) {
		bool was = false;
		for (int j = 0; j < m; j++) {
			if (!used[j]) {
				if (!((kill[j] & need).count())) {
					used[j] = true;
					ans.pb(j + 1);
					was = true;
					need = need ^ (need & restore[j]);
				}
			}
		}
		if (!was) {
			break;
		}
	}
	if (need.count()) {
		cout << -1 << '\n';
		return 0;
	}
	reverse(all(ans));
	cout << sz(ans) << '\n';
	for (auto x: ans) {
		cout << x << ' ';
	}
	cout << '\n';
}