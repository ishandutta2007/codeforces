#include <bits/stdc++.h>
using namespace std;

long long divide(long long a, long long b) {
	return (a + b - 1) / b;
}

void test_case() {
	long long x, y, k;
	cin >> x >> y >> k;
	long long a = k + k * y;
	long long ans = k + divide(a-1, x-1);
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}