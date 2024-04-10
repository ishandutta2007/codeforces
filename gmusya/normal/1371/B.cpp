#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		long long n, r;
		cin >> n >> r;
		long long val = min(n - 1, r);
		long long sum = val * (val + 1) / 2;
		if (r >= n) sum++;
		cout << sum << '\n';
	}
	return 0;
}