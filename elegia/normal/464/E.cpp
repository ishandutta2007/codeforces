#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int H = 3;
const int HP[H] = {998244353, 1000000007, 1000000009};

const int N = 100010, L = 18;

struct Edge {
	int v, w;
	Edge* next;
};

struct Node {
	signed char k, v;
	int hsh[H];
	Node *ls, *rs;
};

struct Data {
	int u;
	Node* step;

	Data(int u, Node* step) : u(u), step(step) {}

	bool operator>(const Data& rhs) const;
};

int n, m;
int from[N];
int pw[L][H];
bool poped[N];
Edge* g[N];
Node* dis[N];

priority_queue<Data, vector<Data>, greater<Data> > q;

bool cmp(const Node* lhs, const Node* rhs);
void adde(int u, int v, int w);
Node* cons(int k);
bool ch(Node* p, int k);
Node* create();
Node* clone(const Node* p);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d%d", &n, &m);
	fill(pw[0], pw[0] + H, 2);
	for (int i = 1; i < L; ++i)
		for (int h = 0; h < H; ++h)
			pw[i][h] = pw[i - 1][h] * (ll)pw[i - 1][h] % HP[h];
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adde(u, v, w);
		adde(v, u, w);
	}
	int s, t;
	scanf("%d%d", &t, &s);
	q.emplace(s, dis[s] = cons(L - 1));
	while (!q.empty()) {
		Data tmp = q.top();
		q.pop();
		if (poped[tmp.u])
			continue;
//		LOG("%d: %d\n", tmp.u, tmp.step->hsh[0]);
		poped[tmp.u] = true;
		for (Edge* p = g[tmp.u]; p; p = p->next)
			if (!poped[p->v]) {
				Node* res = clone(tmp.step);
				ch(res, p->w);
				if (dis[p->v] == NULL || cmp(res, dis[p->v])) {
					from[p->v] = tmp.u;
					q.emplace(p->v, dis[p->v] = res);
				}
			}
	}
	if (!dis[t]) {
		puts("-1");
		return 0;
	}
	printf("%d\n", dis[t]->hsh[1]);
	vector<int> trace;
	while (t) {
		trace.push_back(t);
		t = from[t];
	}
	printf("%lu\n", trace.size());
	for (int x : trace)
		printf("%d ", x);

#ifndef ONLINE_JUDGE
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

Node* create() {
	static Node pool[N * L << 4];
	static Node* p = pool;
	return ++p;
}

Node* cons(int k) {
	Node* p = create();
	p->v = -1;
	p->k = k;
	if (k == 0)
		return p;
	p->ls = p->rs = cons(k - 1);
	return p;
}

bool cmp(const Node* lhs, const Node* rhs) {
	if (lhs->k == 0 || lhs->v != rhs->v)
		return lhs->v < rhs->v;
	for (int h = 0; h < H; ++h)
		if (lhs->rs->hsh[h] != rhs->rs->hsh[h])
			return cmp(lhs->rs, rhs->rs);
	return cmp(lhs->ls, rhs->ls);
}

bool Data::operator>(const Data &rhs) const {
	return cmp(rhs.step, step);
}

void adde(int u, int v, int w) {
	static Edge pool[N * 2];
	static Edge* p = pool;
	p->v = v;
	p->w = w;
	p->next = g[u];
	g[u] = p;
	++p;
}

Node* clone(const Node* p) {
	Node* ret = create();
	memcpy(ret, p, sizeof(Node));
	return ret;
}

bool ch(Node* p, int k) {
	if (p->k == 0) {
		if (p->v == 1) {
			p->v = -1;
			memset(p->hsh, 0, sizeof(p->hsh));
			return true;
		} else {
			p->v = 1;
			fill(p->hsh, p->hsh + H, 1);
			return false;
		}
	}
	if (k == 0 && p->v == 1) {
		p->v = -1;
		memset(p->hsh, 0, sizeof(p->hsh));
		return true;
	}

	// PUSH DOWN
	p->ls = clone(p->ls);
	p->rs = clone(p->rs);
	if (p->v == 1) {
		p->ls->v = p->rs->v = 1;
		for (int h = 0; h < H; ++h)
			p->ls->hsh[h] = p->rs->hsh[h] = pw[p->k - 1][h] - 1;
	} else if (p->v == -1) {
		p->ls->v = p->rs->v = -1;
		memset(p->ls->hsh, 0, sizeof(p->hsh));
		memset(p->rs->hsh, 0, sizeof(p->hsh));
	}

	if (k < (1 << (p->k - 1))) {
		if (ch(p->ls, k))
			k = 1 << (p->k - 1);
	}
	bool ret = false;
	k -= 1 << (p->k - 1);
	if (k >= 0) {
		if (ch(p->rs, k))
			ret = true;
	}
	for (int h = 0; h < H; ++h)
		p->hsh[h] = (p->ls->hsh[h] + p->rs->hsh[h] * (ll)pw[p->k - 1][h]) % HP[h];
	if (p->ls->v == p->rs->v) {
		p->v = p->ls->v;
	} else
		p->v = 0;

	return ret;
};