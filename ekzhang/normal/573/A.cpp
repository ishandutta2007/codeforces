#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N;
int bids[MAXN];

int gcd(int a, int b) {
	while (b != 0) {
		int mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}

bool isTwoThree(int n) {
	while (n % 2 == 0) {
		n /= 2;
	}
	while (n % 3 == 0) {
		n /= 3;
	}
	return n == 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> bids[i];
	}

	for (int i = 0; i < N - 1; i++) {
		int g = gcd(bids[i], bids[i + 1]);
		if (!isTwoThree(bids[i] / g) || !isTwoThree(bids[ i + 1] / g)) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}