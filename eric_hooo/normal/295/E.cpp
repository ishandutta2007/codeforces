#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

struct Treap {
	struct Node {
		int x, fix;
		long long size, ll, rr;
		long long lsum, rsum, dist;
		Node *left, *right;
		Node() {}
		Node(int _x, Node *l = NULL, Node *r = NULL) {
			x = _x, left = l, right = r, fix = rand(), size = 1;
			ll = rr = x, lsum = 0, rsum = 0, dist = 0;
		}
		void pushup() {
			if (!left && !right) {
				size = 1, ll = rr = x, lsum = rsum = dist = 0;
				return ;
			}
			size = 1;
			if (left) size += left->size;
			if (right) size += right->size;
			ll = rr = x;
			if (left) ll = left->ll;
			if (right) rr = right->rr;
			lsum = rsum = 0;
			if (!right) {
				lsum = left->lsum + x - left->ll;
				rsum = left->rsum + left->size * (x - left->rr);
			} else if (!left) {
				lsum = right->lsum + right->size * (right->ll - x);
				rsum = right->rsum + right->rr - x;
			} else {
				lsum = left->lsum + x - left->ll + right->lsum + right->size * (right->ll - left->ll);
				rsum = right->rsum + right->rr - x + left->rsum + left->size * (right->rr - left->rr);
			}
			dist = 0;
			if (left) dist += left->dist + left->rsum + left->size * (x - left->rr);
			if (right) dist += right->dist + right->lsum + right->size * (right->ll - x);
			if (left && right) {
				dist += right->size * left->rsum + left->size * right->lsum;
				dist += (right->ll - left->rr) * left->size * right->size;
			}
		}
	}*T;
	typedef pair <Node *, Node *> pnn;
	void init() {T = NULL;}
	Node *merge(Node *l, Node *r) {
		if (!l || !r) return l ? l : r;
		if (l->fix < r->fix) {
			l->right = merge(l->right, r);
			l->pushup();
			return l;
		} else {
			r->left = merge(l, r->left);
			r->pushup();
			return r;
		}
	}
	pnn split(Node *T, int val) {
		if (!T) return pnn(NULL, NULL);
		if (val < T->x) {
			pnn t = split(T->left, val);
			T->left = t.se, T->pushup();
			return mp(t.fi, T);
		} else {
			pnn t = split(T->right, val);
			T->right = t.fi, T->pushup();
			return mp(T, t.se);
		}
	}
	void insert(int x) {
		pnn t = split(T, x - 1);
		T = merge(t.fi, merge(new Node (x), t.se));
	}
	void erase(int x) {
		pnn t1 = split(T, x - 1), t2 = split(t1.se, x);
		delete t2.fi;
		T = merge(t1.fi, t2.se);
	}
	long long query(int l, int r) {
		pnn t1 = split(T, l - 1), t2 = split(t1.se, r);
		long long ans = t2.fi ? t2.fi->dist : 0;
		T = merge(t1.fi, merge(t2.fi, t2.se));
		return ans;
	}
	void print(Node *T, string s = "    ") {
		if (!T) {
			cout << s << "NULL" << endl;
			return ;
		}
		cout << s << "x:" << T->x << endl;
		cout << s << "  size:" << T->size << endl;
		cout << s << "  dist:" << T->dist << endl; 
		cout << s << "  lsum:" << T->lsum << endl;
		cout << s << "  rsum:" << T->rsum << endl;
		cout << s << "  ll & rr:" << T->ll << " " << T->rr << endl;
		cout << s << "  lson:" << endl;
		print( T->left, s + "  ");
		cout << s << "  rson:" << endl;
		print(T->right, s + "  ");
	}
}T;

int a[100010];

int main() {
	srand(232373);
	int n; scanf("%d", &n);
	T.init();
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		T.insert(a[i]);
	}
//	T.print(T.T);
	int q; scanf("%d", &q);
	while (q--) {
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		if (op == 1) T.erase(a[x]), a[x] += y, T.insert(a[x]);
		else printf("%I64d\n", T.query(x, y));
	}
	return 0;
}