#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) cin >> a;

		vector<int> prv(N); iota(prv.begin(), prv.end(), -1); prv[0] = N-1;
		vector<int> nxt(N); iota(nxt.begin(), nxt.end(), 1); nxt[N-1] = 0;

		set<int> to_delete;
		for (int i = 0; i < N; i++) {
			if (std::gcd(A[prv[i]], A[i]) == 1) {
				to_delete.insert(i);
			}
		}

		vector<int> ans; ans.reserve(N);

		for (int cur_pos = 0; int(ans.size()) < N && !to_delete.empty(); ) {
			auto it = to_delete.upper_bound(cur_pos);
			if (it == to_delete.end()) it = to_delete.begin();
			int i = *it;
			ans.push_back(i);
			to_delete.erase(i);

			int p = prv[i];
			int n = nxt[i];
			if (n == i) break;

			to_delete.erase(n);
			nxt[p] = n;
			prv[n] = p;
			if (std::gcd(A[p], A[n]) == 1) to_delete.insert(n);

			cur_pos = n;
		}

		cout << ans.size(); for (int v : ans) { cout << ' ' << v+1; } cout << '\n';
	}

	return 0;
}