#include<bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 mt(48);
struct treap;
treap* null = nullptr;
struct treap {
	using key_type = pair<ll, mt19937::result_type>;
	treap* ch[2] = {null, null};
	mt19937::result_type pri = mt();
	mt19937::result_type key2 = mt();
	ll val = 0;
	int sz = 1;
	ll sum = 0;
	void update() {
		sz = 1 + ch[0]->sz + ch[1]->sz;
		sum = val + ch[0]->sum + ch[1]->sum;
	}
	key_type key() { return make_pair(val, key2); }
};
void init_treap() {
	null = new treap();
	null->ch[0] = null->ch[1] = null;
	null->val = 0;
	null->sz = 0;
	null->sum = 0;
}

void merge(treap* a, treap* b, treap* &r) {
	assert(a && b);
	if (a == null) {
		r = b;
		return;
	}
	if (b == null) {
		r = a;
		return;
	}
	if (a->pri < b->pri) {
		r = a;
		merge(a->ch[1], b, r->ch[1]);
		r->update();
	} else {
		r = b;
		merge(a, b->ch[0], r->ch[0]);
		r->update();
	}
}

void split_elem(treap* v, treap* r, treap* &a, treap* &b) {
	assert(v && v != null);
	assert(r);
	if (r == null) {
		a = b = null;
		return;
	} else if (r->key() == v->key()) {
		assert(r == v);
		a = r->ch[0];
		b = r->ch[1];
		r->ch[0] = r->ch[1] = null;
		r->update();
		return;
	} else if (v->key() > r->key()) {
		a = r;
		split_elem(v, r->ch[1], a->ch[1], b);
		a->update();
		return;
	} else {
		b = r;
		split_elem(v, r->ch[0], a, b->ch[0]);
		b->update();
		return;
	}
}

void split_sz(int k, treap* r, treap* &a, treap* &b) {
	assert(r);
	assert(0 <= k && k <= r->sz);
	if (r == null) {
		a = b = null;
		return;
	}
	if (k <= r->ch[0]->sz) {
		b = r;
		split_sz(k, r->ch[0], a, b->ch[0]);
		b->update();
	} else {
		a = r;
		split_sz(k - r->ch[0]->sz - 1, r->ch[1], a->ch[1], b);
		a->update();
	}
}

void remove_elem(treap* v, treap* &r) {
	int s0 = r->sz;
	treap *a, *b;
	split_elem(v, r, a, b);
	merge(a, b, r);
	assert(r->sz == s0-1);
}

void insert_elem(treap* v, treap* &r) {
	int s0 = r->sz;
	treap *a, *b;
	split_elem(v, r, a, b);
	merge(a, v, a);
	merge(a, b, r);
	assert(r->sz == s0 + 1);
}

const int MAXN = 3.1e5;
int N;
int deg[MAXN];
int A[MAXN];
int B[MAXN];
ll C[MAXN];
treap edge_nodes[MAXN];

vector<pair<int, int>> adj[MAXN];
treap* vert_roots[MAXN];

vector<int> rem_edges[MAXN];

bool vis[MAXN];

int X;
// first = don't use edge <= X, second = use edge <= X-1
// second is more restrictive, so it should have higher cost
pair<ll, ll> dfs(int cur, int prv) {
	//cerr << cur << ' ' << prv << '\n';
	assert(X > 0);
	assert(deg[cur] > X);
	assert(int(adj[cur].size()) + vert_roots[cur]->sz == deg[cur]);

	assert(!vis[cur]);
	vis[cur] = true;

	ll allCost = 0;

	for (auto ed : adj[cur]) {
		int nxt = ed.first;
		int e = ed.second;
		if (nxt == prv) continue;
		auto ch = dfs(nxt, cur);
		allCost += ch.second;

		assert(ch.first <= ch.second);
		ll v = C[e] + ch.first - ch.second;
		if (v < 0) {
			allCost += v;
			v = 0;
		}
		assert(edge_nodes[e].ch[0] == null);
		assert(edge_nodes[e].ch[1] == null);
		assert(v >= 0);
		edge_nodes[e].val = v;
		edge_nodes[e].update();
		insert_elem(&edge_nodes[e], vert_roots[cur]);
	}

	assert(bool(prv) + vert_roots[cur]->sz == deg[cur]);

	pair<ll, ll> ans;
	treap *a, *b;
	split_sz(vert_roots[cur]->sz - X, vert_roots[cur], a, b);
	ans.first = allCost + a->sum;
	merge(a, b, vert_roots[cur]);

	split_sz(vert_roots[cur]->sz - (X-1), vert_roots[cur], a, b);
	ans.second = allCost + a->sum;
	merge(a, b, vert_roots[cur]);

	assert(bool(prv) + vert_roots[cur]->sz == deg[cur]);

	for (auto ed : adj[cur]) {
		int nxt = ed.first;
		int e = ed.second;
		if (nxt == prv) continue;
		remove_elem(&edge_nodes[e], vert_roots[cur]);
	}
	//cerr << cur << ' ' << prv << ' ' << ans.first << ' ' << ans.second << '\n';
	assert(ans.first <= ans.second);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init_treap();

	cin >> N;
	for (int i = 1; i <= N-1; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}

	for (int i = 1; i <= N-1; i++) {
		deg[A[i]] ++;
		deg[B[i]] ++;
	}

	for (int i = 1; i <= N-1; i++) {
		if (deg[A[i]] > deg[B[i]]) swap(A[i], B[i]);
		assert(deg[A[i]] <= deg[B[i]]);
	}

	for (int i = 1; i <= N; i++) vert_roots[i] = null;

	for (int i = 1; i <= N-1; i++) {
		edge_nodes[i].ch[0] = edge_nodes[i].ch[1] = null;
		edge_nodes[i].val = C[i];
		edge_nodes[i].update();

		assert(deg[A[i]] <= deg[B[i]]);
		insert_elem(&edge_nodes[i], vert_roots[B[i]]);
		rem_edges[deg[A[i]]].push_back(i);
	}

	vector<int> verts;
	for (int i = 1; i <= N; i++) verts.push_back(i);
	sort(verts.begin(), verts.end(), [&](int a, int b) -> bool { return deg[a] > deg[b]; });

	vector<ll> ans;

	for (X = N-1; X > 0; X--) {
		// all vertices of degree >x are now bad
		for (int e : rem_edges[X+1]) {
			assert(deg[A[e]] <= deg[B[e]]);
			assert(deg[A[e]] == X+1);
			remove_elem(&edge_nodes[e], vert_roots[B[e]]);
			adj[B[e]].emplace_back(A[e], e);
			adj[A[e]].emplace_back(B[e], e);
		}

		for (int i : verts) {
			if (deg[i] <= X) break;
			vis[i] = false;
		}

		ll tot = 0;

		for (int i : verts) {
			if (deg[i] <= X) break;

			if (vis[i]) continue;
			tot += dfs(i, 0).first;
		}
		ans.push_back(tot);
	}

	ll a0 = 0;
	for (int i = 1; i <= N-1; i++) a0 += C[i];
	ans.push_back(a0);
	reverse(ans.begin(), ans.end());
	for (int x = 0; x <= N-1; x++) {
		cout << ans[x] << " \n"[x==N-1];
	}

	return 0;
}