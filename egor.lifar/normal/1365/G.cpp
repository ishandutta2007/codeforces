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
const int MAXN = 1005;


ll myQuery(vector<ll> res) {
	if (res.empty()) {
		return 0;
	}
	cout << "? " << sz(res);
	for (auto x: res) {
		cout << ' ' << x + 1;
	}
	cout << endl;
	ll rep;
	cin >> rep;
	return rep;
}


ll kek[MAXN], kek1[MAXN];
ll ans[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
 	//read(FILENAME);
	int n;
	cin >> n;
	int uk = 0;
	for (int i = 0; i < (1 << 13); i++) {
		if (__builtin_popcount(i) == 6 && uk < n) {
			kek[uk] = i;
			uk++;
		}
	}
	for (int it = 0; it < 13; it++) {
		vector<ll> res;
		for (int i = 0; i < n; i++) {
			if ((kek[i] >> it) & 1) {
				res.pb(i);
			}
		}
		ll rep = myQuery(res);
		for (int j = 0; j < 64; j++) {
			if ((rep >> j) & 1LL) {
				kek1[j] |= (1LL << it);
			}
		}
	}
	for (int j = 0; j < 64; j++) {
		if (kek1[j]) {
			for (int i = 0; i < n; i++) {
				if (kek[i] != kek1[j]) {
					ans[i] ^= (1LL << j);
				}
			}
		}
	}
	cout << '!';
	for (int i = 0; i < n; i++) {
		cout << ' ' << ans[i];
	}
	cout << endl;
	return 0; 	
}