#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 1000
#define MAXM 1000
#define MAXNODE 200013
#define INF 1000000000
int N, M;
int F[MAXN][MAXM];
bool present[MAXN][MAXM];
pair<int, int> pos[MAXNODE];

// Link-cut node
struct node {
	node* p;
	node* c[2];
	int x, s;
	bool flip;

	bool r() { return !p || (p->c[0] != this && p->c[1] != this); }
	int d() { return r() ? -1 : p->c[1] == this; }

	void update() {
		s = x + (c[0] ? c[0]->s : 0) + (c[1] ? c[1]->s : 0);
	}

	void push() {
		if (flip) {
			swap(c[0], c[1]);
			if (c[0]) c[0]->flip ^= 1;
			if (c[1]) c[1]->flip ^= 1;
			flip = false;
		}
	}

	static void connect(node* pa, node* ch, int dir) {
		if (ch) ch->p = pa;
		if (dir != -1) pa->c[dir] = ch;
	}

	void rot() {
		assert(!r());

		int x = d();
		node* pa = p;

		connect(pa->p, this, pa->d());
		connect(pa, c[!x], x);
		connect(this, pa, !x);

		pa->update();
		update();
	}

	void splay() {
		while (!r() && !p->r()) {
			p->p->push();
			p->push();
			push();
			if (d() == p->d()) p->rot();
			else rot();
			rot();
		}
		if (!r()) {
			p->push();
			push();
			rot();
		}
		push();
	}

	void expose() {
		node* pre = nullptr;
		for (node* v = this; v; v = v->p) {
			v->splay();
			v->c[1] = pre;
			v->update();
			pre = v;
		}
		splay();
	}

	void make_root() {
		expose();
		flip ^= 1;
	}

} verts[MAXNODE];

inline node* n(int i) { return verts + i; }

node* find_root(node* x) {
	x->expose();
	while (x->c[0]) x = x->c[0];
	x->splay();
	return x;
}

bool connected(node* x, node* y) {
	return find_root(x) == find_root(y);
}

void link(node* x, node* y) {
	x->make_root();
	x->p = y;
}

void cut(node* x, node* y) {
	x->make_root();
	y->expose();
	assert(!y->c[1]);
	assert(y->c[0] == x);
	y->c[0] = nullptr;
	x->p = nullptr;
	y->update();
}

void upd(node* x, int amt) {
	x->splay();
	x->x = amt;
	x->update();
}

int path_aggregate(node* x, node* y) {
	x->make_root();
	y->expose();
	return y->s;
}

#define MAXSEG (1<<19)
pair<int, int> st[MAXSEG];
int lazy[MAXSEG];

pair<int, int> combine(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first < b.first) return a;
	if (a.first > b.first) return b;
	return {a.first, a.second + b.second};
}

void init(int lo, int hi, int node) {
	if (lo == hi) {
		st[node] = {-lo, 1}; // initialize to -i
		return;
	}
	int mid = (lo + hi) / 2;
	init(lo, mid, 2 * node + 1);
	init(mid + 1, hi, 2 * node + 2);
	st[node] = combine(st[2 * node + 1], st[2 * node + 2]);
}

void push(int lo, int hi, int node) {
	st[node].first += lazy[node];
	if (lo != hi) {
		lazy[2 * node + 1] += lazy[node];
		lazy[2 * node + 2] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int s, int e, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N * M - 1;
	push(lo, hi, node);
	if (lo > e || hi < s) return;
	if (s <= lo && hi <= e) {
		lazy[node] = x;
		push(lo, hi, node);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	st[node] = combine(st[2 * node + 1], st[2 * node + 2]);
}

pair<int, int> query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N * M - 1;
	push(lo, hi, node);
	if (lo > e || hi < s) return {INF, 0};
	if (s <= lo && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return combine(
		query(s, e, lo, mid, 2 * node + 1),
		query(s, e, mid + 1, hi, 2 * node + 2)
	);
}

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int lo = 0, hi = 0; // [lo, hi) two-pointer interval

bool add_node(int node) {
	int x = pos[node].first, y = pos[node].second;
	vector<int> neighbors;
	set<int> roots;
	for (int k = 0; k < 4; k++) {
		int x2 = x + dx[k];
		int y2 = y + dy[k];
		if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && F[x2][y2] >= lo && F[x2][y2] < hi) {
			neighbors.push_back(F[x2][y2]);
			int r = find_root(n(F[x2][y2])) - verts;
			if (roots.count(r)) {
				return false; // adding this node would create a cycle
			}
			roots.insert(r);
		}
	}

	for (int c : neighbors) {
		link(n(node), n(c));
		update_range(0, c, -1); // detected an edge, in this interval!
	}
	return true;
}

void remove_node(int node) {
	assert(node == lo);
	int x = pos[node].first, y = pos[node].second;
	vector<int> neighbors;
	for (int k = 0; k < 4; k++) {
		int x2 = x + dx[k];
		int y2 = y + dy[k];
		if (x2 >= 0 && x2 < N && y2 >= 0 && y2 < M && F[x2][y2] >= lo && F[x2][y2] < hi) {
			neighbors.push_back(F[x2][y2]);
		}
	}

	for (int c : neighbors) {
		cut(n(node), n(c));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> F[i][j];
			--F[i][j];
			pos[F[i][j]] = {i, j};
		}
	}

	init(0, N * M - 1, 0);

	LL ans = 0;
	while (lo < N * M) {
		// try to advance hi as much as possible
		while (hi < N * M) {
			bool ok = add_node(hi);
			if (!ok) break;
			++hi;

			// add the right amount to ans
			assert(hi > lo);
			auto p = query(lo, hi - 1);
			assert(p.first == -(hi - 1));
			ans += p.second;
		}

		// advance lo
		remove_node(lo);
		++lo;
	}

	cout << ans << endl;
	return 0;
}