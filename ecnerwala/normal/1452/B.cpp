#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (auto& a : A) cin >> a;
		int64_t tot = std::accumulate(A.begin(), A.end(), int64_t(0));
		int64_t need = max((tot + N-2)/(N-1), int64_t(*max_element(A.begin(), A.end()))) * (N-1);
		cout << need - tot << '\n';
	}

	return 0;
}