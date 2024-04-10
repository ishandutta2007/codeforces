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

enum Oper {NOT, AND, OR, XOR, IN};

struct Vertex {
	Oper op;
	vector<int> to;
	bool val;
	bool v0[2];
};

inline int nextInt() {
	int n; cin >> n; return n;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<Vertex> tree(n);
	for (int i = 0; i < n; i++) {
		string type; cin >> type;
		tree[i].to.reserve(2);
		if (type == "IN") {
			tree[i].op = IN;
			cin >> tree[i].val;
		} else if (type == "NOT") {
			tree[i].op = NOT;
			tree[i].to.push_back(nextInt() - 1);
		} else if (type == "AND") {
			tree[i].op = AND;
			tree[i].to.push_back(nextInt() - 1);
			tree[i].to.push_back(nextInt() - 1);
		} else if (type == "OR") {
			tree[i].op = OR;
			tree[i].to.push_back(nextInt() - 1);
			tree[i].to.push_back(nextInt() - 1);
		} else if (type == "XOR") {
			tree[i].op = XOR;
			tree[i].to.push_back(nextInt() - 1);
			tree[i].to.push_back(nextInt() - 1);
		} else {
			assert(false);
		}
	}
	
	auto eval = [&](int v) -> bool {
		switch (tree[v].op) {
			case IN: {
				return tree[v].val;
			} break;
			case NOT: {
				return !tree[tree[v].to[0]].val;
			} break;
			case AND : {
				return tree[tree[v].to[0]].val & tree[tree[v].to[1]].val;
			} break;
			case OR : {
				return tree[tree[v].to[0]].val | tree[tree[v].to[1]].val;
			} break;
			case XOR : {
				return tree[tree[v].to[0]].val ^ tree[tree[v].to[1]].val;
			} break;
			default: {
				assert(false);
			}
		}
	};
	
	function<void(int)> dfs1 = [&](int v) {
		for (int to: tree[v].to) {
			dfs1(to);
		}
		tree[v].val = eval(v);
	};
	
	function<void(int, int)> dfs2 = [&](int v, int p) {
		if (p < 0) {
			tree[v].v0[0] = 0;
			tree[v].v0[1] = 1;
		} else {
			bool wasVal = tree[v].val;
			for (int newVal = 0; newVal < 2; newVal++) {
				tree[v].val = newVal;
				tree[v].v0[newVal] = tree[p].v0[eval(p)];
			}
			tree[v].val = wasVal;
		}
		for (int to: tree[v].to) {
			dfs2(to, v);
		}
	};
	
	dfs1(0);
	dfs2(0, -1);
	
	for (int i = 0; i < n; i++) {
		if (tree[i].op == IN) {
			cout << tree[i].v0[!tree[i].val];
		}
	}
	cout << endl;
	
	return 0;
}