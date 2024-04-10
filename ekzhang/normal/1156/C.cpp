#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N, Z;
int X[MAXN];

bool test(int k) {
	for (int i = 0; i < k; i++)
		if (X[i] + Z > X[N - k + i])
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> Z;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}

	sort(X, X + N);

	int lo = 0;
	int hi = N / 2;
	while (lo != hi) {
		int mid = (lo + hi + 1) / 2;
		if (test(mid))
			lo = mid;
		else
			hi = mid - 1;
	}

	cout << lo << endl;
	return 0;
}