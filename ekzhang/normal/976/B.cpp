#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

LL N, M;
LL K;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M >> K;
	LL r = -1, c = -1;

	if (K < N)
		r = K, c = 0;
	else {
		K -= N;
		LL d = K / (M - 1), m = K % (M - 1);
		r = N - 1 - d;
		c = 1 + m;
		if (d % 2)
			c = M - c;
	}

	cout << r + 1 << ' ' << c + 1 << endl;
	return 0;
}