#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013

int N, K;
LL A[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = N - 2; i >= 0; i--)
		A[i] += A[i + 1];

	LL sum = A[0];
	sort(A + 1, A + N);

	cout << sum + accumulate(A + N - K + 1, A + N, 0LL) << endl;
	return 0;
}