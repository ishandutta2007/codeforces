#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define MAX 500000
#define MAXLG 20
#define MAXSEG ((1<<20) + 2 * MAXN * MAXLG)
int N, M;
pair<int, int> A[MAXN];
struct node {
	node *l, *r;
	int x;
} vals[MAXSEG]; int t = 0;
node* tree[MAXN];

node* build_tree(int lo=0, int hi=-1) {
	if (hi == -1) hi = MAX;
	node* cur = &vals[t++];
	if (lo != hi) {
		int mid = (lo + hi) / 2;
		cur->l = build_tree(lo, mid);
		cur->r = build_tree(mid + 1, hi);
	}
	return cur;
}

node* update(node* n, int i, int x, int lo=0, int hi=-1) {
	if (hi == -1) hi = MAX;
	if (hi < i || lo > i) return n;
	node* v = &vals[t++];
	if (lo == hi) { v->x = n->x + x; return v; }
	int mid = (lo + hi) / 2;
	v->l = update(n->l, i, x, lo, mid);
	v->r = update(n->r, i, x, mid + 1, hi);
	v->x = v->l->x + v->r->x;
	return v;
}

int query(node* n, int s, int e, int lo=0, int hi=-1) {
	if (hi == -1) hi = MAX;
	if (hi < s || lo > e) return 0;
	if (lo >= s && hi <= e) return n->x;
	int mid = (lo + hi) / 2;
	return query(n->l, s, e, lo, mid) + 
			query(n->r, s, e, mid + 1, hi);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}

	sort(A, A + N, [](auto& p, auto& q) {
		return p.first != q.first ? p.first < q.first : p.second > q.second;
	});

	vector<pair<int, int> > v, e;
	e.emplace_back(0, A[0].first);

	int mx = 0;
	for (int i = 0; i < N; i++) {
		if (A[i].second > mx) {
			if (v.size() && v.back().second < A[i].first)
				e.emplace_back(v.back().second, A[i].first);
			v.emplace_back(A[i].first, A[i].second);
			mx = A[i].second;
		}
	}

	e.emplace_back(mx, MAX);

	node* empty_tree = build_tree();
	for (int i = v.size() - 1; i >= 0; i--) {
		int cut = v[i].second;
		int j = lower_bound(v.begin(), v.end(), pair<int, int> { v[i].second + 1, 0 }) - v.begin() - 1;
		if (j == i) {
			tree[i] = update(empty_tree, cut, MAXN);
		}
		else {
			tree[i] = update(tree[j], v[i].second, 1);
		}
	}

	while (M--) {
		int x, y;
		cin >> x >> y;
		int k = lower_bound(e.begin(), e.end(), pair<int, int> { y, 0 }) - e.begin() - 1;
		if (e[k].second > x) {
			cout << -1 << '\n';
			continue;
		}
		k = lower_bound(v.begin(), v.end(), pair<int, int> { x + 1, 0 }) - v.begin() - 1;
		int ans = query(tree[k], 0, y - 1) + 1;
		cout << (ans > MAXN ? -1 : ans) << '\n';
	}

	cout.flush();
	return 0;
}