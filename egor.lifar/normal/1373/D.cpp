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


int n;
ll a[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	int t;
 	cin >> t;
 	while (t--) {
 		cin >> n;
 		ll ans = 0;
 		for (int i = 0; i < n; i++) {
 			cin >> a[i];
 			if (i % 2 == 0) {
 				ans += a[i];
 			}
 		}
 		ll cur = ans;
 		ll pref0 = 0, pref1 = 0;
 		ll gk = -1e18;
 		ll gk1 = -1e18;
 		for (int i = 0; i < n; i++) {
 			if (i % 2 == 0) {
 				chkmax(gk, -(pref1 - pref0));
 			} else {
 				chkmax(gk1, -(pref1 - pref0));
 			}
 			if (i % 2 == 0) {
 				pref0 += a[i];
 			} else {
 				pref1 += a[i];
 			}
 			if (i % 2 == 0) {
 				ll kek = pref1 - pref0;
 				chkmax(ans, cur + kek + gk1);
 			} else {
 				ll kek = pref1 - pref0;
 				//cout << cur + kek + gk << endl;
 				chkmax(ans, cur + kek + gk);
 			}
 		}
 		cout << ans << '\n';
 	}
	return 0;	 	
}