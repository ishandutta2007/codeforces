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
const int MAXN = 500229;


int n, k;
int a[MAXN];
int b[MAXN];
int ans = 0;
int c[MAXN];
int f[MAXN];
int M;


void inc(int i, int val) {
	for (int j = i; j < M; j |= (j + 1)) {
		chkmax(f[j], val);
	}
}


int get(int i) {
	int tp = 0;
	for (int j = i; j >= 0; j = (j & (j + 1)) - 1) {
		chkmax(tp, f[j]);
	}
	return tp;
}


void solve(int l, int r) {
	int lx = (l > 0 ? a[l - 1]: -1e9 - 1000228);
	int rx = (r + 1 < n ? a[r + 1]: 1e9 + 1000228);
	if (lx + r - l + 1 >= rx) {
		cout << -1 << '\n';
		exit(0);
	}
	int res = r - l + 1;
	int t = lx;
	vector<pair<int, int> > st;
	for (int i = 0; i <= r - l; i++) {
		f[i] = 0;
	}
	M = r - l + 1;
	for (int i = l; i <= r; i++) {
		bool bad = false;
		if (a[i] - (i - l) <= lx || a[i] + (r - i) >= rx) {
			bad = true;
		}
		if (bad) {
			continue;
		}
		//a[i] - a[j] >= i - j
		//a[i] - i >= a[j] - j
		c[i] = a[i] - i;
		st.pb(mp(c[i], i));
	}
	sort(all(st));
	int d = 0;
	for (int i = 0; i < sz(st); i++) {	
		int cur = 1 + get(st[i].second - 1 - l);
		chkmax(d, cur);
		inc(st[i].second - l, cur);
	}
	res -= d;
	ans += res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> b[i];
		b[i]--;
	}
	int last = 0;
	for (int i = 0; i < k; i++) {
		solve(last, b[i] - 1);
		last = b[i] + 1;
	}
	solve(last, n - 1);
	cout << ans << '\n';
	return 0;
}