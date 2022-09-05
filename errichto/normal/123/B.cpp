#include <bits/stdc++.h>
using namespace std;

long long divide(long long a, long long b) {
	if(a < 0) {
		return a / b - 1;
	}
	else {
		return a / b;
	}
}

int main() {
	long long a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;
	long long n = abs(divide(x1 - y1, 2 * b) - divide(x2 - y2, 2 * b));
	long long m = abs(divide(x1 + y1, 2 * a) - divide(x2 + y2, 2 * a));
	cout << max(n, m) << "\n";
}