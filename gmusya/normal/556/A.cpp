#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, cnt1 = 0, cnt2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		if (x == '0')
			cnt1++;
		if (x == '1')
			cnt2++;
	}
	cout << abs(cnt1 - cnt2);
	return 0;
}