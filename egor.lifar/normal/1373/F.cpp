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
const int MAXN = 2000228;



int n;
int a[MAXN], b[MAXN];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
 	int ts;
 	cin >> ts;
 	while (ts--) {
 		cin >> n;
 		for (int i = 0; i < n; i++) {
 			cin >> a[i];
 		}
 		for (int i = 0; i < n; i++) {
 			cin >> b[i];
 		}
 		bool bad = false;
 		ll sum = 0;
 		ll sum1 = 0;
 		for (int i = 0; i < n; i++) {
 			sum += b[i];
 			sum1 += a[i];
 			int j = (i - 1 + n) % n;
 			if (b[j] + b[i] < a[i]) {
 				bad = true;
 			}
 		}	
 		if (sum < sum1) {
 			bad = true;
 		}
 		for (int i = 0; i < n; i++) {
 			a[i + n] = a[i];
 			b[i + n] = b[i];
 		}
 		ll prefa = 0;
 		ll prefb = 0;
 		ll cur = 1e18;
 		for (int i = 0; i < 2 * n; i++) {
 			prefa += a[i];
 			prefb += b[i];
 			ll val = prefa - prefb;
 			if (val - cur > 0) {
 				bad = true;
 				break;
 			}
 			ll sub = prefa - (prefb - b[i]);
 			chkmin(cur, sub);
 		}
 		if (bad) {
 			cout << "NO\n";
 			continue;
 		}
 		cout << "YES\n";
 	}
	return 0;	 	
}