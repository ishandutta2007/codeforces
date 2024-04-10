#include <bits/stdc++.h>
using namespace std;

using ll = long long;

mt19937 mt(1198237);
using rand_int = mt19937::result_type;
struct treap {
	rand_int pri = mt();
	ll key = 0;
	ll duration;

	ll end;
	ll totDur;

	treap* ch[2] = {nullptr, nullptr};

	void update() {
		totDur = duration + (ch[0] ? ch[0]->totDur : 0) + (ch[1] ? ch[1]->totDur : 0);

		end = key;
		if (ch[0]) {
			end = max(end, ch[0]->end);
		}
		end += duration;
		if (ch[1]) {
			end = max(end + ch[1]->totDur, ch[1]->end);
		}
	}
};

void merge(treap* a, treap* b, treap* &r) {
	if (!a) {
		r = b;
		return;
	}
	if (!b) {
		r = a;
		return;
	}

	if (a->pri < b->pri) {
		r = a;
		merge(a->ch[1], b, r->ch[1]);
	} else {
		r = b;
		merge(a, b->ch[0], r->ch[0]);
	}
	
	r->update();
}

void split(int t, treap* r, treap* &a, treap* &b) {
	if (!r) {
		a = b = nullptr;
		return;
	}

	if (r->key <= t) {
		a = r;
		split(t, r->ch[1], a->ch[1], b);
	} else {
		b = r;
		split(t, r->ch[0], a, b->ch[0]);
	}
	r->update();
}

const int MAXQ = 3.1e5;
int Q;
treap nodes[MAXQ];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> Q;
	treap* root = nullptr;
	for (int q = 1; q <= Q; q++) {
		char op; cin >> op;
		if (op == '+') {
			cin >> nodes[q].key >> nodes[q].duration;
			nodes[q].update();
			treap *l, *r;
			split(nodes[q].key, root, l, r);
			merge(l, &nodes[q], root);
			merge(root, r, root);
		} else if (op == '-') {
			int ind; cin >> ind;
			assert(nodes[ind].key != 0);
			ll t = nodes[ind].key;
			treap *l, *m, *r;
			split(t, root, l, r);
			split(t-1, l, l, m);
			assert(m == &nodes[ind]);
			nodes[ind].key = 0;
			merge(l, r, root);
		} else if (op == '?') {
			ll t; cin >> t;

			treap *l, *r;
			split(t, root, l, r);

			ll res = t;
			if (l) res = max(res, l->end);
			cout << res - t << '\n';

			merge(l, r, root);
		} else assert(false);
	}
}