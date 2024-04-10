#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int H, G; cin >> H >> G;
		int N = (1<<H);
		int M = (1<<G);
		vector<int> A(N);
		for (int i = 1; i < N; i++) {
			cin >> A[i];
		}
		i64 ans = 0;
		vector<int> ops; ops.reserve(N-M);
		vector<vector<int>> vals(N);
		for (int i = 1; i < N; i++) {
			vals[i].reserve(1<<(__builtin_clz(i) - __builtin_clz(N)));
			vals[i].push_back(A[i]);
		}

		for (int i = N - 1; i >= 1; i--) {
			if (2 * i < N) {
				auto ast = vals[2*i].begin();
				auto aen = vals[2*i].end(); --aen;
				auto bst = vals[2*i+1].begin();
				auto ben = vals[2*i+1].end(); --ben;
				int lim = max(*aen, *ben);
				while (true) {
					int cur = max(*ast, *bst);
					if (cur <= lim) {
						while (ast != aen) {
							ops.push_back(2*i);
							++ast;
						}
						while (bst != ben) {
							ops.push_back(2*i+1);
							++bst;
						}
						break;
					}
					assert(*ast != *bst);
					if (*ast == cur) {
						vals[i].push_back(*ast);
						++ast;
					} else if (*bst == cur) {
						vals[i].push_back(*bst);
						++bst;
					} else assert(false);
				}
			}

			if (i >= M) {
				// you're allowed to be empty
				vals[i].push_back(0);
			}

			ans += vals[i].back();
		}

		auto st = vals[1].begin();
		auto en = vals[1].end(); --en;
		while (st != en) {
			ops.push_back(1);
			++st;
		}

		assert(int(ops.size()) == N-M);
		reverse(ops.begin(), ops.end());
		cout << ans << '\n';
		for (int i = 0; i < N-M; i++) {
			cout << ops[i] << " \n"[i+1==N-M];
		}
	}

	return 0;
}