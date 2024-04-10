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
template<typename T1, typename T2> inline bool chkmin(T1 &a, T2 b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T1, typename T2> inline bool chkmax(T1 &a, T2 b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
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



void solve() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s;
	cin >> s;
	int cnta = 0, cntb = 0;
	for (auto x: s) {
		if (x == 'A') {
			cnta++;
		} else {
			cntb++;
		}
	}
	if (cnta != a + c + d) {
		cout << "NO\n";
		return;
	}
	if (cntb != b + c + d) {
		cout << "NO\n";
		return;
	}
	vector<pair<char, int> > st;
	for (int i = 0; i < sz(s); i++) {
		if (st.empty() || st.back().first != s[i]) {
			st.pb(mp(s[i], 1));
		} else {
			st.back().second++;
		}
	}
	int uk = 0;
	int bal = 0;
	vector<int> kek[2];
	while (uk + 1 < sz(st)) {
		int cnt = 1;
		int pt = uk;
		while (uk + 1 < sz(st) && st[uk + 1].second == 1) {
			cnt++;
			uk++;
		}
		if (uk + 1 < sz(st)) {
			cnt++;
		}
		char pos = st[pt].first;
		if (cnt % 2 == 1) {
			bal += cnt / 2;
		} else {
			kek[pos - 'A'].pb(cnt / 2);
		}
		uk++; 
	}
	sort(all(kek[0]));
	sort(all(kek[1]));
	for (auto x: kek[0]) {
		if (c >= x) {
			c -= x;
		} else {
			bal += x - 1;
		}
	}
	for (auto x: kek[1]) {
		if (d >= x) {
			d -= x;
		} else {
			bal += x - 1;
		}
	}
	if (bal >= c + d) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}