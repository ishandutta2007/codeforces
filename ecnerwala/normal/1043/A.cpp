#include<bits/stdc++.h>
using namespace std;

int N;
int A[200];
int K;
int main() {
	cin >> N; for (int i = 0; i < N; i++) cin >> A[i];
	K = 0;
	for (int i = 0; i < N; i++) {
		K = max(K, A[i]);
	}
	int T = 0;
	for (int i = 0; i < N; i++) {
		T += A[i];
	}
	T = 2 * T + 1;
	K = max(K, (T + N-1) / N);
	cout << K << '\n';

	return 0;
}