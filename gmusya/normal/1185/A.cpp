#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <int> a(3);
	int d;
	for (int i = 0; i < 3; i++) cin >> a[i];
	cin >> d;
	sort(a.begin(), a.end());
	int cnt1 = 0, cnt2 = 0;
	while (a[0] + d > a[1] + cnt1) cnt1++;
	while (a[1] + d > a[2] + cnt2) cnt2++;
	cout << cnt1 + cnt2;
	return 0;
}