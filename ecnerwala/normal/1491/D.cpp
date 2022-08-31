#include <bits/stdc++.h>

bool has_path(int u, int v) {
	if (u > v) return false;
	if (u == v) return true;
	if (__builtin_popcount(v) > __builtin_popcount(u)) return false;

	while (true) {
		int L = 31 - __builtin_clz(v);
		assert(v & (1 << L));
		if (u & (1 << L)) {
			u -= (1 << L);
			v -= (1 << L);
		} else {
			break;
		}
	}
	assert(__builtin_popcount(u) >= __builtin_popcount(v));
	while (v) {
		if (__builtin_ctz(u) > __builtin_ctz(v)) {
			return false;
		}
		v &= v-1;
		u &= u-1;
	}
	return true;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int Q; cin >> Q;
	while (Q--) {
		int U, V; cin >> U >> V;
		cout << (has_path(U, V) ? "YES" : "NO") << '\n';
	}

	return 0;
}