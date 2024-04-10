// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  Codeforces Round #424 (Div. 1)  |
+----------------------------------+
|             Problem B            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(42);

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

struct Treap {
	int x;
	int mv;
	int lazy;
	int size;
	int y;
	Treap *l, *r;
	
	Treap(int x)
		: x(x), mv(x), lazy(0), size(1), y(randGen()), l(nullptr), r(nullptr) {
	}
	
	~Treap() {
		if (l != nullptr) {
			delete l;
		}
		if (r != nullptr) {
			delete r;
		}
	}
};
typedef Treap* pTreap;

inline int getSize(pTreap t) {
	return (t != nullptr) ? t->size : 0;
}

inline int getMv(pTreap t) {
	return (t != nullptr) ? t->mv : infinity;
}

inline void update(pTreap t) {
	if (t != nullptr) {
		t->size = getSize(t->l) + 1 + getSize(t->r);
		t->mv = min(getMv(t->l), min(t->x, getMv(t->r)));
	}
}

void splitSize(pTreap t, pTreap& l, pTreap& r, int count) {
	if (t == nullptr) {
		l = r = nullptr;
	} else if (count <= getSize(t->l)) {
		splitSize(t->l, l, t->l, count);
		r = t;
	} else {
		splitSize(t->r, t->r, r, count - getSize(t->l) - 1);
		l = t;
	}
	update(l); update(r);
}

inline int findMin(pTreap t) {
	if (t == nullptr) {
		cerr << ":(" << endl;
		exit(42);
	}
	int sz = getSize(t->l);
	if (getMv(t) == getMv(t->r)) {
		return findMin(t->r) + sz + 1;
	} else if (t->x == getMv(t)) {
		return sz;
	} else {
		return findMin(t->l);
	}
}

void merge(pTreap& t, pTreap l, pTreap r) {
	if (l == nullptr || r == nullptr) {
		t = (l != nullptr) ? l : r;
	} else if (l->y > r->y) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	update(t);
}

signed main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	pTreap t = nullptr;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		merge(t, new Treap(v[i]), t);
	}
	int64_t ans = 0;
	for (int i = 0; i < n; i++) {
		int pos = findMin(t);
		pTreap l, m, r;
		splitSize(t, l, m, pos);
		splitSize(m, m, r, 1);
		merge(t, r, l);
		ans += n - i - pos;
	}
	cout << ans << endl;
	return 0;
}