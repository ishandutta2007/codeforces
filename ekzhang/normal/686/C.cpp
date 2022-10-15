#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXD 25
int N, M;
int D1, D2;
int digits[7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	int D1 = 1, D2 = 1;
	int n1 = 7, n2 = 7;
	while (n1 < N) {
		n1 *= 7;
		++D1;
	}
	while (n2 < M) {
		n2 *= 7;
		++D2;
	}

	if (D1 + D2 > 7) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < 7; i++) {
		digits[i] = i;
	}

	int ans = 0;
	do {
		int h = 0, m = 0;
		for (int i = 0; i < D1; i++) {
			h *= 7;
			h += digits[i];
		}
		for (int i = D1; i < D1 + D2; i++) {
			m *= 7;
			m += digits[i];
		}
		if (h < N && m < M) {
			++ans;
		}
	} while (next_permutation(digits, digits + 7));

	for (int x = 1; x <= 7 - D1 - D2; x++) {
		ans /= x;
	}

	cout << ans << endl;
	return 0;
}