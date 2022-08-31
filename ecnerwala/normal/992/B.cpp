#include <bits/stdc++.h>
using namespace std;

int go() {
	int L, R, X, Y; cin >> L >> R >> X >> Y;
	if (Y % X != 0) return 0;
	Y /= X;
	L--;
	L /= X;
	R /= X;
	if (Y == 1) return L < 1 && 1 <= R;
	// (L, R]
	int res = 0;
	for (int i = 1; i < Y / i; i++) {
		if (Y % i == 0) {
			if (L < i && Y / i <= R && __gcd(i, Y / i) == 1) res += 2;
		}
	}
	return res;
}

int main() {
	// your code goes here
	cout << go() << '\n';
	return 0;
}