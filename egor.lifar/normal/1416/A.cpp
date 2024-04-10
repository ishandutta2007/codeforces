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
const int MAXN = 300229;




int n;
vector<int> where[MAXN];
int ans[MAXN];
int a[MAXN];


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		where[i].clear();
	}	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		where[a[i]].pb(i);
	}
	for (int i = 0; i <= n; i++) {
		ans[i] = 1e9;
	}
	for (int i = 1; i <= n; i++) {
		int last = 0;
		int t = 0;
		for (auto x: where[i]) {
			chkmax(t, x - last);
			last = x + 1;
		}
		chkmax(t, n - last);
		chkmin(ans[t + 1], i);
	}
	for (int i = 1; i <= n; i++) {
		chkmin(ans[i], ans[i - 1]);
		if (ans[i] > n) {
			cout << -1 << ' ';
		} else {
			cout << ans[i] << ' ';
		}
	}
	cout << '\n';
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