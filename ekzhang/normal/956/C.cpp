#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
int A[MAXN];
int B[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		B[i] = A[i] + 1;
	}

	for (int i = 1; i < N; i++) {
		B[i] = max(B[i], B[i - 1]);
	}
	for (int i = N - 2; i >= 0; i--) {
		B[i] = max(B[i], B[i + 1] - 1);
	}

	LL ans = 0;
	for (int i = 1; i < N; i++) {
		ans += B[i] - 1 - A[i];
	}

	cout << ans << endl;
	return 0;
}