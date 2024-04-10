#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int64_t X; cin >> X;

	struct op_t {
		int64_t a, b;
		char v;
	};
	vector<op_t> ops; ops.reserve(1e5);

	while (X > 1) {
		int L = (63 - __builtin_clzll(X));
		assert(X & (1ll << L));
		for (int i = 0; i < L; i++) {
			ops.push_back({X << i, X << i, '+'});
		}
		int64_t a = X << L;
		ops.push_back({a, X, '^'});
		int64_t b = a ^ X;

		for (int i = 0; i <= L; i++) {
			if (b & (1ll << i)) {
				ops.push_back({a, (X << i), '+'});
				ops.push_back({b, (X << i), '+'});
				a += (X << i);
				b += (X << i);
			}
			assert(!(b & (1ll << i)));
		}
		ops.push_back({a, b, '^'});
		int64_t nx = a ^ b;
		assert(nx != 0);
		assert(__builtin_clzll(nx) >= __builtin_clzll(X));
		X = nx;
	}

	cout << ops.size() << '\n';
	for (auto op : ops) {
		cout << op.a << ' ' << op.v << ' ' << op.b << '\n';
	}

	return 0;
}