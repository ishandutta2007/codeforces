#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 100000 + 5;
const int maxQ = 100000 + 5;
const LL maxA = 1000000000000000000; // 1e18
const LL INF = 0x3f3f3f3f3f3f3f3f;
//#define MOGAI
#ifndef MOGAI
const int POWER_COUNT = 11;
const LL powers[POWER_COUNT] = {
42LL,
1764LL,
74088LL,
3111696LL,
130691232LL,
5489031744LL,
230539333248LL,
9682651996416LL,
406671383849472LL,
17080198121677824LL,
717368321110468608LL
};
#else
const int POWER_COUNT = 6;
const LL powers[POWER_COUNT] = {
5LL, 7LL, 28LL, 44LL, 80LL,
10000000000000000LL
};
#endif
bool ispower(LL x) {
	for(int i = 0; i < POWER_COUNT; ++i) if(x == powers[i]) return true;
	return false;
}
int n, q;
LL a[maxN];

/*
4 20
38 39 40 41
3 1 4 1
1 3
*/

template<int NODE>
struct SegmentTree {
#define lson (o << 1)
#define rson (o << 1 | 1)
	int n;
	LL level;
	LL min[NODE], tag[NODE];

	void build(int o, int L, int R) {
		tag[o] = 0;
		if(L == R) min[o] = level <= a[L] ? INF : level - a[L];
		else {
			int M = (L + R) >> 1;
			build(lson, L, M);
			build(rson, M + 1, R);
			maintain(o, L, R);
		}
	}
	
	void print(int o, int L, int R, int d = 0) {
		if(d == 0) printf("==Sg. lev. = %lld==\n", level);
		printf("node[%d, %d] : min = %lld, tag = %lld\n", L, R, min[o], tag[o]);
		if(L < R) {
			int M = (L + R) >> 1;
			print(lson, L, M, d + 1);
			print(rson, M + 1, R, d + 1);
		}
		if(d == 0) printf("=======End========\n");
	}
	
	void apply(int o, int L, int R, LL tg) {
		if(tg < 0) {
			min[o] = -tg;
			tag[o] = tg;
		} else if(tag[o] < 0) {
			min[o] -= tg;
			tag[o] += tg;
			if(tag[o] == 0) again = true;
			if(tag[o] >= 0) tag[o] = -INF, min[o] = INF;
		} else {
			min[o] -= tg;
			tag[o] += tg;
		}
	}

	void pushdown(int o, int L, int R) {
		if(tag[o] && L < R) {
//			if(level == 7) printf("[%d %d] pushdown\n", L, R);
			int M = (L + R) >> 1;
			apply(lson, L, M, tag[o]); apply(rson, M + 1, R, tag[o]);
		}
		tag[o] = 0;
	}

	void maintain(int o, int L, int R) {
		if(L < R) {
			min[o] = std::min(min[lson], min[rson]);
		}
	}

	int ql, qr; LL qv;
	bool again;

	void dig(int o, int L, int R) {
//		if(level == 28) printf("dig : (%d, %d, %d) : min = %lld, tag = %lld\n", o, L, R, min[o], tag[o]);
		// if(again) return;
		if(L == R) {
			if(min[o] < 0) min[o] = INF;
			else if(min[o] == 0) again = true, min[o] = INF/*, printf("on %d feel again with level = %lld\n", L, level)*/; // modify
		} else {
			pushdown(o, L, R);
			int M = (L + R) >> 1;
			if(min[lson] <= 0) dig(lson, L, M);
			if(min[rson] <= 0) dig(rson, M + 1, R);
			maintain(o, L, R);
		}
//		if(level == 28) printf("eod : (%d, %d, %d) : min = %lld, tag = %lld\n", o, L, R, min[o], tag[o]);
	}

	void modify(int o, int L, int R) {
//		if(level == 7) printf("modify [%d, %d]\n", L, R);
		if(ql <= L && R <= qr) {
			apply(o, L, R, qv);
//			if(level == 7) printf("min = %lld tag = %lld\n", min[o], tag[o]);
			if(min[o] <= 0) dig(o, L, R);
		} else {
			pushdown(o, L, R);
			int M = (L + R) >> 1;
			if(ql <= M) modify(lson, L, M);
			if(qr > M) modify(rson, M + 1, R);
			maintain(o, L, R);
		}
	}
	
	void setv(int o, int L, int R) { // whatever
		if(ql <= L && R <= qr) {
			tag[o] = -qv; min[o] = qv;
		} else {
			pushdown(o, L, R);
			int M = (L + R) >> 1;
			if(ql <= M) setv(lson, L, M);
			if(qr > M) setv(rson, M + 1, R);
			maintain(o, L, R);
		}
	}

	int qp;
	LL query(int o, int L, int R) {
		if(L == R) {
			return level - min[o]; // the direct value
		} else {
			pushdown(o, L, R);
			int M = (L + R) >> 1;
			if(qp <= M) return query(lson, L, M);
			else return query(rson, M + 1, R);
		}
	}

#undef lson
#undef rson
};
SegmentTree<maxN*4> st[POWER_COUNT];

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < POWER_COUNT; ++i) {
		st[i].n = n; st[i].level = powers[i];
		st[i].build(1, 1, n);
	}
	for(int kase = 1; kase <= q; ++kase) {
//		st[1].print(1, 1, n);
		int t; cin >> t;
		if(t == 1) {
			cin >> st[POWER_COUNT - 1].qp;
			cout << st[POWER_COUNT - 1].query(1, 1, n) << "\n";
		} else if(t == 2) {
			int a, b; LL x; cin >> a >> b >> x;
			for(int i = 0; i < POWER_COUNT; ++i) {
				st[i].ql = a; st[i].qr = b;
				st[i].qv = x < st[i].level ? st[i].level - x : INF;
				st[i].setv(1, 1, n);
			}
		} else if(t == 3) {
			int a, b; LL x; cin >> a >> b >> x;
			bool f = false;
			do {
//				cout << "Add\n";
				f = false;
				for(int i = 0; i < POWER_COUNT; ++i) {
					st[i].ql = a; st[i].qr = b; st[i].qv = x;
					st[i].again = false;
					st[i].modify(1, 1, n);
					f = (f || st[i].again);
				}
			} while(f);
		} else {
			assert(false);
		}
	}
	return 0;
}