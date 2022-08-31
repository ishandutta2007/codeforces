#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int N;
long long B[MAXN];
long long A[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N; assert(N >= 2);
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	bool all0 = true;
	for (int i = 0; i < N; i++) {
		if (B[i] != 0) {
			all0 = false;
			break;
		}
	}
	if (all0) {
		cout << "YES" << '\n';
		for (int i = 0; i < N; i++) {
			cout << 1 << " \n"[i == N-1];
		}
		return 0;
	}
	bool allEq = true;
	for (int i = 1; i < N; i++) {
		if (B[i] != B[i-1]) {
			allEq = false;
			break;
		}
	}
	if (allEq) {
		cout << "NO" << '\n';
		return 0;
	}

	long long ma = B[0];
	for (int i = 1; i < N; i++) {
		ma = max(ma, B[i]);
	}
	assert(ma > 0);
	for (int i = 0; i < N; i++) {
		if (B[i] == ma && B[(i+N-1)%N] != ma) {
			assert(B[(i+N-1)%N] < ma);
			// we'll just start here
			A[i] = ma;
			for (int j = (i+N-1)%N; j != i; j = (j+N-1)%N) {
				assert(A[(j+1)%N] > B[j]);
				A[j] = A[(j+1)%N] + B[j];
				if (A[j] == ma) {
					assert(j == (i+N-1)%N);
					assert(A[(j+1)%N] >= ma);
					assert(A[(j+1)%N] > 0);
					A[j] += A[(j+1)%N];
				}
				assert(A[j] > ma);
			}
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		assert(A[i]);
	}
	for (int i = 0; i < N; i++) {
		assert(B[i] == (A[i] % A[(i+1)%N]));
	}
	cout << "YES" << '\n';
	for (int i = 0; i < N; i++) {
		cout << A[i] << " \n"[i == N-1];
	}

	return 0;
}