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
	//#define LOCAL_INPUT_FILE
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

struct Edge {
	int a, b, c;
};

struct Treap {
	int x, y;
	int data;
	int mx;
	int size;
	Treap *l, *r;
	
	Treap(int x, int data)
		: x(x), y(randGen()), data(data), mx(data), size(1), l(nullptr), r(nullptr) {
	}
	
	~Treap() {
		if (l != nullptr) {
			delete l;
		}
		if (r != nullptr) {
			delete r;
		}
	}
};
typedef Treap *pTreap;

inline int getSize(pTreap t) {
	return (t != nullptr) ? t->size : 0;
}

inline int getMax(pTreap t) {
	return (t != nullptr) ? t->mx : 0;
}

inline void update(pTreap t) {
	if (t != nullptr) {
		t->size = getSize(t->l) + 1 + getSize(t->r);
		t->mx = max(t->data, max(getMax(t->l), getMax(t->r)));
	}
}

void split(pTreap t, pTreap &l, pTreap &r, int x) {
	if (t == nullptr) {
		l = r = nullptr;
	} else if (x <= t->x) {
		split(t->l, l, t->l, x);
		r = t;
	} else {
		split(t->r, t->r, r, x);
		l = t;
	}
	update(l); update(r);
}

void splitSize(pTreap t, pTreap &l, pTreap &r, int count) {
	if (t == nullptr) {
		l = r = nullptr;
	} else if (count <= getSize(t->l)) {
		splitSize(t->l, l, t->l, count);
		r = t;
	} else {
		splitSize(t->r, t->r, r, count - getSize(t->l) - 1);
		l = t;
	}
	update(l); update(r);
}

void merge(pTreap &t, pTreap l, pTreap r) {
	if (l == nullptr || r == nullptr) {
		t = (l != nullptr) ? l : r;
	} else if (l->y > r->y) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	update(t);
}

void insert(pTreap &t, pTreap it) {
	if (t == nullptr) {
		t = it;
	} else if (it->y > t->y) {
		split(t, it->l, it->r, it->x);
		t = it;
	} else if (it->x <= t->x) {
		insert(t->l, it);
	} else {
		insert(t->r, it);
	}
	update(t);
}

void erase(pTreap &t, int x) {
	if (t != nullptr) {
		if (x == t->x) {
			pTreap oldT = t;
			merge(t, t->l, t->r);
			oldT->l = oldT->r = nullptr;
			delete oldT;
		} else if (x < t->x) {
			erase(t->l, x);
		} else {
			erase(t->r, x);
		}
	}
	update(t);
}

void unite(pTreap &t, pTreap l, pTreap r) {
	if (l == nullptr || r == nullptr) {
		t = (l != nullptr) ? l : r;
	} else {
		if (r->y > l->y) {
			swap(l, r);
		}
		pTreap rl, rr;
		split(r, rl, rr, l->x);
		unite(l->l, l->l, rl);
		unite(l->r, l->r, rr);
		t = l;
	}
	update(t);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector<Edge> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i].a >> v[i].b >> v[i].c;
		v[i].a--; v[i].b--;
	}
	vector<pTreap> dp(n);
	int best = 0;
	for (int i = 0; i < m; i++) {
		pTreap &t = dp[v[i].a];
		pTreap l, r; split(t, l, r, v[i].c);
		int kur = getMax(l) + 1;
		best = max(best, kur);
		merge(t, l, r);
		insert(dp[v[i].b], new Treap(v[i].c, kur));
	}
	cout << best << endl;
	return 0;
}