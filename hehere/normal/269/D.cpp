#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort;
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

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline bool chmin(int &a, int b) { return a > b ? a = b, true : false; }
inline bool chmax(int &a, int b) { return a < b ? a = b, true : false; }

const int maxN = 100000 + 233;
const int INF = 0x7fffffff;
int n, top;
struct Plane {
	int h, l, r;
}p[maxN];
int get_overlap(const Plane &A, const Plane &B) {
	return min(A.r, B.r) - max(A.l, B.l);
}
struct Event {
	int time, type, height, id;
	Event() {}
	Event(int tm, int ty, int h, int i) :
		time(tm), type(ty), height(h), id(i) {}
	friend bool operator < (const Event &a, const Event &b) {
		if(a.time != b.time) return a.time < b.time;
		if(a.type != b.type) return a.type < b.type;
		return a.height < b.height;
	}
};
vector<Event> events;

void init() {
	scanf("%d%d", &n, &top);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d%d", &p[i].h, &p[i].l, &p[i].r);
	vector<int> rx(n+2);
	for(int i = 0; i < n; ++i) rx[i] = p[i+1].h;
	rx[n] = 0; rx[n+1] = top;
	std::sort(rx.begin(), rx.end());
	vector<int>::iterator pos = std::unique(rx.begin(), rx.end());
	for(int i = 1; i <= n; ++i) p[i].h = std::lower_bound(rx.begin(), pos, p[i].h) - rx.begin();
	top = std::lower_bound(rx.begin(), pos, top) - rx.begin();
//	printf("top = %d\n", top);
//	for(int i = 1; i <= n; ++i)
//		printf("%d %d %d\n", p[i].h, p[i].l, p[i].r);
}

struct FenwickTree {
	int n, C[maxN];
	void init(int n) {
		++n;
		this->n = n;
		for(int i = 0; i <= n; ++i) C[i] = 0;
	}
	void add(int p, int x) {
		++p;
		for(int i = p; i <= n; i += (i & -i)) C[i] += x;
	}
	int sum(int p) {
		++p;
		int ret = 0;
		for(int i = p; i > 0; i -= (i & -i)) ret += C[i];
		return ret;
	}
}fwt;

int find_pre(int x) {
	int L = 0, R = x - 1;
	int sx = fwt.sum(x);
	while(L < R) {
		int M = (L + R) >> 1;
		int sm = fwt.sum(M);
		if(sm >= sx-1) R = M;
		else L = M + 1;
	}
	return L;
}

int find_post(int x) {
	int L = x + 1, R = top;
	int sx = fwt.sum(x);
	while(L < R) {
		int M = (L + R) >> 1;
		int sm = fwt.sum(M);
//		printf("find_post : sx = %d, [%d, %d] -> f(%d) = %d\n", sx, L, R, M, sm);
		if(sm >= sx + 1) R = M;
		else L = M + 1;
	}
	return L;
}
vector<int> G[maxN];
int f[maxN];
int dfs(int u) {
	int &ans = f[u];
	if(ans >= 0) return ans;
	for(int v : G[u]) {
		chmax(ans, min(dfs(v), get_overlap(p[u], p[v])));
	}
	return ans;
}

int id[maxN];
int up[maxN], down[maxN];
bool us[maxN], ds[maxN]; // judge if it is strong / weak

void add_edge(int u, int v) {
//	printf("Edge add %d->%d\n", u, v);
	G[u].push_back(v);
}

int solve() {
	for(int i = 1; i <= n; ++i) {
		Plane &a = p[i];
		events.push_back(Event(a.l, 1, a.h, i)); // insert
		events.push_back(Event(a.r, -1, a.h, i)); // delete
	}
	std::sort(events.begin(), events.end());
	memset(id, -1, sizeof(id));
	memset(up, -1, sizeof(up));
	memset(down, -1, sizeof(down));
	memset(us, 0, sizeof(us));
	memset(ds, 0, sizeof(ds));
	fwt.init(top);
	fwt.add(0, 1); fwt.add(top, 1);
	id[0] = 0; id[top] = n + 1;
	p[0] = Plane{0, (int)-1e9, (int)+1e9};
	p[n + 1] = Plane{top, (int)-1e9, (int)+1e9};
	up[0] = top; down[top] = 0;
	us[0] = false; ds[top] = false;
	for(Event &e : events) {
		int now = e.height;
		if(e.type == 1) fwt.add(now, 1);
		int low = find_pre(now), high = find_post(now);
		if(e.type == -1) fwt.add(now, -1);
//		printf("%s now = %d, high = %d, low = %d\n", e.type > 0 ? "Insert" : "Erase", now, high, low);
//		for(int i = 0; i <= top; ++i) printf("%d ", fwt.sum(i)); printf("\n");
		if(e.type == 1) {
//			printf("%d %d\n", up[low], down[high]);
//			assert(up[low] == high); assert(down[high] == low);
			up[low] = now; down[now] = low;
			up[now] = high; down[high] = now;
			us[low] = true; ds[now] = true;
			us[now] = true; ds[high] = true;
			id[now] = e.id;
		} else if(e.type == -1) {
//			printf("%d %d\n", up[low], down[high]);
//			assert(up[low] == now); assert(down[now] == low);
//			assert(up[now] == high); assert(down[high] == now);
//			assert(ds[now] == us[low]); assert(us[now] == ds[high]);
			if(ds[now]) add_edge(id[now], id[low]);
			if(us[now]) add_edge(id[high], id[now]);
			up[low] = high; down[high] = low;
			us[low] = false; ds[high] = false;
			id[now] = -1;
		} else {
//			assert(false);
		}
	}
	memset(f, -1, sizeof(f));
	f[0] = INF;
	return dfs(n + 1);
}

int main() {
	init();
	printf("%d\n", solve());
	return 0;
}