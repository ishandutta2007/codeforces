#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<vector<uint64_t>> B(64);
	for (int i = 0; i < N; i++) {
		uint64_t b; cin >> b;
		B[63 - __builtin_clzll(b)].push_back(b);
	}

	vector<uint64_t> ans; ans.reserve(N);

	uint64_t alive_B = 0;
	for (int l = 0; l < 64; l++) {
		if (!B[l].empty()) alive_B |= uint64_t(1) << l;
	}

	uint64_t v = 0;
	for (int i = 0; i < N; i++) {
		uint64_t m = ~v & alive_B;
		if (!m) {
			cout << "No" << '\n';
			exit(0);
		}
		int l = __builtin_ctzll(m);
		v ^= B[l].back();
		ans.push_back(B[l].back());
		B[l].pop_back();
		if (B[l].empty()) alive_B ^= uint64_t(1) << l;
	}

	cout << "Yes" << '\n';
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " \n"[i+1==N];
	}

	return 0;
}

// if it's increasing, that means the highest set bit of the next b_i always is 0
// we can group the b_i by the highest set bit
//
// these must form a binary tree