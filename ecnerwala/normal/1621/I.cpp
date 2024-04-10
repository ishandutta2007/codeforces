#include <bits/stdc++.h>

std::vector<int> op(const std::vector<int>& A) {
	int N = int(A.size());

	int L = 0; // size of the current stack
	std::vector<int> cur_string(N);
	std::vector<int> border(N+1);
	std::vector<int> final_cut(N+1); // length and total length of the final cut

	border[0] = -1;

	std::vector<bool> is_single(N+1);
	for (int v = A[0], i = 0; i < N; i++) {
		if (A[i] <= v) {
			is_single[i] = true;
			v = A[i];
		}
	}
	is_single[N] = true;
	for (int i = N-1; i > 0; i--) {
		if (!is_single[i+1] && is_single[i] && A[i-1] == A[i]) is_single[i] = false;
	}

	std::vector<int> B; B.reserve(N);

	for (int i = 0; i < N; i++) {
		// insert A[i]
		int v = A[i];
		while (L > 0 && v < cur_string[border[L]]) {
			L %= (L - border[L]);
		}
		cur_string[L] = v;
		if (L == 0 || v == cur_string[border[L]]) {
			border[L+1] = border[L]+1;
		} else {
			border[L+1] = 0;
		}
		L++;

		{
			int nsz = L % (L - border[L]);
			if (nsz == 0) {
				final_cut[L] = L;
			} else {
				final_cut[L] = final_cut[nsz];
			}
		}
		{
			int l = final_cut[L];
			if (is_single[i+1]) l -= border[l];
			for (int j = i - l + 1; j <= i; j++) {
				B.push_back(A[j]);
				if (int(B.size()) == N) goto done;
			}
		}
	}

	assert(false);
done:
	return B;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> A(N);
	for (auto& a : A) cin >> a;

	std::vector<std::vector<int>> As; As.reserve(30);
	As.emplace_back(A);
	do {
		As.emplace_back(op(As.back()));
	} while (As.end()[-2] != As.end()[-1]);

	int Q; cin >> Q;
	while (Q--) {
		int i, j; cin >> i >> j; j--;
		i = std::min(i, int(As.size())-1);
		cout << As[i][j] << '\n';
	}

	return 0;
}