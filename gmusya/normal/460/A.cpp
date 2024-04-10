#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	int cnt1 = 0;
	while (n > 0) {
		cnt += n;
		cnt1 += n % m;
		n /= m;
		n += cnt1 / m;
		cnt1 = cnt1 % m;
	}
	cout << cnt;
	return 0;
}