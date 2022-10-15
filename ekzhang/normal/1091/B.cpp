#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	LL x = 0, y = 0;
	for (int i = 0; i < 2 * N; i++) {
		int xx, yy;
		cin >> xx >> yy;
		x += xx; y += yy;
	}

	x /= N;
	y /= N;

	cout << x << ' ' << y << endl;
	return 0;
}