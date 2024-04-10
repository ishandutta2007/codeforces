#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N);
		for (auto& a : A) cin >> a;
		cout << std::max_element(A.begin(), A.end()) - A.begin() + 1 << ' ';
		cout << std::min_element(A.begin(), A.end()) - A.begin() + 1 << '\n';
	}

	return 0;
}