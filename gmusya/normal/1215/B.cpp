#include <iostream>
#include <vector>

using namespace std;

int n;
vector <long long int> a, b, ans1, ans2;

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	b.resize(n);
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) b[i] = 1;
		if (a[i] < 0) b[i] = 0;
	}
	ans1.resize(n);
	ans2.resize(n);
	if (b[0] == 0) {
		ans1[0] = 0;
		ans2[0] = 1;
	}
	if (b[0] == 1) {
		ans1[0] = 1;
		ans2[0] = 0;
	}
	for (int i = 1; i < n; i++) {
		if (b[i] == 1) {
			ans1[i] = ans1[i - 1] + 1;
			ans2[i] = ans2[i - 1];
		}
		if (b[i] == 0) {
			ans1[i] = ans2[i - 1];
			ans2[i] = ans1[i - 1] + 1;
		}
	}
	long long int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) sum1 += ans1[i];
	for (int i = 0; i < n; i++) sum2 += ans2[i];
	cout << sum2 << " " << sum1;
	return 0;
}