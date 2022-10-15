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
	#undef assert
	#define assert(cond)
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

queue<long long> codeforces;

class DisjointSetUnion {
private:
	int n;
	vector<int> p;
	vector<int> sz;
public:
	int parent(int v) {
		if (p[v] < 0) {
			return v;
		} else {
			return p[v] = parent(p[v]);
		}
	}
	
	inline bool merge(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b) {
			return false;
		}
		if (sz[a] < sz[b]) {
			swap(a, b);
		}
		p[b] = a;
		sz[a] += sz[b];
		return true;
	}
	
	DisjointSetUnion(int n) :
		n(n), p(n, -1), sz(n, 1)
	{}
	
	DisjointSetUnion() {
	}
};

class NumBlock {
private:
	int len;
	vector<int> v;
	int head, tail;
	vector<int> knts;
	DisjointSetUnion mutate;
	vector<int> mutateVal;
	
	inline void moveVal(int dst, int src) {
		knts[dst] += knts[src];
		knts[src] = 0;
		mutate.merge(dst, src);
		mutateVal[mutate.parent(dst)] = dst;
	}
	
	inline int getVal(int elt) {
		return mutateVal[mutate.parent(v[elt])] - head;
	}
public:
	inline void updateAll(int delta) {
		if (delta == 0 || head + delta >= tail) {
			return;
		}
		if (head + 2*delta <= tail) {
			for (int i = head; i < head + delta; i++) {
				moveVal(i + delta, i);
			}
			head += delta;
		} else {
			for (int i = head + delta; i < tail; i++) {
				moveVal(i - delta, i);
			}
			tail = head + delta;
		}
	}
	
	inline int getAll(int x) {
		return (head + x < tail) ? knts[head + x] : 0;
	}
	
	inline void updateOne(int elt, int delta) {
		assert(0 <= elt && elt < len);
		int val = getVal(elt);
		if (delta > val) {
			return;
		}
		knts[head + val]--;
		val -= delta;
		v[elt] = head + val;
		knts[head + val]++;
	}
	
	inline int getOne(int elt, int x) {
		assert(0 <= elt && elt < len);
		return getVal(elt) == x;
	}
	
	NumBlock(const vector<int> &v, int maxKnt) :
		len(v.size()), v(v), head(0), tail(maxKnt), knts(maxKnt),
		mutate(maxKnt), mutateVal(maxKnt)
	{
		for (int i = 0; i < len; i++) {
			knts[v[i]]++;
		}
		for (int i = 0; i < maxKnt; i++) {
			mutateVal[mutate.parent(i)] = i;
		}
	}
	
	NumBlock() {
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	const int maxVal = (int)1e5;
	const int block = 444;
	
	int n, m; cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; v[i]--;
	}
	
	vector<NumBlock> blocks;
	for (int l = 0; l < n; l += block) {
		int r = min(l + block, n);
		blocks.emplace_back(vector<int>(v.begin() + l, v.begin() + r), maxVal);
	}
	
	for (int i = 0; i < m; i++) {
		int q, l, r, x; cin >> q >> l >> r >> x; l--;
		int lBlock = (l + block - 1) / block, rBlock = r / block;
		int lbb = lBlock * block, rbb = rBlock * block;
		
		if (q == 1) {
			if (lBlock > rBlock) {
				for (int j = l; j < r; j++) {
					blocks[lBlock-1].updateOne(j + block - lbb, x);
				}
			} else {
				for (int j = lBlock; j < rBlock; j++) {
					blocks[j].updateAll(x);
				}
				for (int j = l; j < lbb; j++) {
					blocks[lBlock-1].updateOne(j + block - lbb, x);
				}
				for (int j = rbb; j < r; j++) {
					blocks[rBlock].updateOne(j - rbb, x);
				}
			}
		} else if (q == 2) {
			x--;
			int ans = 0;
			if (lBlock > rBlock) {
				for (int j = l; j < r; j++) {
					ans += blocks[lBlock-1].getOne(j + block - lbb, x);
				}
			} else {
				for (int j = lBlock; j < rBlock; j++) {
					ans += blocks[j].getAll(x);
				}
				for (int j = l; j < lbb; j++) {
					ans += blocks[lBlock-1].getOne(j + block - lbb, x);
				}
				for (int j = rbb; j < r; j++) {
					ans += blocks[rBlock].getOne(j - rbb, x);
				}
			}
			cout << ans << "\n";
		} else {
			assert(false);
		}
	}
	
	return 0;
}