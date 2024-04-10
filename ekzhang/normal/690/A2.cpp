#include <bits/stdc++.h>
using namespace std;

#define SIG(x) (1<<(31-__builtin_clz(x)))

int N;

int main() {
	cin >> N;
	if (N % 2 == 1) {
		cout << N / 2 << endl;
	}
	else {
		cout << (N - SIG(N)) / 2 << endl;
	}
	return 0;
}