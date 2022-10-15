#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 18
int N;
int A[MAXN];

bool solve() {
	for (int mask = 0; mask < (1<<N); mask++) {
		int ng = 0;
		for (int k = 0; k < N; k++)
			if (mask & (1<<k))
				ng += A[k];
			else
				ng -= A[k];
		if (ng % 360 == 0)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cout << (solve() ? "YES" : "NO") << endl;
	return 0;
}