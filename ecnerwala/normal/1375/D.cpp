#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) cin >> A[i];
		vector<bool> has(N+1);
		vector<int> ops; ops.reserve(2*N);
		while (N) {
			for (int i = 0; i <= N; i++) { has[i] = false; }
			for (int i = 0; i < N; i++) { has[A[i]] = true; }
			int x = 0; while (has[x]) x++;
			if (x == N) {
				ops.push_back(N-1);
				A[N-1] = x;
				N--;
			} else {
				ops.push_back(x);
				A[x] = x;
			}
		}
		cout << ops.size() << '\n';
		for (int z = 0; z < int(ops.size()); z++) {
			cout << ops[z]+1 << " \n"[z+1==int(ops.size())];
		}
	}

	return 0;
}