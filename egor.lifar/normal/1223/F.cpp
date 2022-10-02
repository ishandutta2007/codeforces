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
const int MAXN = 300228;
const int P = 424243;
const int M = 1000000009;
const int P1 = 1000003;
const int M1 = 1000000007;
int n;
int a[MAXN];
ll res = 0;


void kek(int l, int r) {
	if (r - l + 1 <= 1) {
		return;
	}
	int mid = (l + r) >> 1;
	kek(l, mid);
	kek(mid + 1, r);
	map<pair<int, int> , int>  kek;
	vector<pair<int, ll> > st;
	st.pb({-1, 1});
	vector<pair<int, ll> > st1;
	st1.pb({-1, 1});
	for (int i = mid; i >= l; i--) {
		if (st.empty() || st.back().first != a[i]) {
			ll f = (st.empty() ? a[i]: (st.back().second * P + a[i]) % M);
			st.push_back({a[i], f});
		} else {
			st.pop_back();
		}
		if (st1.empty() || st1.back().first != a[i]) {
			ll f = (st1.empty() ? a[i]: (st1.back().second * P1 + a[i]) % M1);
			st1.push_back({a[i], f});
		} else {
			st1.pop_back();
		}
		kek[{st.back().second, st1.back().second}]++;
	}
	st.clear();
	st1.clear();
	st.pb({-1, 1});
	st1.pb({-1, 1});
	for (int i = mid + 1; i <= r; i++) {
		if (st.empty() || st.back().first != a[i]) {
			ll f = (st.empty() ? a[i]: (st.back().second * P + a[i]) % M);
			st.push_back({a[i], f});
		} else {
			st.pop_back();
		}
		if (st1.empty() || st1.back().first != a[i]) {
			ll f = (st1.empty() ? a[i]: (st1.back().second * P1 + a[i]) % M1);
			st1.push_back({a[i], f});
		} else {
			st1.pop_back();
		}
		res += kek[{st.back().second, st1.back().second}];
	}
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	res = 0;
	kek(0, n - 1);
	cout << res << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	int q;
	cin >> q;
	for (int it = 0; it < q; it++) {
		solve();
	}
	return 0;
}