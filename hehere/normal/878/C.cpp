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

inline int readint() {
	int a = 0, po = 1; char c = getchar();
	while(isspace(c)) c = getchar();
	if(c == '-') po = -1, c = getchar();
	while(isdigit(c)) a = a*10 + c - '0', c = getchar();
	return a * po;
}

bool chmin(int &a, int b) { return a > b ? a = b, true : false; }
bool chmax(int &a, int b) { return a < b ? a = b, true : false; }

const int maxN = 50000 + 233;
const int maxK = 10;
const int INF = 0x3f3f3f3f;
int n, k;
int a[maxN][maxK];

int ql, qr, qp, qv;
int standard[maxK];
int smin[maxK], smax[maxK];

template<int NODE>
struct ValueSegmentTree {

#define lson (o << 1)
#define rson (o << 1 | 1)

	void init() {
		for(int o = 0; o <= n*4; ++o) {
			for(int j = 0; j < k; ++j) max[o][j] = ~INF, min[o][j] = INF;
			sum[o] = 0;
		}
	}

	int max[NODE][maxK], min[NODE][maxK], sum[NODE];
	void maintain(int o, int L, int R) {
		if(L < R) {
			for(int i = 0; i < k; ++i) {
				min[o][i] = std::min(min[lson][i], min[rson][i]);
				max[o][i] = std::max(max[lson][i], max[rson][i]);
			}
			sum[o] = sum[lson] + sum[rson];
		}
	}

	int leftmost(int o, int L, int R) { // standard[] required
		if(L == R) return L;
		bool f = false;
		for(int i = 0; i < k; ++i) f = (f || max[lson][i] > standard[i]);
		int M = (L + R) >> 1;
		if(f) return leftmost(lson, L, M);
		else return leftmost(rson, M + 1, R);
	}

	int rightmost(int o, int L, int R) { // standard[] required
		if(L == R) return R;
		bool f = false;
		for(int i = 0; i < k; ++i) f = (f || min[rson][i] < standard[i]);
		int M = (L + R) >> 1;
		if(f) return rightmost(rson, M + 1, R);
		else return rightmost(lson, L, M);
	}

	int remove(int o, int L, int R) { // ql, qr, sim[], smax[] required
		int ret = 0;
		if(L == R) {
			if(!sum[o]) ret = sum[o];
			ret = sum[o]; sum[o] -= ret;
			for(int i = 0; i < k; ++i) chmin(smin[i], min[o][i]), chmax(smax[i], max[o][i]);
			for(int i = 0; i < k; ++i) min[o][i] = INF, max[o][i] = ~INF;
		} else {
			int M = (L + R) >> 1;
			if(ql <= M && sum[lson]) ret += remove(lson, L, M);
			if(qr > M && sum[rson]) ret += remove(rson, M + 1, R);
			maintain(o, L, R);
		}
		return ret;
	}

	void insert(int o, int L, int R) { // qp, qv, smax[], smin[] required
		if(L == R) {
			for(int i = 0; i < k; ++i) min[o][i] = smin[i], max[o][i] = smax[i];
			sum[o] = qv;
		} else {
			int M = (L + R) >> 1;
			if(qp <= M) insert(lson, L, M);
			else insert(rson, M + 1, R);
			maintain(o, L, R);
		}
	}

#undef lson
#undef rson

};

ValueSegmentTree<maxN*4> st;

/*
3 2
1 2
2 1
3 3
*/

void initialize() {
	n = readint(); k = readint();
	for(int i = 1; i <= n; ++i) for(int j = 0; j < k; ++j) a[i][j] = readint();
	vector<int> v; v.reserve(n);
	for(int j = 0; j < k; ++j) {
		v.clear();
		for(int i = 1; i <= n; ++i) v.push_back(a[i][j]);
		std::sort(v.begin(), v.end());
		for(int i = 1; i <= n; ++i)
			a[i][j] = std::lower_bound(v.begin(), v.end(), a[i][j]) - v.begin() + 1;
	}
}

void solve() {
	st.init();
	int pos = -1, cnt = 0;
	for(int i = 1; i <= n; ++i) {
		int leftmost = maxN, rightmost = -1;
		bool left = false, right = false;
		for(int j = 0; j < k; ++j) smin[j] = smax[j] = standard[j] = a[i][j];
		for(int j = 0; j < k; ++j) left = (left || st.max[1][j] > standard[j]);
		for(int j = 0; j < k; ++j) right = (right || st.min[1][j] < standard[j]);
//		for(int j = 0; j < k; ++j) printf("%d ", st.max[1][j]); printf("\n");
//		for(int j = 0; j < k; ++j) printf("%d ", st.min[1][j]); printf("\n");
		if(left) leftmost = st.leftmost(1, 1, n);
		if(right) rightmost = st.rightmost(1, 1, n);
		int sum = 1;
		if(leftmost <= rightmost)
			{ ql = leftmost; qr = rightmost; sum += st.remove(1, 1, n); }
		qp = standard[0]; qv = sum;
		st.insert(1, 1, n);
		if((right && rightmost == pos) || qp > pos) { pos = qp; cnt = sum; }
//		printf("leftmost = %d, rightmost = %d, sum = %d\n", leftmost, rightmost, sum);
		printf("%d\n", cnt);
	}
}

int main() {
	initialize();
	solve();
	return 0;
}