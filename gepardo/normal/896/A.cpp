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

#define int int64_t

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int q; cin >> q;
	string inner = "What are you doing at the end of the world? Are you busy? Will you save us?";
	string head = "What are you doing while sending \"";
	string middle = "\"? Are you busy? Will you send \"";
	string tail = "\"?";
	
	vector<int64_t> lensOf;
	
	lensOf.push_back((int)inner.size());
	for (;;) {
		int64_t newVal = 2 * lensOf.back() + (int)head.size() + (int)middle.size() + (int)tail.size();
		if (newVal > (int64_t)2e18) {
			break;
		}
		lensOf.push_back(newVal);
	}
	
	string res = "";
	for (int i = 0; i < q; i++) {
		
		function<char(int64_t, int64_t)> getChar = [&](int64_t n, int64_t k) -> char {
			if (n == 0) {
				return (k >= (int)inner.size()) ? '.' : inner[k];
			}
			if (k < (int)head.size()) {
				return head[k];
			}
			k -= (int)head.size();
			if (n-1 >= (int)lensOf.size() || k < lensOf[n-1]) {
				return getChar(n-1, k);
			}
			k -= lensOf[n-1];
			if (k < (int)middle.size()) {
				return middle[k];
			}
			k -= (int)middle.size();
			if (k < lensOf[n-1]) {
				return getChar(n-1, k);
			}
			k -= lensOf[n-1];
			if (k < (int)tail.size()) {
				return tail[k];
			}
			k -= (int)tail.size();
			return '.';
		};
		
		int64_t n, k; cin >> n >> k; k--;
		res += getChar(n, k);
	}
	cout << res << endl;
	return 0;
}