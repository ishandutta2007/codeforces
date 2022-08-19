#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) { cin >> a; a--; }
		std::vector<int> B(N);
		for (auto& a : B) { cin >> a; a--; }

		bool good = true;
		std::vector<bool> seen(N);
		std::vector<int> cnt(N);
		int i, j;
		for (i = N-1, j = N-1; i >= 0; ) {
			int va = A[i];
			int cnt_a = 0;
			while (i >= 0 && A[i] == va) i--, cnt_a++;
			while (j >= 0 && B[j] == va) j--, cnt[va]++;
			cnt[va] -= cnt_a;
			if (cnt[va] < 0) {
				good = false;
				break;
			}
		}
		if (j > 0) good = false;
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}