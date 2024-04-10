// Code written by gepardo
#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
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

#ifdef DEBUG
class API {
private:
	int n, m;
	vector< pair<int, int> > vvv;
public:
	API() {
		cin >> n >> m;
		for (int i = 0; i < m; ++i) {
			int a, b; cin >> a >> b; a--; b--;
			vvv.emplace_back(a, b);
		}
	}
	
	int init() {
		cout << "init " << n << endl;
		return n;
	}
	
	int query(vector<int> v) {
		if (v.size() <= 1) {
			return 0;
		}
		cout << "? " << v.size() << "\n";
		for (int i : v) {
			cout << i+1 << " ";
		}
		cout << endl;
		set<int> st(v.begin(), v.end());
		int res = 0;
		for (auto it : vvv) {
			if (st.count(it.first) && st.count(it.second)) {
				res++;
			}
		}
		cout << " > " << res << endl;
		return res;
	}
	
	void found(vector<int> split) {
		vector<int> d1;
		for (int i = 0; i < (int)split.size(); ++i) {
			if (split[i]) {
				d1.push_back(i);
			}
		}
		cout << "Y " << d1.size() << endl;
		for (int i : d1) {
			cout << i+1 << " ";
		}
		cout << endl;
		exit(0);
	}
	
	void notFound(vector<int> loop) {
		cout << "N " << loop.size() << endl;
		for (int i : loop) {
			cout << i+1 << " ";
		}
		cout << endl;
		exit(0);
	}
};
#else
class API {
public:
	int init() {
		int n; cin >> n; return n;
	}
	
	int query(vector<int> v) {
		if (v.empty()) {
			return 0;
		}
		cout << "? " << v.size() << "\n";
		for (int i : v) {
			cout << i+1 << " ";
		}
		cout << endl;
		int res; cin >> res;
		if (res == -1) {
			for (;;);
		}
		return res;
	}
	
	void found(vector<int> split) {
		vector<int> d1;
		for (int i = 0; i < (int)split.size(); ++i) {
			if (split[i]) {
				d1.push_back(i);
			}
		}
		cout << "Y " << d1.size() << endl;
		for (int i : d1) {
			cout << i+1 << " ";
		}
		cout << endl;
		exit(0);
	}
	
	void notFound(vector<int> loop) {
		cout << "N " << loop.size() << endl;
		for (int i : loop) {
			cout << i+1 << " ";
		}
		cout << endl;
		exit(0);
	}
};
#endif

API api;

inline vector<int> glue(vector<int> a, vector<int> b) {
	a.insert(a.end(), b.begin(), b.end());
	return a;
}

inline vector<int> chunk(vector<int> a, int sz) {
	return vector<int>(begin(a), begin(a) + sz);
}

vector<int> bfs(const vector< vector<int> > &g, int src, int dst) {
	int n = g.size();
	vector<int> d(n, -1);
	vector<int> p(n, -1);
	queue<int> q;
	d[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int to: g[v]) {
			if (d[to] < 0) {
				d[to] = d[v] + 1;
				p[to] = v;
				q.push(to);
			}
		}
	}
	assert(d[dst] >= 0);
	vector<int> res;
	while (dst != src) {
		res.push_back(dst);
		dst = p[dst];
	}
	res.push_back(src);
	return res;
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n = api.init();
	vector<int> colors(n, -1);
	vector<int> p1, p2;
	p1.push_back(0);
	colors[0] = 0;
	vector<int> rem(n-1);
	vector< vector<int> > tree(n);
	iota(rem.begin(), rem.end(), 1);
	
	auto done = [&](int v, int adj) {
		rem.erase(find(rem.begin(), rem.end(), v));
		tree[v].push_back(adj);
		tree[adj].push_back(v);
	};
	
	auto findEdge = [&](vector<int> st, int ver) {
		vector<int> vv; vv.push_back(ver);
		if (api.query(glue(st, vv)) == 0) {
			return -1;
		}
		int l = 0, r = st.size();
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (api.query(glue(chunk(st, m), vv)) == 0) {
				l = m;
			} else {
				r = m-1;
			}
		}
		return st[l];
	};
	
	auto connect = [&](vector<int> &st, vector<int> &rst, int color, bool check) {
		//cout << "\033[41mtry? " << rem.size() << "\033[0m" << endl;
		if (check && api.query(glue(st, rem)) == api.query(rem)) {
			return -1;
		}
		int l = 0, r = rem.size();
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (api.query(glue(st, chunk(rem, m))) == api.query(chunk(rem, m))) {
				l = m;
			} else {
				r = m-1;
			}
		}
		int chosen = rem[l];
		int e1 = findEdge(st, chosen); assert(e1 >= 0);
		int e2 = findEdge(rst, chosen);
		if (e2 >= 0) {
			vector<int> loop = bfs(tree, e1, e2);
			loop.push_back(chosen);
			api.notFound(loop);
		}
		colors[chosen] = !color;
		rst.push_back(chosen);
		done(chosen, e1);
		return chosen;
	};
	
	for (int i = 1; i < n; ++i) {
		//cout << "\033[42mi= " << i << "\033[0m" << endl;
		if (connect(p1, p2, 0, true) < 0) {
			connect(p2, p1, 1, false);
		}
	}
	
	api.found(colors);
	return 0;
}