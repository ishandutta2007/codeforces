#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int Q, N;
int A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];
		sort(A, A + N);
		N = unique(A, A + N) - A;
		int ans = 0;
		for (int i = N - 1; i >= 0; i--) {
			ans = max(ans, A[i]);
			for (int j = i - 1; j >= 0; j--) {
				if (A[i] % A[j]) {
					ans = max(ans, A[i] + A[j]);
					for (int k = j - 1; k >= 0; k--) {
						if (A[i] % A[k] && A[j] % A[k]) {
							ans = max(ans, A[i] + A[j] + A[k]);
							break;
						}
					}
					break;
				}
			}
		}
		cout << ans << '\n';
	}

	cout.flush();
	return 0;
}