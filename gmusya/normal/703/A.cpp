#include <iostream>
#include <vector>

using namespace std;

int main() {
	int cnt1 = 0, cnt2 = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			cnt1++;
		if (b > a)
			cnt2++;
	}
	if (cnt1 > cnt2)
		cout << "Mishka";
	if (cnt1 == cnt2)
		cout << "Friendship is magic!^^";
	if (cnt1 < cnt2)
		cout << "Chris";
	return 0;
}