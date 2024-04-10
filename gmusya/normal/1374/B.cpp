#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int cnt2 = 0, cnt3 = 0;
		while (n % 3 == 0) {
			n /= 3;
			cnt3++;
		}
		while (n % 2 == 0) {
			n /= 2;
			cnt2++;
		}
		if (n != 1 || cnt2 > cnt3) {
			cout << -1 << '\n';
			continue;
		}
		cout << (cnt3 - cnt2) + cnt3 << '\n';
	}
	return 0;
}