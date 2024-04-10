#include<bits/stdc++.h>

int64_t minv(int64_t a, int64_t m) {
	assert(0 < a && a < m);
	if (a == 1) return 1;
	return m - minv(m % a, a) * m / a;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	if (N == 1) {
		cout << 1 << ' ' << 1 << '\n' << -A[0] << '\n';
		cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
		cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
		exit(0);
	}

	int64_t invNm1 = minv(N-1, N);
	assert(invNm1 * (N-1) % N == 1);

	vector<int64_t> op1(N);
	vector<int64_t> op2(N-1);
	for (int i = 0; i < N-1; i++) {
		op2[i] = -A[i] % N * invNm1 % N;
		assert((A[i] + (op2[i] * (N-1))) % N == 0);
		op1[i] = -(A[i] + (op2[i] * (N-1))) / N;
		assert(A[i] + (op1[i] * N) + (op2[i] * (N-1)) == 0);
	}

	cout << 1 << ' ' << N << '\n';
	for (int i = 0; i < N; i++) {
		cout << op1[i] * N << " \n"[i+1==N];
	}
	cout << 1 << ' ' << N-1 << '\n';
	for (int i = 0; i < N-1; i++) {
		cout << op2[i] * (N-1) << " \n"[i+1==N-1];
	}

	cout << N << ' ' << N << '\n';
	cout << -A[N-1] << '\n';

	return 0;
}