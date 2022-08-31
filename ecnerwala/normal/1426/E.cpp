#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;

	std::array<int, 3> A; cin >> A[0] >> A[1] >> A[2];
	std::array<int, 3> B; cin >> B[0] >> B[1] >> B[2];

	// R S P, so 0 beats 1 beats 2 beats 0

	// A wins as many as few as possible
	// N - max flow along non-winning edges
	cout << max({0, A[0] + B[1] - N, A[1] + B[2] - N, A[2] + B[0] - N}) << ' ';

	// max-flow along winning edges
	cout << min(A[0], B[1]) + min(A[1], B[2]) + min(A[2], B[0]) << '\n';

	return 0;
}