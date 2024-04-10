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
	int n; cin >> n;
	vector<int64_t> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	string s; cin >> s;
	int64_t time = 0;
	int64_t ec2 = 0, ec4 = 0;
	bool hpond = false;
	for (int i = 0; i < n; ++i) {
		int64_t len = v[i];
		switch (s[i]) {
			case 'G': {
				time += 5*len;
				ec4 += len;
				int64_t aid = min(len, ec2);
				ec2 -= aid;
				ec4 += aid;
			} break;
			case 'W': {
				time += 3*len;
				ec2 += len;
				hpond = true;
			} break;
			case 'L': {
				int64_t energy = len;
				int64_t spent = min(energy, ec2);
				energy -= spent;
				ec2 -= spent;
				spent = min(energy, ec4);
				energy -= spent;
				ec4 -= spent;
				if (hpond) {
					time += 3*energy;
				} else {
					time += 5*energy;
				}
				time += len;
			} break;
			default: {
				assert(false);
			}
		}
	}
	cout << time - ec2 - 2*ec4 << endl;
	return 0;
}