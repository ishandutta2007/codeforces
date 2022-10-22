#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Submatrix {
	int l[3];
	int r[3];
	int components;

	Submatrix() {
	}
};

Submatrix unit_matrix() {
	Submatrix u;
	rep(i,0,3) {
		u.l[i] = -1;
		u.r[i] = -1;
	}
	u.components = 0;
	return u;
}

int num_different(const vector<int>& v) {
	vector<int> d;
	for (int x : v) {
		if(find(all(d), x) == d.end()) {
			d.push_back(x);
		}
	}
	return sz(d);
}

vector<int> rename_vec;

Submatrix merge(Submatrix a, Submatrix b) {
	int max_a = 0;
	rep(i,0,3) {
		max_a = max(max_a, a.l[i]);
		max_a = max(max_a, a.r[i]);
	}
	max_a += 2;
	rep(i,0,3) {
		if (b.l[i] >= 0) {
			b.l[i] += max_a;
		}
		if (b.r[i] >= 0) {
			b.r[i] += max_a;
		}
	}
	/*vector<int> orig_components;
	rep(i,0,3) {
		orig_components.push_back(a.l[i]);
		orig_components.push_back(a.r[i]);
		orig_components.push_back(b.l[i]);
		orig_components.push_back(b.r[i]);
	}*/
	Submatrix c;
	rep(i,0,3) {
		c.l[i] = a.l[i];
		c.r[i] = b.r[i];
	}
	c.components = a.components+b.components;
	rep(i,0,3) {
		if (a.r[i] >= 0 && b.l[i] >= 0 && a.r[i] != b.l[i]) {
			int from = b.l[i];
			int to = a.r[i];
			c.components--;
			rep(j,0,3) {
				if (b.l[j] == from)
					b.l[j] = to;
				if (b.r[j] == from)
					b.r[j] = to;
				if (c.l[j] == from)
					c.l[j] = to;
				if (c.r[j] == from)
					c.r[j] = to;
			}
		}
	}
	/*vector<int> final_components;
	rep(i,0,3) {
		final_components.push_back(a.l[i]);
		final_components.push_back(a.r[i]);
		final_components.push_back(b.l[i]);
		final_components.push_back(b.r[i]);
	}
	c.components += num_different(final_components)-num_different(orig_components);*/
	//map<int, int> rename_vec;
	return c;
}
	
Submatrix unit = unit_matrix();

struct Tree {
	typedef Submatrix T;
	T f(T a, T b) { return merge(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
	int n;
	cin >> n;
	Tree tree(n);
	vector<string> m(3);
	rep(i,0,3) {
#ifdef DEBUG
		rep(j,0,n)
			m[i].push_back((rand()%2) + '0');
#else
		cin >> m[i];
#endif
	}
	rep(j,0,n) {
		Submatrix sm;
		sm.components = 0;
		string s;
		rep(i,0,3) {
			s += m[i][j];
			if (m[i][j] == '1') {
				sm.l[i] = 1;
			} else {
				sm.l[i] = -1;
			}
			sm.r[i] = sm.l[i];
		}
		if (s != "000") {
			sm.components = 1;
		}
		if (s == "101") {
			sm.components = 2;
			sm.l[2] = 2;
			sm.r[2] = 2;
		}
		tree.update(j, sm);
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
#ifdef DEBUG
		r = (rand()%n)+1;
		l = (rand()%r)+1;
#else
		cin >> l >> r;
#endif
		--l;
		Submatrix sm = tree.query(l, r);
		cout << sm.components << endl;
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	solve();
}