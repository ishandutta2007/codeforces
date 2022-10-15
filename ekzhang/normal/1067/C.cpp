#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

void out(int x, int y) {
	cout << x << ' ' << y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x = (i / 3) * 2;
		if (i % 3 == 0) out(x, 0);
		else if (i % 3 == 1) out(x + 1, 1);
		else out(x + 1, -1);
	}

	cout.flush();
	return 0;
}