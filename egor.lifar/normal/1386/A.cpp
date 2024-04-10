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


bool ask(ll x) {
	cout << "? " << x << endl;
	int resp;
	cin >> resp;
	return resp;
}


void solve() {
	ll n;
	cin >> n;
	ll cur = 0;
	ll start = n;
	ll l = 1;
	ll r = n - 1;
	int g = 0;
	while (l <= r) {
		ll mid = (l + r) / 2;
		cur += (!g ? mid: -mid);
		chkmin(start, n - cur);
		l = mid + 1;
		g ^= 1;
	}
	l = 1;
	r = n - 1;
	g = 0;
	ll res = n;
	ask(start);
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll nstart = start + (!g ? mid: -mid);
		if (ask(nstart)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
		start = nstart;
		g ^= 1;
	}
	cout << "= " << res << endl;
}


int main() {
	ios_base::sync_with_stdio(false);
	//read(FILENAME);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}