#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int64_t A, B, N; cin >> A >> B >> N;
		int ans = 0;
		while (max(A,B) <= N) {
			if (A > B) swap(A, B);
			A += B;
			ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}