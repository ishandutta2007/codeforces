#include<bits/stdc++.h>
using namespace std;

int main() {
	long long N; cin >> N;
	if (N % 2 == 0) {
		cout << N / 2 << '\n';
		return 0;
	} else {
		for (long long p = 3; p * p <= N; p += 2) {
			if (N % p == 0) {
				cout << 1 + (N - p) / 2 << '\n';
				return 0;
			}
		}
		cout << 1 << '\n';
	}

	return 0;
}