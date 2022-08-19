#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	A[0] = 0; // dummy value
	ll res = 0;
	for (int i = 1; i <= N; i++) {
		// A[i] is in, but A[i-1] is not
		if (A[i] > A[i-1]) {
			res += ll(A[i] - A[i-1]) * ll(N - A[i] + 1);
		} else {
			res += ll(A[i-1] - A[i]) * ll(A[i]);
		}
	}
	cout << res << '\n';

	return 0;
}