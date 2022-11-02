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
#include <bitset>
using std::bitset;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

bool chmax(int &a, int b) { return a < b ? a = b, true : false; }

const int maxN = 5000 + 5;
const int maxW = 1000 + 5;
const int maxQ = 30000 + 5;
const int BSIZE = maxN + 10000;
//const int BSIZE = 10;
int n, k, q, id;
int v[BSIZE], w[BSIZE];
int cnt[maxQ], ans[maxQ], sid;
bitset<BSIZE> status[maxQ];
bitset<BSIZE> now;

int getHash(const vector<int> &f) {
	static const LL P = 10000000 + 19;
	static const LL Q = 1000000000 + 7;
	LL pp = 1, ans = 0;
	int maxv = 0;
	for(int i = 1; i <= k; ++i) {
		chmax(maxv, f[i]);
		ans = (ans + maxv * pp) % Q;
		pp = pp * P % Q;
	}
	return (int)ans;
}

int overall_id;
const bitset<BSIZE> &build(int L, int R) {
	int M = (L + R) >> 1;
	int myid = L == R ? L : ++overall_id;
	if(L == R) {
//		cout << "on " << L << ", bitset = " << status[myid] << endl;
		return status[myid];
	} else {
		const bitset<BSIZE> &bl = build(L, M);
		const bitset<BSIZE> &br = build(M + 1, R);
		status[myid] = bl & br;
//		cout << "on [" << L << ", " << R << "], bitset = " << status[myid] << endl;
		return status[myid];
	}
}

vector<int> buc[20];
void solve(int L, int R, int d, const vector<int> &g, const bitset<BSIZE> &T) {
	vector<int> &f = buc[d];
	int myid = L == R ? L : ++overall_id;
	const bitset<BSIZE> &S = status[myid];
	f = g;
#ifdef DEBUG
	assert((S & T) == T);
#endif
	bitset<BSIZE> F = S & ~T;
//	printf("Knapsack :\n");
//	for(int i = 0; i <= k; ++i) printf("%d ", f[i]); printf("\n");
	for(int i = 0; i <= id; ++i) if(F[i]) {
//		printf("add item %d, with v = %d, w = %d\n", i, v[i], w[i]);
		for(int j = k - w[i]; j >= 0; --j) chmax(f[j + w[i]], f[j] + v[i]);
	}
//	for(int i = 0; i <= k; ++i) printf("%d ", f[i]); printf("\n");
	ans[myid] = getHash(f);
	if(L < R) {
		int M = (L + R) >> 1;
		solve(L, M, d + 1, f, status[myid]);
		solve(M + 1, R, d + 1, f, status[myid]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> v[i] >> w[i], now[i] = true;
	id = n;
	cin >> q;
	sid = 1;
	for(int i = 1; i <= q; ++i) {
		int op; cin >> op;
		if(op == 1) {
			++id;
			cin >> v[id] >> w[id];
			now[id] = true;
			if(cnt[sid]) ++sid;
		} else if(op == 2) {
			int x; cin >> x;
			now[x] = false;
			if(cnt[sid]) ++sid;
		} else if(op == 3) {
			if(!cnt[sid]) {
				status[sid] = now;
				cnt[sid] = 1;
			} else {
				++cnt[sid];
			}
		} else {
			assert(false);
		}
	}
	if(!cnt[sid]) --sid;
	overall_id = sid;
	build(1, sid);
	overall_id = sid;
	for(int i = 0; i < 20; ++i) buc[i].clear(), buc[i].resize(k + 1);
	now &= 0;
	solve(1, sid, 1, buc[0], now);
	for(int i = 1; i <= sid; ++i) {
		for(int j = 0; j < cnt[i]; ++j) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}