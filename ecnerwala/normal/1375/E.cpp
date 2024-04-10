#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first; A[i].second = i;
	}
	sort(A.begin(), A.end());

	vector<pair<int, int>> ops; ops.reserve(N*(N-1) / 2);
	for (int z = 0; z < N; z++) {
		for (int i = 0; i+1 < N; i++) {
			if (A[i].second > A[i+1].second) {
				swap(A[i].second, A[i+1].second);
				ops.emplace_back(A[i].second, A[i+1].second);
			}
		}
	}
	cout << ops.size() << '\n';
	for (auto it : ops) {
		cout << it.first+1 << ' ' << it.second+1 << '\n';
	}

	return 0;
}