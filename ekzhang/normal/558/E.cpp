#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int N, Q;
char S[100005];
int* sts[26]; // 26 segment trees :o
pii* lazys[26]; // with lazy prop too! O.O

void build(int* st, pii* lazy, char c, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) {
		hi = N - 1;
	}
	lazy[node].first = lazy[node].second = -2;
	if (lo == hi) {
		st[node] = (S[lo] == c ? 1 : 0);
		return;
	}
	int mid = (lo + hi) / 2;
	build(st, lazy, c, lo, mid, 2 * node + 1);
	build(st, lazy, c, mid + 1, hi, 2 * node + 2);
	st[node] = st[2 * node + 1] + st[2 * node + 2];
}

void update(int* st, pii* lazy, int s, int e, int x, int y, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) {
		hi = N - 1;
	}
	int mid = (lo + hi) / 2;
	if (lazy[node].first >= 0) {
		st[node] = lazy[node].second - lazy[node].first + 1;
		if (lo != hi) { // is not a leaf
			// we're allowed to just override laziness, since laziness from
			// the parent is "newer"
			lazy[2 * node + 1].first = lazy[node].first;
			lazy[2 * node + 1].second = min(lazy[node].second, mid);
			if (lazy[2 * node + 1].first > lazy[2 * node + 1].second) {
				lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
			}
			lazy[2 * node + 2].first = max(lazy[node].first, mid + 1);
			lazy[2 * node + 2].second = lazy[node].second;
			if (lazy[2 * node + 2].first > lazy[2 * node + 2].second) {
				lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
			}
		}
		lazy[node].first = lazy[node].second = -2;
	}
	if (lazy[node].first == -1) {
		st[node] = 0;
		if (lo != hi) {
			lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
			lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
		}
		lazy[node].first = lazy[node].second = -2;
	}
	if (hi < s || lo > e) {
		return;
	}
	if (lo >= s && hi <= e) {
		st[node] = min(y, hi) - max(x, lo) + 1;
		if (st[node] < 0) {
			st[node] = 0;
			if (lo != hi) {
				lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
				lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
			}
		}
		else {
			if (lo != hi) {
				lazy[2 * node + 1].first = max(x, lo);
				lazy[2 * node + 1].second = min(y, mid);
				if (lazy[2 * node + 1].first > lazy[2 * node + 1].second) {
					lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
				}
				lazy[2 * node + 2].first = max(x, mid + 1);
				lazy[2 * node + 2].second = min(y, hi);
				if (lazy[2 * node + 2].first > lazy[2 * node + 2].second) {
					lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
				}
			}
		}
		return;
	}

	update(st, lazy, s, e, x, y, lo, mid, 2 * node + 1);
	update(st, lazy, s, e, x, y, mid + 1, hi, 2 * node + 2);
	st[node] = st[2 * node + 1] + st[2 * node + 2];
}

int query(int* st, pii* lazy, int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) {
		hi = N - 1;
	}
	if (hi < s || lo > e) {
		return 0;
	}
	int mid = (lo + hi) / 2;
	// copied code for passing down laziness
	if (lazy[node].first >= 0) {
		st[node] = lazy[node].second - lazy[node].first + 1;
		if (lo != hi) { // is not a leaf
			// we're allowed to override laziness, since laziness from
			// the parent is "newer"
			lazy[2 * node + 1].first = lazy[node].first;
			lazy[2 * node + 1].second = min(lazy[node].second, mid);
			if (lazy[2 * node + 1].first > lazy[2 * node + 1].second) {
				lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
			}
			lazy[2 * node + 2].first = max(lazy[node].first, mid + 1);
			lazy[2 * node + 2].second = lazy[node].second;
			if (lazy[2 * node + 2].first > lazy[2 * node + 2].second) {
				lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
			}
		}
		lazy[node].first = lazy[node].second = -2;
	}
	if (lazy[node].first == -1) {
		st[node] = 0;
		if (lo != hi) {
			lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
			lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
		}
		lazy[node].first = lazy[node].second = -2;
	}
	if (lo >= s && hi <= e) {
		return st[node];
	}
	return query(st, lazy, s, e, lo, mid, 2 * node + 1)
			+ query(st, lazy, s, e, mid + 1, hi, 2 * node + 2);
}

void get(int* st, pii* lazy, char c, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) {
		hi = N - 1;
	}
	// copied code for passing down laziness
	int mid = (lo + hi) / 2;
	if (lazy[node].first >= 0) {
		st[node] = lazy[node].second - lazy[node].first + 1;
		if (lo != hi) { // is not a leaf
			// we're allowed to override laziness, since laziness from
			// the parent is "newer"
			lazy[2 * node + 1].first = lazy[node].first;
			lazy[2 * node + 1].second = min(lazy[node].second, mid);
			if (lazy[2 * node + 1].first > lazy[2 * node + 1].second) {
				lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
			}
			lazy[2 * node + 2].first = max(lazy[node].first, mid + 1);
			lazy[2 * node + 2].second = lazy[node].second;
			if (lazy[2 * node + 2].first > lazy[2 * node + 2].second) {
				lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
			}
		}
		lazy[node].first = lazy[node].second = -2;
	}
	if (lazy[node].first == -1) {
		st[node] = 0;
		if (lo != hi) {
			lazy[2 * node + 1].first = lazy[2 * node + 1].second = -1;
			lazy[2 * node + 2].first = lazy[2 * node + 2].second = -1;
		}
		lazy[node].first = lazy[node].second = -2;
	}
	if (st[node] == 0) {
		return;
	}
	if (lo == hi) {
		S[lo] = c;
		return;
	}
	get(st, lazy, c, lo, mid, 2 * node + 1);
	get(st, lazy, c, mid + 1, hi, 2 * node + 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("558E.in", "r", stdin);
	//freopen("558E.out", "w", stdout);

	cin >> N >> Q;
	string s1;
	cin >> s1;
	for (int i = 0; i < N; i++) {
		S[i] = s1[i];
	}

	for (int i = 0; i < 26; i++) {
		sts[i] = new int[262144];
		lazys[i] = new pii[262144];
		build(sts[i], lazys[i], (char) ('a' + i));
	}

	for (int q = 0; q < Q; q++) {
		/*
		for (int i = 0; i < 32; i++) {
			cout << sts[0][i] << sts[1][i] << sts[2][i] << sts[3][i] << endl;
		}
		*/
		int a, b, res;
		cin >> a >> b >> res;
		a--;b--;
		cerr << a << ' ' << b << ' ' << res << endl;
		if (res == 1) {
			int curr = a;
			for (int i = 0; i < 26; i++) {
				int amt = query(sts[i], lazys[i], a, b);
				//cerr << amt;
				if (amt != 0) {
					update(sts[i], lazys[i], a, b, curr, curr + amt - 1);
					curr += amt;
				}
			}
			//cerr << endl;
			/*
			if (curr != b + 1) {
				cerr << "ERROR: curr is at the end of loop: " << curr << " :instead of: " << b + 1 << endl;
			}
			*/
		}
		else {
			int curr = b;
			for (int i = 0; i < 26; i++) {
				int amt = query(sts[i], lazys[i], a, b);
				if (amt != 0) {
					update(sts[i], lazys[i], a, b, curr - amt + 1, curr);
					curr -= amt;
				}
			}
			/*
			if (curr != a - 1) {
				cerr << "ERROR: curr is at the end of loop: " << curr << " :instead of: " << a - 1 << endl;
			}
			*/
		}
	}

	for (int i = 0; i < 26; i++) {
		get(sts[i], lazys[i], 'a' + i);
	}

	for (int i = 0; i < N; i++) {
		cout << S[i];
	}
	cout << endl;
	return 0;
}