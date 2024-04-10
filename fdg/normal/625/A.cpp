#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	long long ans = n / a;
	if (n >= b) {
		ans = max(ans, 1 + (n - b) / min(a, b - c));
		long long tmp = 1 + (n - b) / (b - c) + ((n - b) % (b - c) + c) / a;
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}