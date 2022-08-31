#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M, T, W; cin >> N >> M >> T >> W;
	T = std::min(T, 1 << __builtin_ctz(N));
	int L = 0;
	while ((1 << L) < std::max(T+1, N)) L++;
	int S = (1 << L);

	std::vector<int> seg(2*S);
	for (int i = 0; i < S; i++) {
		seg[S+i] = i < N ? -1 : 0;
	}

	int num_extra = 0;
	int num_bad = 0;

	auto update_node = [&](int l, int i, int d) {
		int x = seg[(2 << l) + i];
		int y = seg[(3 << l) + i];
		int& z = seg[(1 << l) + i];
		if ((T >> l) & 1) {
			if (x == -1 || y == -1 || x == y) {
				// -1 and with anything to get anything
				z = x & y;
				// no extra, cause they're required equal
			} else {
				z = 0;
				num_bad += d;
			}
		} else {
			if (x == -1 || y == -1) {
				z = -1;
				if (x == -1 && y == -1) {
					num_extra += d;
				}
			} else {
				z = x ^ y;
			}
		}
	};

	for (int l = L-1; l >= 0; l--) {
		for (int i = 0; i < (1 << l); i++) {
			update_node(l, i, +1);
		}
	}

	auto set_val = [&]() {
		int pos, val; cin >> pos >> val; pos--;
		for (int l = L-1; l >= 0; l--) {
			update_node(l, pos & ((1 << l) - 1), -1);
		}
		seg[S+pos] = val;
		for (int l = L-1; l >= 0; l--) {
			update_node(l, pos & ((1 << l) - 1), +1);
		}
	};

	while (M--) set_val();

	int Q; cin >> Q;
	while (Q--) {
		set_val();

		int p; cin >> p;
		if (num_bad > 0) {
			cout << 0 << '\n';
		} else {
			int e = num_extra + (seg[1] == -1);
			int64_t r = 1;
			int64_t a = (1 << W) % p;
			for (; e; e >>= 1) {
				if (e & 1) { r *= a, r %= p; }
				a *= a, a %= p;
			}
			cout << r << '\n';
		}
	}

	return 0;
}