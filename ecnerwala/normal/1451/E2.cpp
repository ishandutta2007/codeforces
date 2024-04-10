#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> xor0(N);
	for (int i = 1; i < N; i++) {
		cout << "XOR" << ' ' << 0+1 << ' ' << i+1 << '\n' << flush;
		cin >> xor0[i];
	}

	int v0 = 0;

	vector<int> seen_ind(N, -1);
	for (int i = 0; i < N; i++) {
		if (seen_ind[xor0[i]] == -1) {
			seen_ind[xor0[i]] = i;
		} else {
			int j = seen_ind[xor0[i]];
			cout << "AND" << ' ' << j+1 << ' ' << i+1 << '\n' << flush;
			int v; cin >> v;
			v0 = v ^ xor0[i];
			goto finish;
		}
	}

	// it's a permutation
	for (int i = 1; i < N; i++) {
		if (xor0[i] == 1) {
			cout << "AND" << ' ' << 0+1 << ' ' << i+1 << '\n' << flush;
			int v; cin >> v;
			v &= ~1;
			v0 |= v;
		}
	}
	for (int i = 1; i < N; i++) {
		if ((xor0[i] & 1) == 0) {
			cout << "AND" << ' ' << 0+1 << ' ' << i+1 << '\n' << flush;
			int v; cin >> v;
			v &= 1;
			v0 |= v;
			break;
		}
	}

finish:
	cout << '!';
	for (int i = 0; i < N; i++) {
		cout << ' ' << (v0 ^ xor0[i]);
	}
	cout << '\n' << flush;

	return 0;
}

// xor 0 i for all i=1..n-1
// + 2 queries to identify bits of 0