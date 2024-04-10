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
vector<int> need[30];
vector<int> f[30];



void solve() {
	for (int i = 0; i < 30; i++) {
		need[i].clear();
		f[i].clear();
	}
	cin >> n;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			cout << -1 << endl;
			return;
		}
		if (a[i] == b[i]) {
			continue;
		}
		need[b[i] - 'a'].pb(a[i] - 'a');
	}
	int ans = 0;
	for (int i = 0; i < 20; i++) {
		if (need[i].empty()) {
			continue;
		}
		sort(all(need[i]));
		need[i].resize(distance(need[i].begin(), unique(all(need[i]))));
		for (auto x: need[i]) {
			f[x].pb(i);
		}
	}
	for (int i = 0; i < 20; i++) {
		int td = 1e9;
		vector<int> st;
		for (auto y: f[i]) {
			if (y == i) {
				continue;
			}
			chkmin(td, y);
			st.pb(y);
		}
		if (!st.empty()) {
			ans++;
			for (auto x: st) {
				f[td].pb(x);
			}
		}
	}	
	cout << ans << '\n';
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