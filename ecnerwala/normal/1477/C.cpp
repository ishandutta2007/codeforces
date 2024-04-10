#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<array<int, 2>> A(N);
	for (auto& a : A) cin >> a[0] >> a[1];
	auto is_okay = [&](array<int, 2> a, array<int, 2> b, array<int, 2> c) -> bool {
		return int64_t(c[0] - b[0]) * int64_t(a[0] - b[0]) + int64_t(c[1] - b[1]) * int64_t(a[1] - b[1]) > 0;
	};
	vector<int> P; P.reserve(N);
	P.push_back(0);
	P.push_back(1);
	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= int(P.size()); j++) {
			if ((j < 2 || is_okay(A[P[j-2]], A[P[j-1]], A[i])) && (j-1 < 0 || j >= int(P.size()) || is_okay(A[P[j-1]], A[i], A[P[j]])) && (j+1 >= int(P.size()) || is_okay(A[i], A[P[j]], A[P[j+1]]))) {
				P.insert(P.begin()+j, i);
				break;
			}
		}
		if (int(P.size()) != i+1) {
			cout << -1 << '\n';
			exit(0);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << P[i]+1 << " \n"[i+1==N];
	}
	return 0;
}