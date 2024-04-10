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
const int MAXN = 1028;
 
 
 
int n;
int a[MAXN];
vector<int> g[MAXN];
int pos[MAXN];
int b[MAXN];

 
bool comp(int i, int j) {
	return b[i] > b[j];
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	cin >> n;
	vector<pair<int, int> > st;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st.pb(mp(a[i], i));
	}
	sort(all(st));
	for (int i = 0; i < sz(st); i++) {
		b[st[i].second] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				g[i].pb(j);
			}
		}
	}
	vector<pair<int, int> > res;
	for (int i = 0; i < n; i++) {
		sort(all(g[i]), comp);
		for (auto h: g[i]) {
			res.pb(mp(i + 1, h + 1));
			swap(a[i], a[h]);
			swap(b[i], b[h]);
		}
	}
	for (int i = 0; i < n - 1; i++) {
		assert(a[i] <= a[i + 1]);
	}
	cout << sz(res) << '\n';
	for (auto x: res) {
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;	 	
}