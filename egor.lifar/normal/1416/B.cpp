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
const int MAXN = 10228;


int n;
ll a[MAXN];
ll have[MAXN];


void solve() {
	cin >> n;
	//n = rand() % 10;
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//a[i] = rand() % 20 + 1;
		s += a[i];
	}
	if (s % n != 0) {
		cout << -1 << '\n';
		return;
	}
	ll need = s / n;
	vector<pair<pair<int, int>, int> > res;
	vector<pair<int, int> > bads;
	set<pair<int, int> > ss;
	for (int i = 2; i <= n; i++) {
	//	if (a[i] % i > need) {
			bads.pb(mp(i - a[i] % i, i));
	//	} 
		ss.insert(mp(a[i] - a[i] % i, i));
	}
	sort(all(bads));
	for (auto x: bads) {
		while (a[1] < x.first && !ss.empty()) {
			auto y = *ss.rbegin();
			ss.erase(y);
			a[1] += y.first;
			res.pb(mp(mp(y.second, 1), y.first / y.second));
			a[y.second] -= y.first;
		}
		if (a[1] < x.first) {
			cout << -1 << '\n';
			return;
		}
		res.pb(mp(mp(1, x.second), x.first));
		a[1] -= x.first;
		ss.erase(mp(a[x.second] - a[x.second] % x.second, x.second));
		a[x.second] += x.first;
		assert(a[x.second] % x.second == 0);
		ss.insert(mp(a[x.second] - a[x.second] % x.second, x.second));
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] > need) {
			ll f = a[i] / i;
			res.pb(mp(mp(i, 1), f));
			a[i] -= f * i;
			a[1] += f * i;
			assert(a[i] <= need);
		}
	}
	for (int i = 2; i <= n; i++) {
		if (a[i] < need) {
			ll val = need - a[i];
			a[1] -= val;
			a[i] += val;
			res.pb(mp(mp(1, i), val));
		}
	}
	for (int i = 1; i <= n; i++) {
		assert(a[i] == need);
	}
	assert(sz(res) <= 3 * n);
	cout << sz(res) << '\n';
	for (auto x: res) {
		cout << x.first.first << ' ' << x.first.second << ' ' << x.second << '\n';
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}