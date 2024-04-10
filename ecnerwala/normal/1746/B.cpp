#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N); for (auto& a : A) cin >> a;
		int ans = 0;
		for (int i = 0, j = N-1; i <= j; ) {
			if (A[i] == 0) i++;
			else if (A[j] == 1) j--;
			else {
				ans++;
				i++, j--;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}