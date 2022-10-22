#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const char nl = '\n';
const int MOD = 1e9+7;

int add(int a, int b) {
	return (a+b < MOD ? a+b : a+b - MOD);
}
int mul(int a, int b) {
	return (ll)a*b % MOD;
}

int power(int n, int e) {
	int res = 1;
	for(;e;e/=2) {
		if(e&1) res = mul(res,n);
		n = mul(n,n);
	}
	return res;
}

int inverse(int n) {
	return power(n, MOD-2);
}

const int N = 1<<17;
vector<int> adj[N];
int lc[N], rc[N], inv[N];
int addv[N], subv[N], tot[N];
int sz[N];

struct SegTree {
	struct Node {
		int sum, sv, z;
		Node *l, *r;
		Node(): sum(0), sv(0), z(0), l(nullptr), r(nullptr) {}
		~Node() {
			if(l != nullptr) delete l;
			if(r != nullptr) delete r;
		}
		void apply(int v, int s, int e) {
			sum = add(sum, MOD - mul(e-s+1, mul(v,v)));
			sum = add(sum, mul(v, add(tot[e], (s ? MOD-tot[s-1] : 0))));
			sum = add(sum, MOD - mul(mul(2,v), sv));
			sv = add(sv, mul(e-s+1, v));
			z = add(z, v);
		}
	};
	Node* root;
	SegTree(): root(new Node()) {}

	void push(Node* i, int s, int m, int e) {
		if(i->z) {
			if(i->l == nullptr) i->l = new Node();
			i->l->apply(i->z, s, m);
			if(i->r == nullptr) i->r = new Node();
			i->r->apply(i->z, m+1, e);
			i->z = 0;
		}
	}

	void pull(Node* i) {
		i->sum = i->sv = 0;
		if(i->l != nullptr) {
			i->sum = add(i->sum, i->l->sum);
			i->sv = add(i->sv, i->l->sv);
		}
		if(i->r != nullptr) {
			i->sum = add(i->sum, i->r->sum);
			i->sv = add(i->sv, i->r->sv);
		}
	}

	void insert(int l, int r, int v) {
		insert(l, r, v, root, 0, N-1);
	}
	Node* insert(int l, int r, int v, Node* i, int s, int e) {
		if(r<s || e<l) return i;
		if(i == nullptr) i = new Node();
		if(l<=s && e<=r) {
			i->apply(v,s,e);
			return i;
		}
		int m = (s+e)/2;
		push(i,s,m,e);
		i->l = insert(l,r,v,i->l,s,m);
		i->r = insert(l,r,v,i->r,m+1,e);
		pull(i);
		return i;
	}

	int query() {
		return root->sum;
	}

	void erase() {
		delete root;
	}
};

SegTree st[N];

void merge(int u, int p, int r) {
	st[r].insert(lc[u], rc[u], inv[u]);
	for(int v:adj[u]) {
		if(v==p) continue;
		merge(v, u, r);
	}
}

int solve(int u, int p) {
	sz[u] = 1;
	int best = 0;
	int child = -1;
	int res = 0;
	for(int v:adj[u]) {
		if(v==p) continue;
		res = add(res, solve(v, u));
		sz[u] += sz[v];
		if(sz[v] > best) {
			best = sz[v];
			child = v;
		}
	}
	if(p == 0) {
		return res;
	}

	if(child != -1) {
		st[u] = st[child];
		for(int v:adj[u]) {
			if(v==p || v==child) continue;
			st[v].erase();
			merge(v, u, u);
		}
	}
	st[u].insert(lc[u], rc[u], inv[u]);
	res = add(res, st[u].query());
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;
	int all = 1;
	for(int i=1; i<=n; i++) {
		cin >> lc[i] >> rc[i];
		int len = rc[i]-lc[i]+1;
		all = mul(all, len);
		inv[i] = inverse(len);
		addv[lc[i]] = add(addv[lc[i]], inv[i]);
		subv[rc[i]] = add(subv[rc[i]], MOD-inv[i]);
	}

	int cur = 0;
	for(int i=1;i<N;i++) {
		cur = add(cur, addv[i]);
		tot[i] = add(tot[i-1], cur);
		cur = add(cur, subv[i]);
	}

	for(int i=1; i<n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << mul(all, solve(1, 0)) << nl;

	return 0;
}