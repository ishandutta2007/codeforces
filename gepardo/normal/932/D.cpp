#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int q; cin >> q;
	const int l = 20;
	vector< vector<int> > up(q+2, vector<int>(l, 0));
	vector< vector<int64_t> > val(q+2, vector<int64_t>(l, 0));
	vector< vector<int> > up2(q+2, vector<int>(l, 0));
	vector< vector<int64_t> > val2(q+2, vector<int64_t>(l, 0));
	vector<int64_t> w(q+2);
	w[0] = (int64_t)1.5e15;
	int last = 0;
	int lv = 1;
	for (int i = 0; i < l; i++) {
		val[0][i] = val2[0][i] = w[0];
		val[1][i] = val2[1][i] = w[0];
	}
	val[1][0] = val2[1][0] = 0;
	for (int i = 0; i < q; i++) {
		int64_t type, p, q; cin >> type >> p >> q;
		p ^= last; q ^= last;
		//cerr << type << " " << p << " " << q << endl;
		if (type == 1) {
			lv++;
			w[lv] = q;
			up[lv][0] = p;
			val[lv][0] = q;
			for (int j = 1; j < l; j++) {
				up[lv][j] = up[up[lv][j-1]][j-1];
				val[lv][j] = max(val[lv][j-1], val[up[lv][j-1]][j-1]);
			}
			int wh = up[lv][0];
			for (int j = l-1; j >= 0; j--) {
				if (val[wh][j] < q) {
					//cout << "??? " << wh << " " << j << " " << val[wh][j] << endl;
					wh = up[wh][j];
				}
			}
			up2[lv][0] = wh;
			val2[lv][0] = q;
			//cout << "wh = " << wh << endl;
			//cout << "up :: " << up2[lv][0] << " " << val2[lv][0] << endl;
			for (int j = 1; j < l; j++) {
				up2[lv][j] = up2[up2[lv][j-1]][j-1];
				val2[lv][j] = val2[lv][j-1] + val2[up2[lv][j-1]][j-1];
				//cout << "up :: " << up2[lv][j] << " " << val2[lv][j] << " :: " << up2[lv][j-1] << " " << val2[up2[lv][j-1]][j-1] << endl;
			}
		} else {
			int ans = 0;
			for (int j = l-1; j >= 0; j--) {
				//cout << "!!! " << j << " " << up2[p][j] << " " << val2[p][j] << endl;
				if (val2[p][j] <= q) {
					q -= val2[p][j];
					p = up2[p][j];
					ans += 1 << j;
				}
			}
			last = ans;
			cout << ans << "\n";
		}
	}
	
	return 0;
}