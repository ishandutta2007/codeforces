//MIPT Cryptozoology
//Room 202
#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <bitset>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define itn int

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef YA
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
	cin.tie(0);
#endif
	//cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef YA
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

inline int nxt(){
	int x;
	cin >> x;
	return x;
}

#define int li

const int shift = 1 << 18;

struct SegTree{

	struct Node {
		int mn;
		int push_add;
	};

	Node tree[2 * shift];

	void push(int v) {
		for (int h = 0; h < 2; ++h) {
			tree[2 * v + h].push_add += tree[v].push_add;
			tree[2 * v + h].mn += tree[v].push_add;
		}
		tree[v].push_add = 0;
	}

	Node merge(const Node& l, const Node& r) {
		Node res;
		res.push_add = 0;
		res.mn = min(l.mn, r.mn);
		return res;
	}

	Node rmq(int v, int tl, int tr, int l, int r) {
		if (tr <= l || r <= tl) {
			return{ (li)1e18, 0LL };
		}
		if (l <= tl && tr <= r) {
			return tree[v];
		}
		push(v);
		int tm = (tl + tr) / 2;
		Node ans = merge(rmq(2 * v, tl, tm, l, r), rmq(2 * v + 1, tm, tr, l, r));
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
		return ans;
	}


	Node get_min(int l, int r) {
		return rmq(1, 0, shift, l, r);
	}

	void modify(int v, int tl, int tr, int l, int r, int val) {
		if (tr <= l || r <= tl) {
			return;
		}
		if (l <= tl && tr <= r) {
			tree[v].push_add += val;
			tree[v].mn += val;
			return;
		}
		push(v);
		int tm = (tl + tr) / 2;
		modify(2 * v, tl, tm, l, r, val);
		modify(2 * v + 1, tm, tr, l, r, val);
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}

	void update(int l, int r, int val) {
		return modify(1, 0, shift, l, r, val);
	}

	void build(int v, int tl, int tr, const vector<int>& vals) {
		if (tl >= vals.size()) {
			return;
		}
		if (tl + 1 == tr) {
			tree[v].mn = vals[tl];
			tree[v].push_add = 0;
			return;
		}
		int tm = (tl + tr) / 2;
		build(2 * v, tl, tm, vals);
		build(2 * v + 1, tm, tr, vals);
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}

	void build(const vector<int>& vals) {
		return build(1, 0, shift, vals);
	}
};

vector<SegTree> tree(2);

void use(int r, int k) {
	tree[0].update(0, (r + 1) / 2, k);
	if (r & 1) {
		tree[1].update(r / 2, shift, -k);
		tree[0].update((r + 1) / 2, shift, k);
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	set<int> bad;
	vector<int> c;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		c.push_back(a[i]);
		if (a[i] == -1) {
			bad.insert(i);
		}
	}

	for (int i = 1; i < a.size(); ++i) {
		a[i] -= a[i - 1];
	}
	for (int start = 0; start < 2; ++start) {
		vector<int> b;
		for (int i = start; i < a.size(); i += 2) {
			b.push_back(a[i]);
		}
		tree[start].build(b);
	}
	bool stress = false;

	int Q;
	cin >> Q;
	while (Q--) {
		int type;
		int l, r;
		cin >> type >> l >> r;
		++r;
		if (type == 1) {
			int k;
			cin >> k;
			if (stress) {
				for (int i = l; i < r; ++i) {
					c[i] += k;
				}
			}
			use(r, k);
			use(l, -k);
			if (k > 0) {
				auto it = bad.lower_bound(l);
				while (it != bad.end() && *it < r) {
					auto nex = it;
					++nex;
					bad.erase(it);
					it = nex;
				}
			}
		}
		else {
			/*int cur = 0;
			for (int i = l; i < r; ++i) {
				cur = c[i] - cur;
				if (cur < 0) {
					cur_res = 
				}
			}*/

			auto it = bad.lower_bound(l);
			if (it != bad.end() && *it < r) {
				cout << "0\n";
				continue;
			}
			int pref = l ? tree[!(l & 1)].get_min((l - 1) / 2, (l - 1) / 2 + 1).mn : 0;
			int tl = l / 2, tr = r / 2;
			if (r % 2 == 1 && l % 2 == 0) {
				++tr;
			}
			int cur_min = tree[l & 1].get_min(tl, tr).mn;
			if (cur_min + pref < 0) {
				cout << "0\n";
				continue;
			}
			tl = (l + 1) / 2;
			tr = r / 2;
			if (r % 2 == 1 && l % 2 == 1) {
				++tr;
			}
			cur_min = tree[!(l & 1)].get_min(tl, tr).mn;
			if (cur_min - pref < 0) {
				cout << "0\n";
				continue;
			}
			if (tree[!(r & 1)].get_min((r - 1) / 2, (r - 1) / 2 + 1).mn != pref * ((l % 2 == r % 2) ? 1 : -1)) {
				cout << "0\n";
				continue;
			}
			cout << "1\n";
		}
	}

}