#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;

[[noreturn]] void FAIL() {
	cout << "No" << '\n';
	exit(0);
}

const int MAXN = 3e5;
int N;
ll T;
ll A[MAXN];
int X[MAXN];

ll B[MAXN];

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] += T;
	}
	for (int i = 0; i < N; i++) {
		cin >> X[i]; X[i] --;
		assert(0 <= X[i] && X[i] < N);
	}

	for (int i = 0; i < N; i++) {
		if (X[i] < i) {
			FAIL();
		}
	}

	for (int i = 1; i < N; i++) {
		if (X[i] < X[i-1]) {
			FAIL();
		}
	}

	ll prv = 0;
	for (int i = 0; i < N; i = X[i] + 1) {
		for (int j = i; j <= X[i]; j++) {
			if (X[j] != X[i]) FAIL();
		}
		for (int j = i; j < X[i]; j++) {
			B[j] = prv = max(prv+1, A[j+1]);
		}
		int j = X[i];
		B[j] = prv = max(prv+1, A[j]);
		if (j+1 < N && B[j] >= A[j+1]) {
			FAIL();
		}
	}

	cout << "Yes" << '\n';
	for (int i = 0; i < N; i++) {
		cout << B[i] << " \n"[i==N-1];
	}

	return 0;
}