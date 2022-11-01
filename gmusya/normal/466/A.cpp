#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	cout << min((n / m) * b + (n % m) * a, min(a * n, (n + m - 1) / m * b));
	return 0;
}