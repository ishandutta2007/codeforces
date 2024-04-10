#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdint>
#include <cstring>
#include <random>
#include <chrono>
#include <list>
#include <deque>
#include <tuple>
#include <numeric>
#include <iomanip>

using namespace std;
using namespace chrono;

const int module = (int)1e9 + 7;
const int infinity = (int)1e9 + 42;
const int64_t llInf = (int64_t)1e18 + 256;

signed main() {
	#ifdef DEBUG
	//	stdin = freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	string s; cin >> s;
	static int has[26][26][10000] = {};
	
	int n = s.size();
	s += s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			has[s[i] - 'a'][s[i+j] - 'a'][j]++;
		}
	}
	
	int sum = 0;
	
	for (int i = 0; i < 26; i++) {
		int opt = 0;
		for (int k = 0; k < n; k++) {
			int kur = 0;
			for (int j = 0; j < 26; j++) {
				kur += (has[i][j][k] == 1);
			}
			opt = max(opt, kur);
		}
		sum += opt;
	}
	
	cout << fixed << setprecision(10) << (long double)sum / n << endl; 
	return 0;
}