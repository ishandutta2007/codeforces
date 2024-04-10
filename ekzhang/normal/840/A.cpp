#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N;
int A[MAXN], B[MAXN];
int idx[MAXN];
int ans[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		idx[i] = i;
	}

	sort(idx, idx + N, [](int i, int j) {
		return B[i] > B[j];
	});

	sort(A, A + N);

	for (int i = 0; i < N; i++) {
		ans[idx[i]] = A[i];
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}

	cout << endl;
	return 0;
}