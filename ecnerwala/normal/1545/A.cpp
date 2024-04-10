#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N/2);
		vector<int> B(N-N/2);
		auto g = [&](int i) -> int& { return (i & 1 ? A : B)[i/2]; };
		for (int i = 0; i < N; i++) {
			cin >> g(i);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		bool good = true;
		for (int i = 0; i+1 < N; i++) {
			good = good && g(i) <= g(i+1);
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}