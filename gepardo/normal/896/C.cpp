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

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

queue<long long> codeforces;

struct Query {
	int op, l, r, x, y;
};

struct Segment {
	int64_t val;
	int len;
};

inline int64_t binPow(int64_t a, int n, int m) {
	int64_t res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		n >>= 1;
	}
	return res % m;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n, m, seed, vmax; cin >> n >> m >> seed >> vmax;
	
	function<int()> rnd = [&]() {
		int ret = seed;
		seed = ((int64_t)seed * 7 + 13) % 1000000007;
		return ret;
	};
	
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		a[i] = (rnd() % vmax) + 1;
	}
	vector<Query> q(m);
	for (int i = 0; i < m; i++) {
		q[i].op = rnd() % 4 + 1;
		q[i].l = rnd() % n;
		q[i].r = rnd() % n;
		if (q[i].l > q[i].r) {
			swap(q[i].l, q[i].r);
		}
		if (q[i].op == 3) {
			q[i].x = rnd() % (q[i].r - q[i].l + 1);
		} else {
			q[i].x = (rnd() % vmax) + 1;
		}
		if (q[i].op == 4) {
			q[i].y = (rnd() % vmax) + 1;
		}
	}
	
	basic_string<Segment> segments;
	for (int i = 0; i < n; i++) {
		segments += Segment {a[i], 1};
	}
	
	auto splitBy = [&](int point) -> int {
		for (int i = 0; i < (int)segments.size(); i++) {
			if (point < segments[i].len) {
				if (point == 0) {
					return i;
				} else {
					Segment newSeg {segments[i].val, point};
					segments[i].len -= point;
					segments.insert(segments.begin() + i, newSeg);
					return i+1;
				}
			}
			point -= segments[i].len;
		}
		return (int)segments.size();
	};
	
	for (Query query : q) {
		int lPos = splitBy(query.l);
		int rPos = splitBy(query.r+1);
		switch (query.op) {
			case 1 : {
				for (int i = lPos; i < rPos; i++) {
					segments[i].val += query.x;
				}
			} break;
			case 2 : {
				segments.erase(lPos, rPos - lPos);
				segments.insert(segments.begin() + lPos, Segment {query.x, query.r - query.l + 1});
			} break;
			case 3 : {
				vector<Segment> seg(segments.begin() + lPos, segments.begin() + rPos);
				sort(seg.begin(), seg.end(), [&](const Segment &a, const Segment &b) -> bool {
					return a.val < b.val;
				});
				int pos = query.x;
				for (int i = 0; i < (int)seg.size(); i++) {
					if (pos < seg[i].len) {
						cout << seg[i].val << "\n";
						break;
					}
					pos -= seg[i].len;
				}
			} break;
			case 4 : {
				int64_t ans = 0;
				for (int i = lPos; i < rPos; i++) {
					ans += (int64_t)segments[i].len * binPow(segments[i].val % query.y, query.x, query.y);
				}
				cout << ans % query.y << "\n";
			} break;
			default: {
				assert(false);
			}
		}
	}
	
	return 0;
}