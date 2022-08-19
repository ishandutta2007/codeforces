#include<bits/stdc++.h>
using namespace std;

unsigned int myrand() {
	static unsigned seed = 1;
	seed = (seed * 1103515245 + 12345) & (0x7FFFFFFF);
	return seed;
}

typedef long long ll;

int U, V;
int P;

ll inv(ll a, ll m) {
	return a == 1 ? 1 : m - inv(m % a, a) * m / a;
}

int do_op(int u, int c) {
	if (c == 0) {
		return (u == (P - 1)) ? 0 : u + 1;
	} else if (c == 1) {
		return (u == 0) ? P-1 : u-1;
	} else if (c == 2) {
		if (u == 0) return 0;
		return int(inv(u, P));
	} else assert(false);
}

int inv_op(int c) {
	if (c == 0) {
		return 1;
	} else if (c == 1) {
		return 0;
	} else if (c == 2) {
		return 2;
	} else assert(false);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> U >> V >> P;

	assert(0 <= U && U < P);
	assert(0 <= V && V < P);

	while(true) {
		unordered_map<int, int> nxt;

		vector<int> vals;
		for (int i = 0; i < int(1e4); i++) {
			vals.push_back(V);
		}
		nxt[V] = -1;

		for (int z = 0; z < 100; z++) {
			vector<int> nvals;
			for (int i : vals) {
				for (int c = 0; c < 3; c++) {
					int n = do_op(i, c);
					if (nxt.count(n)) continue;
					nxt[n] = inv_op(c);
				}
				nvals.push_back(do_op(i, myrand() % 3));
			}
			swap(vals, nvals);
		}

		cerr << "finished backwards\n";

		unordered_map<int, int> prv;

		vals.clear();
		for (int i = 0; i < int(1e4); i++) {
			vals.push_back(U);
		}
		prv[U] = -1;

		for (int z = 0; z < 100; z++) {
			vector<int> nvals;
			for (int i : vals) {
				for (int c = 0; c < 3; c++) {
					int n = do_op(i, c);
					if (prv.count(n)) continue;
					prv[n] = c;
					assert(do_op(n, inv_op(prv[n])) == i);
					if (nxt.count(n)) {
						cerr << "meetmid is " << n << '\n';
						vector<int> res;
						for (int cur = n; cur != U; ) {
							int c = prv[cur];
							res.push_back(c);
							cur = do_op(cur, inv_op(c));
						}
						reverse(res.begin(), res.end());
						for (int cur = n; cur != V; ) {
							int c = nxt[cur];
							res.push_back(c);
							cur = do_op(cur, c);
						}
						cout << res.size() << '\n';
						for (int it : res) {
							cout << it + 1 << ' ';
						}
						cout << '\n';
						return 0;
					}
				}
				nvals.push_back(do_op(i, myrand() % 3));
			}
			swap(vals, nvals);
		}
		cerr << "Failed run\n";
	}

	return 0;
}