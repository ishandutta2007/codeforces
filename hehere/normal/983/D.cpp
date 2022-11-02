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

const int maxN = 100000 + 233;
int n;
struct Rectangle {
	int x1, x2, y1, y2;
	void read() {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 > x2) std::swap(x1, x2);
		if(y1 > y2) std::swap(y1, y2);
	}
}a[maxN];

struct Event {
	int t;
	int y, id, l, r;
	Event(int t, int y, int i, int l, int r) :
	 	t(t), y(y), id(i), l(l), r(r) {}
	friend bool operator < (const Event &A, const Event &B) {
		return A.y != B.y ? A.y < B.y :
			A.t != B.t ? A.t > B.t :
			A.t == -1 ? A.id < B.id : A.id > B.id;
	}
};
vector<Event> events;

void discretization() {
	vector<int> v;
	v.clear(); v.reserve(n*2);
	for(int i = 1; i <= n; ++i) v.push_back(a[i].x1), v.push_back(a[i].x2);
	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
	for(int i = 1; i <= n; ++i) a[i].x1 = std::lower_bound(v.begin(), v.end(), a[i].x1) - v.begin() + 1,
	                            a[i].x2 = std::lower_bound(v.begin(), v.end(), a[i].x2) - v.begin() + 1 - 1;
//	for(int i = 1; i <= n; ++i) printf("(%d, %d)\n", a[i].x1, a[i].x2);
}

void initialize() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) a[i].read();
	discretization();
	events.clear(); events.reserve(n*2);
	for(int i = 1; i <= n; ++i) {
		events.push_back(Event(1, a[i].y1, i, a[i].x1, a[i].x2));
		events.push_back(Event(-1, a[i].y2, i, a[i].x1, a[i].x2));
	}
	std::sort(events.begin(), events.end());
}

bool appeared[maxN];
bool vis[maxN];
template<int NODE>
struct SegmentTree {
#define lson (o<<1)
#define rson (o<<1|1)
	priority_queue<int> pq[NODE];
	int min[NODE];
	int max[NODE];
	void init(int n) {
		for(int o = 0; o <= 4*n; ++o) {
			while(!pq[o].empty()) pq[o].pop();
			pq[o].push(0);
			min[o] = 0;
			max[o] = 0;
		}
	}

	void maintain(int o, int L, int R) {
		min[o] = pq[o].top();
		while(vis[pq[o].top()]) pq[o].pop();
		max[o] = appeared[pq[o].top()] ? 0 : pq[o].top();
		if(L < R) {
			chmax(min[o], std::min(min[lson], min[rson]));
			if(pq[o].top() >= std::min(min[lson], min[rson])) {
				chmax(max[o], std::max(max[lson] > pq[o].top() ? max[lson] : 0, 
										max[rson] > pq[o].top() ? max[rson] : 0));
			} else {
				max[o] = std::max(max[lson], max[rson]);
			}
		}
	}
	
	void print(int o, int L, int R) {
		printf("#%d : [%d, %d] v = %d with {%d, %d}\n", o, L, R, pq[o].top(), min[o], max[o]);
		if(L < R) {
			int M = (L + R) >> 1;
			print(lson, L, M);
			print(rson, M + 1, R);
		}
	}
	
	int ql, qr, qv;

	void seek(int o, int L, int R) {
		if(pq[o].top() != qv) {
#ifdef DEBUG
			assert(L < R);
#endif
			int M = (L + R) >> 1;
			if(max[lson] == qv) seek(lson, L, M);
			if(max[rson] == qv) seek(rson, M + 1, R);
		}
		maintain(o, L, R);
	}

	void solve(int o, int L, int R) {
		while(max[o]) {
//			printf("Append %d to answer.\n", max[o]);
			appeared[max[o]] = true;
			qv = max[o];
			seek(o, L, R);
		}
	}


	void push(int o, int L, int R) {
		if(ql <= L && R <= qr) {
			pq[o].push(qv);
		} else {
			int M = (L + R) >> 1;
			if(ql <= M) push(lson, L, M);
			if(qr > M) push(rson, M + 1, R);
		}
		maintain(o, L, R);
	}

	void pop(int o, int L, int R) {
		if(ql <= L && R <= qr) {
			while(vis[pq[o].top()]) pq[o].pop();
		} else {
			int M = (L + R) >> 1;
			if(ql <= M) pop(lson, L, M);
			if(qr > M) pop(rson, M + 1, R);
		}
		maintain(o, L, R);
	}

#undef lson
#undef rson
};
SegmentTree<maxN*8> st;

int solve() {
	st.init(n*2);
	int lasty = -maxN;
	vis[0] = appeared[0] = false;
	for(const Event &e : events) {
//		printf("Event : t = %d, y = %d, id = %d, interval = [%d, %d]\n", e.t, e.y, e.id, e.l, e.r);
		if(e.y != lasty) {
//			st.print(1, 1, n*2);
			st.solve(1, 1, n*2);
			lasty = e.y;
		}
		if(e.t == -1) {
			st.ql = e.l; st.qr = e.r; st.qv = e.id;
			vis[e.id] = true;
			st.pop(1, 1, n*2);
		} else if(e.t == 1) {
			st.ql = e.l; st.qr = e.r; st.qv = e.id;
			appeared[e.id] = vis[e.id] = false;
			st.push(1, 1, n*2);
		} else {
			assert(false);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i) if(appeared[i]) ++cnt;
	return cnt + 1;
}

/*
3
2 2 3 5
1 1 4 3
1 4 4 6
*/

int main() {
	initialize();
	printf("%d\n", solve());
	return 0;
}