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


int n, k;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
// 	read(FILENAME);
 	int ts;
 	cin >> ts;
 	while (ts--) {
 		cin >> n >> k;
 		string gg;
 		for (int c = 0; c < 10; c++) {
 			for (int t = 0; t <= n; t++) {
 				for (int g = 0; g < 9; g++) {
 					for (int add = 0; add <= n; add++) {
 						int keks = 0;
 						for (int tr = 0; tr <= k; tr++) {
 							int c1 = c + tr;
 							int tp = 0;
 							if (c1 >= 10) {
 								c1 -= 10;
 								tp = 1;
 							}
 							int sum = c1;
 							if (tp) {
 								sum += g + 1;
 							} else {
 								sum += 9 * t + g;
 							}
 							keks += sum + add;
 						}
 						if (keks == n) {
 							//cout << c << ' ' << t << ' '
 							//cerr << "opa" << endl;
 							string f;
 							f += char('0' + c);
 							for (int j = 0; j < t; j++) {
 								f += char('0' + 9);
 							}
 							f += char('0' + g);
 							int adds = add;
 							while (adds > 0) {
 								int t = min(adds, 9);
 								adds -= t;
 								f += char('0' + t);
 							}
 							while (sz(f) > 1 && f.back() == '0') {
 								f.pop_back();
 							}
 							reverse(all(f));

 							if (gg.empty() || (sz(gg) > sz(f) || (sz(gg) == sz(f) && gg > f))) {
 								gg = f;
 							}
 						}
 					}
 				}
 			}
 		}
 		if (gg.empty()) {
 			gg = "-1";
 		}
 		cout << gg << endl;
 	}
	return 0;	 	
}