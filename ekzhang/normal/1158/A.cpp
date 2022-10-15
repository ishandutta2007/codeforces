#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, M;
int A[MAXN], B[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < M; i++)
		cin >> B[i];
	sort(A, A + N);
	sort(B, B + M);

	int x = A[N - 1];
	int y = B[0];

	if (x > y) {
		cout << -1 << endl;
		return 0;
	}

	LL ans = 0;
	for (int i = 0; i < N - 1; i++)
		ans += (LL) A[i] * M;
	for (int i = 0; i < M; i++)
		ans += B[i];

	if (x != y)
		ans += A[N - 1] - A[N - 2];

	cout << ans << endl;
	return 0;
}