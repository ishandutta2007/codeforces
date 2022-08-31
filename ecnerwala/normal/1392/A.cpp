#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) cin >> a;
		if (*min_element(A.begin(), A.end()) == *max_element(A.begin(), A.end())) {
			cout << N << '\n';
		} else {
			cout << 1 << '\n';
		}
	}

	return 0;
}