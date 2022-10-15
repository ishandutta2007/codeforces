#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	int on = 1, om = 1;

	while (true) {
		if (N == 0)
			break;
		if (N == 1) {
			for (int i = 0; i < M; i++) {
				if (i % 2 == 0)
					cout << on << ' ' << om + i / 2 << '\n';
				else
					cout << on << ' ' << om + M - 1 - i / 2 << '\n';
			}
			break;
		}
		// N >= 2;
		for (int i = 0; i < M; i++) {
			cout << on << ' ' << om + i << '\n';
			cout << on + N - 1 << ' ' << om + M - 1 - i << '\n';
		}
		on += 1;
		N -= 2;
	}

	cout.flush();
	return 0;
}