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



vector<pair<int, int> > res;



void resolve(vector<vector<int> > &a) {
	if (sz(a) <= 2) {
		return;
	}
	
	vector<pair<int, int> > st;
	for (int i = 0; i < sz(a); i++) {
		st.pb(mp(sz(a[i]), i));
	}
	sort(all(st));
	for (int i = 0; i < sz(st) - 1; i++) {
		if (st[i].first == st[i + 1].first) {
			int id = st[i].second;
			int id1 = st[i + 1].second;
			for (int t = 0; t < st[i].first; t++) {
				res.pb(mp(a[id][t], a[id1][t]));
			}
			for (auto y: a[id1]) {
				a[id].pb(y);
			}
			a[id1].clear();
			swap(a[id1], a.back());
			a.pop_back();
			resolve(a);
			return;
		}
	}
	for (int i = 0; i < 1; i++) {
		int id = st[i].second;
		for (int t = 0; t < st[i].first; t++) {
			res.pb(mp(a[id][t], a[st.back().second].back()));
			int x = a[st.back().second].back();
			a[st.back().second].pop_back();
			a[id].pb(x);
		}
	}
	if (a[st.back().second].empty()) {
		swap(a[st.back().second], a.back());
		a.pop_back();
	}
	resolve(a);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int n;
	cin >> n;
	vector<vector<int> > st;
	for (int i = 1; i <= n; i++) {
		st.pb(vector<int>{i});
	}
	vector<vector<int> > a;
	while (true) {
		if (sz(st) == 1) {
			a.pb(st[0]);
			break;
		}
		if (sz(st) & 1) {
			a.pb(st.back());
		}
		vector<vector<int> > st1;
		for (int i = 0; i + 1 < sz(st); i+= 2) {
			vector<int> str;
			for (int j = 0; j < sz(st[i]); j++) {
				res.pb(mp(st[i][j], st[i + 1][j]));
				str.pb(st[i][j]);
				str.pb(st[i + 1][j]);
			}
			st1.pb(str);
		}
		st = st1;
	}
	resolve(a);
	cout << sz(res) << '\n';
	for (int i = 0; i < sz(res); i++) {
		cout << res[i].first << ' ' << res[i].second << '\n';
	}
}