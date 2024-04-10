#include <iostream>
#include <vector>
#include <map>

#define endl '\n'

using namespace std;

struct query {
	int id, cnt;
};


struct node {
	int x, y, sz;
	node *l, *r;
	node() {}
	node(int _x) {
		x = _x;
		y = (rand() << 16) + rand();
		sz = 1;
		l = r = nullptr;
	}
};

int size(node *p) {
	return p ? p->sz : 0;
}

void upd_size(node *p) {
	p->sz = 1 + size(p->l) + size(p->r);
}

pair <node*, node*> split(node *p, int x) {
	if (!p) return {};
	if (p->x <= x) {
		pair <node*, node*> q = split(p->r, x);
		p->r = q.first;
		upd_size(p);
		return { p, q.second };
	}
	pair <node*, node*> q = split(p->l, x);
	p->l = q.second;
	upd_size(p);
	return { q.first, p };
}

node* merge(node *l, node *r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		upd_size(l);
		return l;
	}
	r->l = merge(l, r->l);
	upd_size(r);
	return r;
}

void insert(int val, node* &root) {
	pair <node*, node*> q = split(root, val);
	node *t = new node(val);
	root = merge(q.first, merge(t, q.second));
}

void erase(int val, node* &p) {
	if (p->x == val) {
		p = merge(p->l, p->r);
		if (p) upd_size(p);
		return;
	}
	if (p->x > val) {
		erase(val, p->l);
		upd_size(p);
		return;
	}
	erase(val, p->r);
	upd_size(p);
}

int get(int x, node* &root) {
	pair <node*, node*> q = split(root, x - 1);
	int ans = size(q.second);
	merge(q.first, q.second);
	return ans;
}

int n, q;
vector <bool> used;
vector <int> color, ans;
vector <vector <int>> graph;
vector <map <int, int>> cnt;
vector <vector <query>> queries;
vector <node*> treap;

void dfs(int v) {
	used[v] = true;
	cnt[v][color[v]] = 1;
	insert(1, treap[v]);
	for (int u : graph[v])
		if (!used[u]) {
			dfs(u);
			if (cnt[u].size() > cnt[v].size()) {
				swap(cnt[u], cnt[v]);
				swap(treap[u], treap[v]);
			}
			for (auto now : cnt[u]) {
				int key = now.first;
				int val = now.second;
				if (cnt[v].find(key) != cnt[v].end()) erase(cnt[v][key], treap[v]);
				cnt[v][key] += val;
				insert(cnt[v][key], treap[v]);
			}
		}
	for (auto now : queries[v]) {
		int id = now.id;
		int val = now.cnt;
		ans[id] = get(val, treap[v]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	used.resize(n), color.resize(n), graph.resize(n), cnt.resize(n), queries.resize(n), treap.resize(n), ans.resize(q);
	for (int i = 0; i < n; i++)
		cin >> color[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 0; i < q; i++) {
		int v, x;
		cin >> v >> x;
		v--;
		queries[v].push_back({ i, x });
	}
	dfs(0);
	for (int i = 0; i < q; i++)
		cout << ans[i] << endl;
	return 0;
}

/*
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8
*/