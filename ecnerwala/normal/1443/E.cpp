#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, Q; cin >> N >> Q;
	vector<int> A(N); iota(A.begin(), A.end(), 1);
	vector<int64_t> pref(N+1);
	for (int i = 0; i < N; i++) pref[i+1] = pref[i] + A[i];

	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int l, r; cin >> l >> r; l--;
			cout << pref[r] - pref[l] << '\n';
		} else if (op == 2) {
			int x; cin >> x;
			int first_changed = N;
			while (x > 0) {
				int fact = 1;
				int len = 1;
				while (len+1 <= N && fact * (len+1) - 1 <= x && A[N-len-1] < A[N-len]) {
					fact *= ++len;
				}
				if (len == 1) {
					// we just run next_permutation
					x--;

					int i = N-1;
					while (A[i-1] > A[i]) i--;
					assert(A[i-1] < A[i]);
					int j = N-1;
					while (A[i-1] > A[j]) j--;
					assert(j >= i);
					assert(A[i-1] < A[j]);
					swap(A[i-1], A[j]);
					reverse(A.begin()+i, A.end());
					first_changed = min(first_changed, i-1);
				} else {
					assert(fact-1 > 0);
					x -= fact-1;

					reverse(A.end()-len, A.end());
					first_changed = min(first_changed, N-len);
				}
			}
			for (int i = first_changed; i < N; i++) pref[i+1] = pref[i] + A[i];
		} else assert(false);
	}

	return 0;
}