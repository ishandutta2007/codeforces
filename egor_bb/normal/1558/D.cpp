#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

mt19937 rng(239);


struct Node {
	Node *l, *r, *p;
	int val;
	int y;
	int add;
	Node(int x): l(nullptr), r(nullptr), p(this), val(x), y(rng()), add(0) {}
	
	void push() {
		if (l) {
			l->val += add;
			l->add += add;
		}
		if (r) {
			r->val += add;
			r->add += add;
		}
		add = 0;
	}
	
	void print() {
		push();
		if (l) l->print();
		cerr << val << " ";
		if (r) r->print();
	}
};


Node* merge(Node *a, Node *b) {
	if (!a) return b;
	if (!b) return a;
	a->push();
	b->push();
	if (a->y < b->y) {
		a->r = merge(a->r, b);
		if (a->r) a->r->p = a;
		return a;
	}
	b->l = merge(a, b->l);
	if (b->l) b->l->p = b;
	return b;
}

void split(Node *root, Node *&a, Node *&b, int val) {
	if (!root) {
		a = b = nullptr;
		return;
	}
	root->push();
	if (root->val >= val) {
		split(root->l, a, root->l, val);
		if (root->l) root->l->p = root;
		b = root, b->p = b;
	} else {
		split(root->r, root->r, b, val);
		if (root->r) root->r->p = root;
		a = root, a->p = a;
		a->p = a;
	}
}

bool present(Node *v, int val) {
	v->push();
	if (v->val == val) {
		return true;
	}
	if (v->val < val) {
		if (!v->r) return false;
		return present(v->r, val);
	}
	if (!v->l) return false;
	return present(v->l, val);
}

inline Node* rotate(Node* root, int k) {
	if (k == 0) return root;
	Node *l, *r;
	split(root, l, r, k);
	return merge(r, l);
}

const int MOD = 998244353;
const int N = 5e5;


int add(int a, int b) {
	a += b;
	return a >= MOD ? a - MOD : a;
}

int mult(int a, int b) {
	return int((a * 1ll * b) % MOD);
}

int pow(int x, int d) {
	if (d == 0) return 1;
	int t = pow(x, d / 2);
	t = mult(t, t);
	if (d & 1) t = mult(t, x);
	return t;
}

int inv(int x) {
	return pow(x, MOD - 2);
}

int fact[N], invFact[N];

void init() {
	fact[0] = 1;
	forab(i, 1, N) {
		fact[i] = mult(i, fact[i - 1]);
	}
	invFact[N - 1] = inv(fact[N - 1]);
	fornr(i, N - 1) {
		invFact[i] = mult(invFact[i + 1], i + 1);
	}
}

int compC(int n, int k) {
	//cerr << n << " " << k << '\n';
	return mult(fact[n], mult(invFact[n - k], invFact[k]));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	init();
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		int nBalls = n - 1;
		Node *root = new Node(MOD);
		forn(i, m) {
			int x, y;
			cin >> x >> y;
			if (present(root, y)) {
				Node *l, *r;
				split(root, l, r, y);
				r->add++;
				r->val++;
				root = merge(l, r);
				continue;
			}
			Node *l, *r;
			split(root, l, r, y);
			r->add++;
			r->val++;
			Node *cur = new Node(y + 1);
			root = merge(l, merge(cur, r));
			nBalls--;
		//	root->print();
		//	cerr << '\n';
		}
		int nUrns = n + 1;
	//	cerr << nBalls << " " << nUrns << '\n';
		cout << compC(nBalls + nUrns - 1, nBalls) << '\n';
	}
	return 0;
}