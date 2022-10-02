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


ll p, q;


void solve() {
	cin >> p >> q;
	if (p % q != 0) {
		cout << p << '\n';
		return;
	}
	ll a = 2;
	vector<pair<ll, int> > st1;
	while (a * a <= q) {
		if (q % a == 0) {
			int cnt = 0;
			while (q % a == 0) {
				q /= a;
				cnt++;
			}
			st1.pb(mp(a, cnt));
		}
		a++;
	}
	if (q != 1) {
		st1.pb(mp(q, 1));
	}
	ll res = 0;
	for (auto x: st1) {
		ll ans = p;
		int cnt = 0;
		while (ans % x.first == 0) {
			ans /= x.first;
			cnt++;
		}
		for (int j = 0; j < min(cnt, x.second - 1); j++) {
			ans *= x.first;
		}
		chkmax(res, ans);
	}
	cout << res << '\n';
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