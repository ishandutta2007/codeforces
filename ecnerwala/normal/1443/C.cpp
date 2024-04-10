#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<pair<int, int>> A(N);
		for (auto& a : A) cin >> a.first;
		for (auto& a : A) cin >> a.second;
		sort(A.begin(), A.end());

		int suff = 0;
		for (int i = N-1; true; i--) {
			suff += A[i].second;
			if (!i || suff >= A[i-1].first) {
				cout << min(A[i].first, suff) << '\n';
				break;
			}
		}
	}

	return 0;
}