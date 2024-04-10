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

struct Treap {
	int x, y;
	int size;
	int64_t sum;
	Treap *l, *r;
	
	Treap(int x)
		: x(x), y(randGen()), size(1), sum(x), l(nullptr), r(nullptr) {
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
typedef Treap* pTreap;

inline int getSize(pTreap t) {
	return (t != nullptr) ? t->size : 0;
}

inline int64_t getSum(pTreap t) {
	return (t != nullptr) ? t->sum : 0;
}

inline void update(pTreap t) {
	if (t != nullptr) {
		t->size = getSize(t->l) + 1 + getSize(t->r);
		t->sum = getSum(t->l) + t->x + getSum(t->r);
	}
}

inline void split(pTreap t, pTreap& l, pTreap& r, int x) {
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

inline void splitSize(pTreap t, pTreap& l, pTreap& r, int count) {
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

void merge(pTreap& t, pTreap l, pTreap r) {
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

inline void insert(pTreap& t, pTreap it) {
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

inline void erase(pTreap& t, int x) {
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

inline void unite(pTreap& t, pTreap l, pTreap r) {
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

void outItem(pTreap t) {
	cout << t->x << " ";
}

void out(pTreap t) {
	if (t != nullptr) {
		out(t->l);
		outItem(t);
		out(t->r);
	}
}

pTreap nthElement(pTreap t, int n) {
	if (t == nullptr) {
		return nullptr;
	} else if (n == getSize(t->l)) {
		return t;
	} else if (n < getSize(t->l)) {
		return nthElement(t->l, n);
	} else {
		return nthElement(t->r, n - getSize(t->l) - 1);
	}
}

pTreap find(pTreap t, int x) {
	if (t == nullptr) {
		return nullptr;
	} else if (x == t->x) {
		return t;
	} else if (x < t->x) {
		return find(t->l, x);
	} else {
		return find(t->r, x);
	}
}

#define int int64_t

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector<int> l(n);
	for (int i = 1; i < n; i++) {
		cin >> l[i];
	}
	vector< pair<int, int> > q(m);
	for (int i = 0; i < m; i++) {
		cin >> q[i].first >> q[i].second;
		q[i].first--;
	}
	
	vector< vector< pair<int, int> > > sumByLen(n);
	for (int i = 0; i < m; i++) {
		int v = q[i].first;
		int rng = q[i].second;
		int len = 0;
		sumByLen[v].emplace_back(rng, -1);
		while (v != 0) {
			int p = (v - 1) / 2;
			len += l[v];
			int pL = p*2 + 1, pR = p*2 + 2;
			int q = -1;
			if (pL < n && pL != v) {
				q = pL;
			} else if (pR < n && pR != v) {
				q = pR;
			}
			if (q >= 0) {
				sumByLen[q].emplace_back(rng - len - l[q], -1);
			}
			v = p;
		}
	}
	for (int i = 0; i < n; i++) {
		sort(sumByLen[i].begin(), sumByLen[i].end());
	}
	
	function<pTreap(int, int)> dfs = [&](int v, int fUp) {
		pTreap p = new Treap(fUp);
		for (int i = 1; i <= 2; i++) {
			if (v*2 + i < n) {
				pTreap add = dfs(v*2 + i, fUp + l[v*2 + i]);
				unite(p, p, add);
			}
		}
		
		vector<pTreap> pieces;
		pieces.reserve(sumByLen[v].size());
		
		int64_t cumSize = 0, cumSum = 0;
		for (auto &it : sumByLen[v]) {
			int val = it.first + fUp;
			int &res = it.second;
			pieces.push_back(nullptr);
			split(p, pieces.back(), p, val);
			cumSize += getSize(pieces.back());
			cumSum += getSum(pieces.back());
			res = (int64_t)val * cumSize - cumSum;
		}
		
		pTreap q = nullptr;
		for (auto it : pieces) {
			merge(q, q, it);
		}
		merge(q, q, p);
		return q;
	};
	dfs(0, 0);
	
	vector<int64_t> answers(m);
	for (int i = 0; i < m; i++) {
		int v = q[i].first;
		int rng = q[i].second;
		int len = 0;
		answers[i] += lower_bound(sumByLen[v].begin(), sumByLen[v].end(), make_pair(rng, (int)-1))->second;
		while (v != 0) {
			int p = (v - 1) / 2;
			len += l[v];
			if (rng >= len) {
				answers[i] += rng - len;
			}
			int pL = p*2 + 1, pR = p*2 + 2;
			int q = -1;
			if (pL < n && pL != v) {
				q = pL;
			} else if (pR < n && pR != v) {
				q = pR;
			}
			if (q >= 0) {
				answers[i] += lower_bound(sumByLen[q].begin(), sumByLen[q].end(), make_pair(rng - len - l[q], (int)-1))->second;
			}
			v = p;
		}
		cout << answers[i] << endl;
	}
	
	return 0;
}