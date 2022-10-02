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
const int MAXN = 2028;



int n, m;
int a[MAXN], b[MAXN];
int c[MAXN], d[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> c[i] >> d[i];
	}
	vector<pair<int, int> > st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[j] >= a[i] && d[j] >= b[i]) {
				int va = c[j] - a[i] + 1;
				int vb = d[j] - b[i] + 1;
				st.pb(mp(va, vb));
			}
		}
	}
	if (st.empty()) {
		cout << 0 << '\n';
		return 0;
	}
	sort(all(st));
	int curb = 0;
	int ans = 2e9;
	for (int i = sz(st) - 1; i >= 0; i--) {
		chkmin(ans, st[i].first + curb);
		chkmax(curb, st[i].second);
	}
	chkmin(ans, curb);
	cout << ans << '\n';
}