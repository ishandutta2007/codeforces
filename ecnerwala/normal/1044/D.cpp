#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int MAXN = 3e5;
int N;
unordered_map<int, pii> par;

pii getPar(int i) {
	if (!par.count(i)) {
		return pii(i, 0);
	}
	int p = par[i].first;
	pii res = getPar(p);
	res.second ^= par[i].second;
	return par[i] = res;
}

void merge(int i, int j, int x) {
	pii pi = getPar(i);
	pii pj = getPar(j);
	if (pi.first == pj.first) {
		// just skip
		return;
	}

	assert(!par.count(pi.first));
	assert(!par.count(pj.first));

	par[pi.first] = pii(pj.first, pi.second ^ pj.second ^ x);
}

int query(int i, int j) {
	pii pi = getPar(i);
	pii pj = getPar(j);
	if (pi.first == pj.first) {
		return pi.second ^ pj.second;
	} else {
		return -1;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	int last = 0;
	for (int i = 0; i < Q; i++) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, x; cin >> l >> r >> x;
			l ^= last;
			r ^= last;
			x ^= last;
			if (l > r) swap(l, r);
			r++;
			//cerr << "Merge " << l << ' ' << r << ' ' << x << '\n';
			merge(l, r, x);
		} else if (t == 2) {
			int l, r; cin >> l >> r;
			l ^= last;
			r ^= last;
			if (l > r) swap(l, r);
			r++;
			int x = query(l, r);
			//cerr << "Query " << l << ' ' << r << ' ' << x << '\n';
			cout << x << '\n';
			if (x == -1) last = 1;
			else last = x;
		} else assert(false);
	}

	return 0;
}