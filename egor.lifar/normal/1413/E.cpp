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


ll a, b, c, d;

void solve() {
	cin >> a >> b >> c >> d;
	if (a > c * b) {
		cout << -1 << '\n';
		return;
	}	
	if (d >= c) {
		cout << a << '\n';
		return;
	}
	ll ans = a;
	ll f = d * b - a;
	if (f < 0) {
		chkmax(ans, -f + a);
	}
	//d * t * (t + 1) / 2 * b - a * t
	//2 * (d * t * (t - 1) * b - 2 * a * t)
	//2 * (d * b * t * t + (-d * b - 2 * a) * t)
	//2 * d * b * (t * t) + (-d * b - 2 * a) * 2 * t
	//2 * d * b * t + (-d * b - 2 * a)
	//t = -(d * b - 2 * a) / (2 * d * b)
	ll val = (d * b + 2 * a) / (2 * d * b);
	for (ll k = max(0LL, val - 3); k <= val + 3; k++) {
		ll kek = d * k * (k - 1) / 2 * b - a * k;
		chkmax(ans, -kek);
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
	return 0;
}