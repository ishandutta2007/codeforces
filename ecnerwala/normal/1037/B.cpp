#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2.1e5;
int N;
int A[MAXN];
int S;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	int mid = N / 2;
	long long res = 0;
	for (int i = 0; i <= mid; i++) {
		if (A[i] > S) {
			res += A[i] - S;
		}
	}
	for (int i = mid; i < N; i++) {
		if (S > A[i]) {
			res += S - A[i];
		}
	}
	cout << res << '\n';

	return 0;
}