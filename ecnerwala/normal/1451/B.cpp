#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, Q; cin >> N >> Q;
		string S; cin >> S;
		array<int, 2> first_char{N,N};
		array<int, 2> last_char{N,N};
		for (int i = 0; i < N; i++) {
			int v = S[i] - '0';
			if (first_char[v] == N) first_char[v] = i;
			last_char[v] = i;
		}
		while (Q--) {
			int l, r; cin >> l >> r; l--, r--;
			if (l == first_char[S[l] - '0'] && r == last_char[S[r] - '0']) {
				cout << "NO" << '\n';
			} else {
				cout << "YES" << '\n';
			}
		}
	}

	return 0;
}