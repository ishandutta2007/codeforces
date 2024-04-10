// This code was written by alex256
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

class PersistentSegTree {
private:
	int curVersion;
	
	struct Item {
		int64_t value;
		int version;
		Item *l, *r;
		
		Item(int value, int curVersion)
			: value(value), version(curVersion), l(nullptr), r(nullptr) {
		}
		
		Item(const Item &parent, int curVersion)
			: Item(parent) {
			version = curVersion;
		}
	};
	typedef Item *pItem;
	
	inline pItem clone(pItem it) {
		if (!it) {
			return new Item(0, curVersion);
		} else if (it->version == curVersion) {
			return it;
		} else {
			return new Item(*it, curVersion);
		}
	}
	
	inline int64_t valueOf(pItem it) {
		return it ? it->value : 0;
	}
	
	void modify(pItem &it, int tl, int tr, int v, int delta) {
		it = clone(it);
		if (tl == tr) {
			it->value += delta;
			return;
		}
		int tm = (tl + tr) / 2;
		if (v <= tm) {
			modify(it->l, tl, tm, v, delta);
		} else {
			modify(it->r, tm+1, tr, v, delta);
		}
		it->value = valueOf(it->l) + valueOf(it->r);
	}
	
	int sum(pItem &it, int tl, int tr, int l, int r) {
		if (!it) {
			return 0;
		}
		if (l > r) {
			return 0;
		}
		if (l == tl && tr == r) {
			return it->value;
		}
		int tm = (tl + tr) / 2;
		return (
			sum(it->l, tl, tm, l, min(r, tm)) +
			sum(it->r, tm+1, tr, max(l, tm+1), r)
		);
	}
	
	int n;
	vector<pItem> versions;
public:
	inline int thisVersion() {
		return curVersion;
	}
	
	inline int newVersion() {
		versions.push_back(versions[curVersion]);
		curVersion = (int)versions.size() - 1;
		return curVersion;
	}
	
	inline void goToVersion(int versionId) {
		curVersion = versionId;
	}
	
	inline void modify(int v, int delta) {
		modify(versions[curVersion], 0, n-1, v, delta);
	}
	
	inline int sum(int l, int r) {
		return sum(versions[curVersion], 0, n-1, l, r);
	}
	
	PersistentSegTree(int n)
		: n(n), versions() {
		curVersion = 0;
		versions.push_back(new Item(0, curVersion));
	}
};

struct Query {
	int type;
	string sVal;
	int isVal, iVal;
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	map<string, int> sMeanings;
	int q; cin >> q;
	PersistentSegTree tasks(q + 42);
	PersistentSegTree priorities((int)1e9 + 42);
	
	for (int i = 0; i < q + 42; i++) {
		tasks.modify(i, -1);
	}
	
	auto tidToInt = [&](string tid) -> int {
		if (!sMeanings.count(tid)) {
			int ssz = (int)sMeanings.size();
			sMeanings[tid] = ssz;
		}
		return sMeanings[tid];
	};
	
	auto apply = [&](string s, int prior) {
		int t = tidToInt(s);
		int curVal = tasks.sum(t, t);
		if (curVal >= 0) {
			priorities.modify(curVal, -1);
		}
		if (prior >= 0) {
			priorities.modify(prior, +1);
		}
		tasks.modify(t, prior - curVal);
	};
	
	vector<int> keptAt(q+1);
	keptAt[0] = tasks.thisVersion();
	for (int i = 1; i <= q; i++) {
		priorities.newVersion();
		tasks.newVersion();
		string type; cin >> type;
		if (type == "set") {
			string tid; int p; cin >> tid >> p;
			apply(tid, p);
		} else if (type == "remove") {
			string tid; cin >> tid;
			apply(tid, -1);
		} else if (type == "query") {
			string tid; cin >> tid;
			int t = tidToInt(tid);
			int qp = tasks.sum(t, t);
			if (qp < 0) {
				cout << -1 << endl;
			} else {
				cout << priorities.sum(0, qp-1) << endl;
			}
		} else if (type == "undo") {
			int d; cin >> d;
			priorities.goToVersion(keptAt[i - d - 1]);
			tasks.goToVersion(keptAt[i - d - 1]);
		} else {
			raiseError("Wrong query type");
		}
		priorities.newVersion();
		tasks.newVersion();
		keptAt[i] = tasks.thisVersion();
	}
	return 0;
}