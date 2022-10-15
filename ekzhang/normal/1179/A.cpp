#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, Q;
int A[3 * MAXN];
int X[2 * MAXN], Y[2 * MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int k = 0; k < 2 * N; k++) {
		X[k] = A[k];
		Y[k] = A[k + 1];
		if (A[k] > A[k + 1])
			swap(A[k], A[k + 1]);
		A[k + N] = A[k];
	}

	while (Q--) {
		LL m; cin >> m; --m;
		if (m >= 2 * N) {
			m = m % (N - 1);
			while (m + N - 1 < 2 * N)
				m += N - 1;
		}
		cout << X[m] << ' ' << Y[m] << '\n';
	}

	cout.flush();
	return 0;
}