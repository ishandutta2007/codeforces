#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<int> A(N);
	array<int, 2> cnt{0,0};
	for (auto& a : A) { cin >> a; cnt[a]++; }

	while (Q--) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x; x--;
			cnt[A[x]]--;
			A[x] = 1 - A[x];
			cnt[A[x]]++;
		} else if (t == 2) {
			int k; cin >> k;
			cout << (k <= cnt[1] ? 1 : 0) << '\n';
		}
	}

	return 0;
}