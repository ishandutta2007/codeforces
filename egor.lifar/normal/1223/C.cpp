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
const int MAXN = 200228;



int q;
int n;
int p[MAXN];
ll x, a, y, b;
ll k;
ll pref[MAXN];


ll gcd(ll a, ll b) {
	return (a == 0 ? b: gcd(b % a, a));
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	cin >> x >> a >> y >> b >> k;
	sort(p, p + n);
	reverse(p, p + n);
	if (x < y) {
		swap(x, y);
		swap(a, b);
	}
	ll f = a * b;
	f /= gcd(a, b);
	ll res = 1e9;
	for (int i = 0; i < n; i++) {
		pref[i] = p[i];
		if (i) {
			pref[i] += pref[i - 1];
		}
		int cnt = (i + 1) / b;
		int cnt1 = (i + 1) / a;
		int cnt2 = (i + 1) / f;
		cnt -= cnt2;
		cnt1 -= cnt2;
		ll cur = (cnt2 >= 1 ? pref[cnt2 - 1]: 0) / 100 * (x + y) + (cnt1 >= 1 ? pref[cnt1 + cnt2 - 1] - (cnt2 > 0 ? pref[cnt2 - 1]: 0): 0) / 100 * x + (cnt >= 1 ? pref[cnt + cnt1 + cnt2 - 1] - (cnt1 + cnt2 > 0 ? pref[cnt1 + cnt2 - 1]: 0): 0) / 100 * y;
		if (cur >= k) {
			chkmin(res, i + 1);
		}
	}
	if (res > n) {
		res = -1;
	}
	cout << res << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> q;
	for (int it = 0; it < q; it++) {
		solve();
	}
	return 0;
}