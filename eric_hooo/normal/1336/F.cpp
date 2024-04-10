#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, pii> ppp;
typedef int Data;

const Data EPT(0);

vector <int> from[150010], G[150010];
int fa[150010][18], id[150010], TOT, sz[150010], dep[150010], QRY;
int mul[1000010], val[1000000];
vector <pii> qry[150010];
vector <int> a[150010];
vector <int> has[150010];
vector <ppp> all[150010];
vector <pii> rub;
vector <int> node;
vector <pii> Real[150010];
int n;
long long ans;
int st[150010];
int T[150010];

void modify(int x, int v) {
	while (x <= n) T[x] += v, x += x & -x;
}

int query(int x) {
	int res = 0;
	while (x) res += T[x], x -= x & -x;
	return res;
}

long long F(int x) {return 1ll * x * (x - 1) / 2;}

void dfs(int x, int last) {
	id[x] = ++TOT, sz[x] = 1, fa[x][0] = last;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dep[v] = dep[x] + 1, dfs(v, x), sz[x] += sz[v];
	}
}

void get_fa() {
	for (int j = 1; j < 18; j++) {
		for (int i = 1; i <= n; i++) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}

int get_lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int tmp = dep[x] - dep[y], cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

int get_par(int x, int tmp) {
	int cnt = 0;
	while (tmp) {
		if (tmp & 1) x = fa[x][cnt];
		tmp >>= 1, cnt++;
	}
	return x;
}

bool by_id(int x, int y) {return id[x] < id[y];}

bool is_anc(int x, int y) {return id[x] < id[y] && id[y] < id[x] + sz[x];}

int BuildTree() {
	sort(node.begin(), node.end(), by_id), node.resize(unique(node.begin(), node.end()) - node.begin());
	for (int i = (int)node.size() - 1; i >= 1; i--) {
		node.push_back(get_lca(node[i], node[i - 1]));
	}
	sort(node.begin(), node.end(), by_id), node.resize(unique(node.begin(), node.end()) - node.begin());
	for (int i = 0; i < node.size(); i++) {
		G[node[i]].clear(), has[node[i]].clear();
	}
	int tp = 0;
	for (int i = 0; i < node.size(); i++) {
		int x = node[i];
		while (tp && !is_anc(st[tp - 1], x)) tp--;
		if (tp) G[st[tp - 1]].push_back(x);
		st[tp++] = x;
	}
	return node[0];
}

struct Node {
	Data sum;
	Node *lson, *rson;
	void pushup() {sum = (lson ? lson->sum : EPT) + (rson ? rson->sum : EPT);}
}pool[3000010], *CUR;

void Update(Node *&T, int l, int r, int pos, Data x) {
	if (!T) T = CUR++, T->sum = EPT, T->lson = T->rson = NULL;
	if (l == r) {
		T->sum = T->sum + x;
		return ;
	}
	int mid = l + r >> 1;
	if (pos <= mid) Update(T->lson, l, mid, pos, x);
	else Update(T->rson, mid + 1, r, pos, x);
	T->pushup();
}

Data Query(Node *T, int l, int r, int L, int R) {
	if (!T) return EPT;
	if (l == L && r == R) return T->sum;
	int mid = l + r >> 1;
	if (R <= mid) return Query(T->lson, l, mid, L, R);
	if (L > mid) return Query(T->rson, mid + 1, r, L, R);
	return Query(T->lson, l, mid, L, mid) + Query(T->rson, mid + 1, r, mid + 1, R);
}

Node *Merge(Node *L, Node *R) {
	if (!L || !R) return L ? L : R;
	L->sum = L->sum + R->sum;
	L->lson = Merge(L->lson, R->lson);
	L->rson = Merge(L->rson, R->rson);
	return L; 
}

struct Block {
	Node *T;
	vector <int> *a;
	Block() {T = NULL, a = NULL;}
	Block(int x) {T = NULL, Update(T, 1, n, id[x], Data(1)), a = new vector <int>, a->push_back(x);}
};

Block Merge(Block A, Block B, int x, int lca, int K) {
	if (A.a == NULL || B.a == NULL) return A.a == NULL ? B : A;
	if (A.a->size() < B.a->size()) swap(A, B);
	for (vector <int> :: iterator it = B.a->begin(); it != B.a->end(); it++) {
		int y = *it;
		A.a->push_back(y);
		if (dep[x] + dep[y] - 2 * dep[lca] >= K) {
			int ny = get_par(y, min(dep[y] - dep[lca], dep[x] + dep[y] - 2 * dep[lca] - K));
			int l = id[ny], r = id[ny] + sz[ny] - 1;
			ans += Query(A.T, 1, n, l, r);
			if (dep[x] - dep[lca] >= K) ans -= Query(A.T, 1, n, 1, n);
			if (dep[y] - dep[lca] >= K) {
				int ny = get_par(y, dep[y] - dep[lca] - K);
				ans -= Query(A.T, 1, n, id[ny], id[ny] + sz[ny] - 1);
			}
		}
	}
	B.a->clear();
	A.T = Merge(A.T, B.T);
	return A;
}

Block work(int x, int lca, int K) {
	Block cur;
	for (int i = 0; i < G[x].size(); i++) {
		int v = G[x][i];
		cur = Merge(cur, work(v, lca, K), x, lca, K);
	}
	for (int i = 0; i < has[x].size(); i++) {
		cur = Merge(cur, Block(has[x][i]), x, lca, K);
	}
	return cur;
}

void get_ans(int x, int last, int K) {
	for (int i = 0; i < Real[x].size(); i++) {
		int u = Real[x][i].fi, v = Real[x][i].se;
		if (dep[u] - dep[x] >= K) {
			int p = get_par(u, dep[u] - dep[x] - K);
			ans += query(id[p] + sz[p] - 1) - query(id[p] - 1);
		}
		if (dep[v] - dep[x] >= K) {
			int p = get_par(v, dep[v] - dep[x] - K);
			ans += query(id[p] + sz[p] - 1) - query(id[p] - 1);
		}
		modify(id[u], 1), modify(id[v], 1);
	}
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		get_ans(v, x, K);
	}
	for (int i = 0; i < Real[x].size(); i++) {
		int u = Real[x][i].fi, v = Real[x][i].se;
		modify(id[u], -1), modify(id[v], -1);
	}
}

void solve(int K) {
	get_ans(1, 1, K);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < all[i].size(); j++) {
			int k = j;
			node.clear();
			while (k < all[i].size() && all[i][j].fi == all[i][k].fi) {
				node.push_back(all[i][k].se.fi);
				k++;
			}
			int rt = BuildTree();
			for (int l = j; l < k; l++) {
				has[all[i][l].se.fi].push_back(all[i][l].se.se);
			}
			CUR = pool;
			work(rt, i, K);
			j = k - 1;
		}
	}
}

int main() {
	int K, m; scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dfs(1, 1), get_fa();
	for (int i = 1; i <= m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		int lca = get_lca(x, y);
		Real[lca].push_back(mp(x, y));
		if (x != lca && y != lca) {
			pii t1 = mp(get_par(x, dep[x] - dep[lca] - 1), get_par(y, dep[y] - dep[lca] - 1));
			pii t2 = mp(x, y);
			if (t1.fi > t1.se) swap(t1.fi, t1.se), swap(t2.fi, t2.se);
			all[lca].push_back(mp(t1, t2));
		}
		x = id[x], y = id[y];
		if (x > y) swap(x, y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		sort(all[i].begin(), all[i].end());
	}
	solve(K);
	printf("%I64d\n", ans);
	return 0;
}