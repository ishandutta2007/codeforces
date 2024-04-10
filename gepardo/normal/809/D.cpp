#include <iostream>
#include <random>
#include <sstream>

using namespace std;

mt19937 rnd(42);

struct Treap {
	int x;
	int y;
	int lazy;
	int size;
	Treap *l, *r;
	
	Treap(int x) 
		: x(x), y(rnd()), lazy(0), size(1), l(nullptr), r(nullptr) {
	}
};
typedef Treap *pTreap;

inline void push(pTreap t) {
	if (t->l != nullptr) {
		t->l->lazy += t->lazy;
	}
	if (t->r != nullptr) {
		t->r->lazy += t->lazy;
	}
	t->x += t->lazy;
	t->lazy = 0;
}

inline int getSize(pTreap t) {
	if (t == nullptr) {
		return 0;
	} else {
		return t->size;
	}
}

inline void recalc(pTreap t) {
	if (t != nullptr) {
		t->size = getSize(t->l) + 1 + getSize(t->r);
	}
}

inline void split(pTreap t, pTreap &l, pTreap &r, int x) {
	if (t == nullptr) {
		l = r = nullptr;
	} else {
		push(t);
		if (x <= t->x) {
			split(t->l, l, t->l, x);
			r = t;
		} else {
			split(t->r, t->r, r, x);
			l = t;
		}
		recalc(l); recalc(r);
	}
}

inline void splitSize(pTreap t, pTreap &l, pTreap &r, int size) {
	if (t == nullptr) {
		l = r = nullptr;
	} else {
		push(t);
		int lSize = getSize(t->l);
		if (size <= lSize) {
			splitSize(t->l, l, t->l, size);
			r = t;
		} else {
			splitSize(t->r, t->r, r, size - lSize - 1);
			l = t;
		}
		recalc(l); recalc(r);
	}
}

inline pTreap min(pTreap t) {
	if (t == nullptr) {
		return nullptr;
	}
	while (t->l != nullptr) {
		push(t);
		t = t->l;
	}
	push(t);
	return t;
}

inline void merge(pTreap &t, pTreap l, pTreap r) {
	if (l == nullptr) {
		t = r;
	} else if (r == nullptr) {
		t = l;
	} else {
		push(l); push(r);
		if (l->y > r->y) {
			merge(l->r, l->r, r);
			t = l;
		} else {
			merge(r->l, l, r->l);
			t = r;
		}
		recalc(t);
	}
}

inline void add(pTreap t, int delta) {
	if (t != nullptr) {
		t->lazy += delta;
	}
}

const int infinity = 1234567890;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	pTreap t = new Treap(0);
	for (int i = 0; i < n; i++) {
		merge(t, t, new Treap(infinity));
	}
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		pTreap t1, t2, t3, t4;
		split(t, t1, t2, l);
		split(t2, t2, t3, r);
		splitSize(t3, t3, t4, 1);
		if (t2 != nullptr) {
			int minValue = min(t2)->x;
			add(t2, 1);
			t3->x = minValue;
			t3->lazy = 0;
			merge(t2, t3, t2);
			t3 = t4;
		} else {
			merge(t3, t3, t4);
		}
		merge(t2, t2, t3);
		splitSize(t2, t2, t3, 1);
		t2->x = l;
		t2->lazy = 0;
		merge(t2, t2, t3);
		merge(t, t1, t2);
	}
	pTreap l, r;
	split(t, l, r, infinity);
	cout << getSize(l) - 1 << endl;
	return 0;
}