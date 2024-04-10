#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) cin >> a;
	A.insert(A.begin(), 0);
	A.push_back(0);

	vector<int> stack;
	vector<array<int, 2>> ops;
	for (int i = 1; i <= N+1; i++) {
		if (A[i] > A[i-1]) {
			for (int z = A[i] - A[i-1]; z--; ) {
				stack.push_back(i);
			}
		} else {
			for (int z = A[i-1] - A[i]; z--; ) {
				ops.push_back({stack.back(), i-1});
				stack.pop_back();
			}
		}
	}
	cout << ops.size() << '\n';
	for (auto it : ops) cout << it[0] << ' ' << it[1] << '\n';

	return 0;
}