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

bool chmin(int &a, const int &b) { return a > b ? a = b, true : false; }
bool chmax(int &a, const int &b) { return a < b ? a = b, true : false; }

const int maxN = 4000 + 5;
const int maxT = 20000 + 5;
const int maxQ = 20000 + 5;
const int maxC = 4000 + 5;
int n, p, q;
int c[maxN], h[maxN];
// bool busy[maxQ];
int tin[maxN], tout[maxN];

vector<pii> qs[maxQ];
int ans[maxQ];

template<int NODE>
struct SegmentTree {

#define lson (o << 1)
#define rson (o << 1 | 1)

	vector<int> ele[NODE];
	vector<int> buc[20];
	int max[NODE];

	void init(int n) {
		for(int i = 0; i <= n*4; ++i) ele[i].clear(), max[i] = 0;
		for(int i = 0; i < 20; ++i) {
			buc[i].clear(); buc[i].resize(maxC);
		}
	}

	int ql, qr, qv;
	void cover(int o, int L, int R) {
		if(ql <= L && R <= qr) ele[o].push_back(qv);
		else {
			int M = (L + R) >> 1;
			if(ql <= M) cover(lson, L, M);
			if(qr > M) cover(rson, M + 1, R);
		}
	}

	void iterate(int o, int L, int R) {
		max[o] = 0;
//		for(int i : ele[o]) printf("[%d, %d] found %d\n", L, R, i);
		if(L == R) {
			for(pii p : qs[L]) chmax(max[o], p.second);
		} else {
			int M = (L + R) >> 1;
			iterate(lson, L, M);
			iterate(rson, M + 1, R);
			chmax(max[o], max[lson]);
			chmax(max[o], max[rson]);
		}
	}

	void solve(int o, int L, int R, int d, vector<int> &g) {
		if(!max[o]) return;
		vector<int> &f = ele[o].size() ? buc[d] : g;
		if(ele[o].size()) for(int i = 0; i <= max[o]; ++i) f[i] = g[i];
		for(int i : ele[o]) {
			for(int j = max[o] - c[i]; j >= 0; --j)
				chmax(f[j + c[i]], f[j] + h[i]);
		}

		if(L == R) {
//			printf("L = R = %d\n", L);
//			for(int i = 0; i < 10; ++i) printf("%d ", f[i]); printf("\n");
			for(int i = 1; i <= max[o]; ++i) chmax(f[i], f[i - 1]);
			// It won't matter if this modification affects other DP-arrays
			for(pii p : qs[L]) ans[p.first] = f[p.second];
		} else {
			int M = (L + R) >> 1;
			if(max[lson]) solve(lson, L, M, d + 1, f);
			if(max[rson]) solve(rson, M + 1, R, d + 1, f);
		}
	}

#undef lson
#undef rson

};
SegmentTree<maxQ * 4> st;


// int map[maxQ];
// int pre[maxQ], post[maxQ];
void initialize() {
	std::ios::sync_with_stdio(false);
	cin >> n >> p;
	st.init(20000);
	for(int i = 1; i <= n; ++i) {
		cin >> c[i] >> h[i] >> tin[i];
		tout[i] = tin[i] + p - 1;
		st.ql = tin[i]; st.qr = tout[i]; st.qv = i;
		st.cover(1, 1, 20000);
	}
	
	/*
	int t = 0;
	for(int i = 1; i < maxQ; ++i) {
		if(!busy[i]) continue;
		map[i] = ++t;
	}
	pre[0] = 0; post[maxQ - 1] = 0;
	for(int i = 1; i < maxQ; ++i) pre[i] = busy[i] ? i : pre[i - 1];
	for(int i = maxQ - 2; i >= 1; --i) post[i] = busy[i] ? i : post[i + 1];
	for(int i = 1; i <= n; ++i) tin[i] = map[tin[i]], tout[i] = map[tout[i]];*/
	
	cin >> q;
	for(int i = 1; i <= q; ++i) {
		int a, b; cin >> a >> b;
		qs[a].push_back(pii(i, b));
	}
	st.iterate(1, 1, 20000);
	st.solve(1, 1, 20000, 1, st.buc[0]);
}

int main() {
	initialize();
	for(int i = 1; i <= q; ++i) cout << ans[i] << "\n";
	return 0;
}