#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Node {
	Node *ls, *rs;
	int l, r, d;
	
	int qry(int l, int r) const {
		if (l == this->l && r == this->r)
			return d;
		if (r <= ls->r)
			return ls->qry(l, r);
		if (l >= rs->l)
			return rs->qry(l, r);
		return max(ls->qry(l, ls->r), rs->qry(rs->l, r));
	}
};

const int N = 100010, K = 300010, L = 20, INF = 1e9 + 1;

int n, m, k;
int cur[N];
int sl[K], sr[K], sp[K];
int disc[K];
Node* per[K];
vector<pair<int, int> > good[K];

Node* ch(Node* p, int k, int v);
Node* build(int l, int r);
Node* create();

int main() {

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++i) {
		scanf("%d%d%d", &sl[i], &sr[i], &sp[i]);
		disc[i] = sl[i];
	}
	
	sort(disc + 1, disc + k + 1, greater<int>());
	fill(cur + 1, cur + n + 1, INF);
	for (int i = 1; i <= k; ++i)
		good[lower_bound(disc + 1, disc + k + 1, sl[i], greater<int>()) - disc].emplace_back(sr[i], sp[i]);
	per[0] = build(1, n);
	for (int i = 1; i <= k; ++i) {
		per[i] = per[i - 1];
		for (const auto& seg : good[i]) {
			if (cur[seg.second] > seg.first)
				per[i] = ch(per[i], seg.second, cur[seg.second] = seg.first);
		}
	}
	
	while (m--) {
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
	//	LOG("%d ", x);
		x = upper_bound(disc + 1, disc + k + 1, x, greater<int>()) - disc - 1;
		if (per[x]->qry(a, b) <= y)
			puts("yes");
		else
			puts("no");
		fflush(stdout);
	}

	return 0;
}

Node* create() {
	static Node pool[N * 2 + K * L];
	static Node* p = pool;
	return p++;
}

Node* build(int l, int r) {
	Node* p = create();
	p->l = l;
	p->r = r;
	p->d = INF;
	if (l == r) {
		return p;
	}
	int mid = (l + r) >> 1;
	p->ls = build(l, mid);
	p->rs = build(mid + 1, r);
	return p;
}

Node* ch(Node* p , int k, int v) {
	Node* ret = create();
	ret->l = p->l;
	ret->r = p->r;
	if (p->l == p->r) {
		ret->d = v;
		return ret;
	}
	if (k <= p->ls->r) {
		ret->rs = p->rs;
		ret->ls = ch(p->ls, k, v);
	} else {
		ret->ls = p->ls;
		ret->rs = ch(p->rs, k, v);
	}
	ret->d = max(ret->ls->d, ret->rs->d);
	return ret;
}