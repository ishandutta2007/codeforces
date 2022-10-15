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
	//~ #define USE_FILE_IO
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

inline __int128 read128() {
	int64_t q; cin >> q;
	return q;
}

inline ostream &operator<<(ostream &os, __int128 x) {
	return os << (int64_t)x;
}

typedef __int128 i128;
typedef long double ld;

inline i128 add(i128 a, i128 b) {
	return a - 3*b*b - 3*b - 1;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	i128 k = read128();
	vector<i128> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = read128();
	}
	vector<i128> b(n);
	
	int64_t le = -(i128)4e18, ri = (i128)4e18;
	
	auto check = [&](i128 val) {
		i128 knt = 0;
		b.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			if (add(a[i], 0) <= val) return (i128)0;
		}
		for (int i = 0; i < n; ++i) {
			if (add(a[i], a[i]) > val) {
				knt += a[i];
				b[i] = a[i];
				continue;
			}
			i128 d = 9 - 12 * (1 + val - a[i]);
			assert(d >= 0);
			i128 root = (-(ld)3 + sqrtl(d)) / (ld)6;
			while (add(a[i], root) <= val) --root;
			while (add(a[i], root) > val) ++root;
			assert(root <= a[i]);
			knt += root;
			b[i] = root;
		}
		return knt;
	};
	
	while (le != ri) {
		i128 mid = le + (ri - le) / 2;
		if (check(mid) >= k) {
			le = mid+1;
		} else {
			ri = mid;
		}
	}
	
	i128 rem = k - check(le);
	for (int i = n-1; i >= 0; --i) {
		if (b[i] < a[i] && add(a[i], b[i]) == le) {
			++b[i];
			--rem;
		}
		if (!rem) break;
	}
	assert(rem == 0);
	
	for (int i = 0; i < n; ++i) {
		cout << b[i] << " ";
	}
	cout << "\n";
	
	return 0;
}