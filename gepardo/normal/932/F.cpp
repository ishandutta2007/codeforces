#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
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

typedef long double FType;
typedef complex<FType> Point;
#define x real
#define y imag

FType dot(Point a, Point b) {
	return (conj(a) * b).x();
}

FType f(Point a, FType x) {
	return dot(a, {x, 1});
}

const int maxN = 2e5;

class LiChaoTree {
private:
	struct Node {
		Point res;
		Node *l, *r;
		
		Node()
			: res({0, (FType)1e18}), l(nullptr), r(nullptr) {
		}
	};
	
	typedef Node *pNode;
	
	pNode root = nullptr;
	int64_t maxN;
	
	inline void addLine(Point nw, pNode &node, int64_t l, int64_t r) {
		if (node == nullptr) {
			node = new Node;
		}
		int m = l + (r - l) / 2;
		bool lef = f(nw, l) < f(node->res, l);
		bool mid = f(nw, m) < f(node->res, m);
		if (mid) {
			swap(node->res, nw);
		}
		if(r - l == 1) {
			return;
		} else if(lef != mid) {
			addLine(nw, node->l, l, m);
		} else {
			addLine(nw, node->r, m, r);
		}
	}
	
	inline FType get(FType x, pNode &node, int64_t l, int64_t r) {
		if (node == nullptr) {
			node = new Node;
		}
		int m = l + (r - l) / 2;
		if (r - l == 1) {
			return f(node->res, x);
		} else if (x < m) {
			return min(f(node->res, x), get(x, node->l, l, m));
		} else {
			return min(f(node->res, x), get(x, node->r, m, r));
		}
	}
public:
	inline void addLine(Point nw) {
		addLine(nw, root, -maxN, maxN);
	}
	
	inline FType get(FType x) {
		return get(x, root, -maxN, maxN);
	}
	
	LiChaoTree(int64_t maxN = (int64_t)1e6)
		: maxN(maxN) {
	}
};

struct Mergeable {
	LiChaoTree tree;
	vector<Point> nodes;
};
typedef Mergeable *pMerge;

inline pMerge merge(pMerge a, pMerge b) {
	if (a->nodes.size() < b->nodes.size()) {
		swap(a, b);
	}
	for (auto it: b->nodes) {
		a->nodes.push_back(it);
		a->tree.addLine(it);
	}
	delete b;
	return a;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	
	int n; cin >> n;
	vector<int64_t> a(n);
	vector<int64_t> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector< vector<int> > g(n);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int64_t> ans(n);
	
	function<pMerge(int, int)> dfs = [&](int v, int p) {
		pMerge res = new Mergeable;
		if (p >= 0 && (int)g[v].size() == 1) {
			Point pt {b[v], 0};
			res->tree.addLine(pt);
			res->nodes.push_back(pt);
			ans[v] = 0;
		} else {
			for (int to: g[v]) {
				if (to == p) {
					continue;
				}
				res = merge(res, dfs(to, v));
			}
			int64_t jmpHere = res->tree.get(a[v]);
			/*
			cout << "? " << a[v] << " " << jmpHere << " ??? " << f({5, 0}, a[v]) << endl;
			*/
			Point pt {b[v], jmpHere};
			ans[v] = pt.imag();
			res->tree.addLine(pt);
			res->nodes.push_back(pt);
		}
		/*
		cout << v << " !!!" << endl;
		for (Point it: res->nodes) {
			cout << "{" << it << "} ";
		}
		cout << endl;
		*/
		return res;
	};
	
	dfs(0, -1);
	
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}