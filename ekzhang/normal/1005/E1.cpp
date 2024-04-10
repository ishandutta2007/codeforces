#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N, M;
int A[MAXN];
LL lef[2 * MAXN];
LL rht[2 * MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int idx = find(A, A + N, M) - A;

	int cur = N;
	++lef[cur];
	for (int i = idx - 1; i >= 0; i--) {
		if (A[i] < M)
			++lef[--cur];
		else
			++lef[++cur];
	}

	cur = N;
	++rht[cur];
	for (int i = idx + 1; i < N; i++) {
		if (A[i] < M)
			++rht[--cur];
		else
			++rht[++cur];
	}

	LL ans = 0;
	for (int i = 1; i < 2 * N; i++) {
		ans += lef[i] * rht[2 * N - i];
		ans += lef[i] * rht[2 * N - i + 1];
	}

	cout << ans << endl;
	return 0;
}