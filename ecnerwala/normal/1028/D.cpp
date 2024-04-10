#include<bits/stdc++.h>
using namespace std;

const int MOD = int(1e9) + 7;

[[ noreturn ]] void FAIL() {
	cout << 0 << '\n';
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	int Q;
	cin >> Q;
	using iter = set<int>::iterator;
	set<int> book;
	// half-open interval of all things that could be a sell
	iter l = book.begin();
	iter r = book.end();

	long long res = 1;

	for (int q = 0; q < Q; q++) {
		string op; int p; cin >> op >> p;
		if (op == "ACCEPT") {
			if (!book.count(p)) FAIL();
			iter f = book.find(p);
			assert(f != book.end());
			assert(*f == p);
			iter nf = f;
			nf ++;
			if (nf == l) {
				res *= 1, res %= MOD;
			} else if (f == r) {
				res *= 1, res %= MOD;
			} else if ((l != book.end() && *l <= *f) && (r == book.end() || *f < *r)) {
				res *= 2, res %= MOD;
			} else {
				FAIL();
			}
			// remove f
			r = book.erase(f);
			l = r;
		} else if (op == "ADD") {
			// insert this guy
			if (book.count(p)) FAIL();
			iter f = book.insert(p).first;
			f++;
			if (f == l) {
				l--;
			}
		} else assert(false);
	}
	// now take care of all remaining cases
	int cntsell = 0;
	while (l != r) {
		l++;
		cntsell++;
	}
	res *= cntsell + 1, res %= MOD;
	cout << res << '\n';
	return 0;
}