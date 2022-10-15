// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  Codeforces Round #423 (Div. 1)  |
+----------------------------------+
|             Problem C            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(chrono::system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

class FenwickTree {
private:
	int n;
	vector<int64_t> a;
public:
	inline void add(int v, int64_t delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
	
	inline int64_t sum(int v) {
		int64_t res = 0;
		for (; v >= 0; v &= v+1, v--) {
			res += a[v];
		}
		return res;
	}
	
	inline int64_t sum(int l, int r) {
		return sum(r) - sum(l-1);
	}
	
	FenwickTree(int n)
		: n(n), a(n, 0) {
	}
	
	FenwickTree() {
	}
};

inline int let2num(char c) {
	if (c == 'A') {
		return 0;
	} else if (c == 'C') {
		return 1;
	} else if (c == 'T') {
		return 2;
	} else if (c == 'G') {
		return 3;
	} else {
		raiseError("Hello, I am a bug in your test! :)");
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	string s; cin >> s;
	int len = s.size();
	vector<int> v;
	for (char c : s) {
		v.push_back(let2num(c));
	}
	static FenwickTree trees[11][11][4];
	
	auto add = [&](int pos, int letter, int delta) {
		for (int i = 1; i <= 10; i++) {
			trees[i][pos % i][letter].add(pos / i, delta);
		}
	};
	
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < 4; k++) {
				trees[i][j][k] = FenwickTree(len/i + 128);
			}
		}
	}
	
	for (int i = 0; i < len; i++) {
		add(i, v[i], +1);
	}
	
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int qt; cin >> qt;
		if (qt == 1) {
			int x; char c; cin >> x >> c; x--;
			add(x, v[x], -1);
			v[x] = let2num(c);
			add(x, v[x], +1);
		} else {
			int l, r; string e; cin >> l >> r >> e; l--; r--;
			int elen = e.size();
			int res = 0;
			for (int j = 0; j < elen; j++) {
				int jpos = (j + l) % elen;
				int ql = (l + elen - jpos - 1) / elen;
				int qr = (r - jpos) / elen;
				if (r - jpos < 0) {
					qr = -1;
				}
				res += trees[elen][jpos][let2num(e[j])].sum(ql, qr);
			}
			cout << res << "\n";
		}
	}
	
	return 0;
}