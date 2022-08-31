#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<array<int, 5>> A(N);
		for (auto& a : A) for (auto& v : a) cin >> v;
		auto cmp = [](const array<int, 5>& a, const array<int, 5>& b) {
			return (a[0] < b[0]) + (a[1] < b[1]) + (a[2] < b[2]) + (a[3] < b[3]) + (a[4] < b[4]) >= 3;
		};
		int cur = 0;
		for (int i = 1; i < N; i++) if (cmp(A[i], A[cur])) cur = i;
		for (int i = 0; i < N; i++) {
			if (i == cur) continue;
			if (!cmp(A[cur], A[i])) {
				cur = -2;
				break;
			}
		}
		cout << cur+1 << '\n';
	}

	return 0;
}