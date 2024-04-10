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





void solve() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << n / 2 << ' ' << n / 2 << '\n';
		return;
	}
	ll ans = n - 1;
	vector<int> st;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			st.pb(i);
			st.pb(n / i);
		}
	}
	for (auto x: st) {
		ll y = n / x;
		if (y == 1) {
			continue;
		}
		chkmin(ans, (ll)x * (y - 1));
	}
	cout << ans << ' ' << n - ans << '\n';
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