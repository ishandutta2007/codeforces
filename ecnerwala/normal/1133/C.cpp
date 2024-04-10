#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	std::vector<int> A(N);
	for (auto& a : A) cin >> a;
	std::sort(A.begin(), A.end());
	int ans = 0;
	for (int l = 0, r = 0; r < N; ) {
		if (A[r] - A[l] <= 5) {
			ans = std::max(ans, r - l + 1);
			r++;
		} else {
			l++;
		}
	}

	cout << ans << '\n';
	return 0;
}