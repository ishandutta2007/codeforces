#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;
int A[103];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i && A[i] + A[i - 1] == 5) {
			cout << "Infinite" << endl;
			return 0;
		}
	}

	int ans = 0;
	for (int i = 1; i < N; i++) {
		// every other one is circle??
		if (A[i] == 1)
			ans += A[i - 1] + 1;
		else if (A[i] == 2)
			ans += 3 - (i >= 2 && A[i - 2] == 3);
		else
			ans += 4;
	}

	cout << "Finite\n" << ans << endl;
	return 0;
}