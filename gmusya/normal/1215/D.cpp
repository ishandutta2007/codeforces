#include <iostream>
#include <vector>

using namespace std;

int n;
double sum1 = 0, num1 = 0, sum2 = 0, num2 = 0;
vector <char> a;

void swap() {
	double k = sum1;
	sum1 = sum2;
	sum2 = k;
	k = num1;
	num1 = num2;
	num2 = k;
}

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n / 2; i++) {
		if (a[i] == '0') sum1 += 0;
		if (a[i] == '1') sum1 += 1;
		if (a[i] == '2') sum1 += 2;
		if (a[i] == '3') sum1 += 3;
		if (a[i] == '4') sum1 += 4;
		if (a[i] == '5') sum1 += 5;
		if (a[i] == '6') sum1 += 6;
		if (a[i] == '7') sum1 += 7;
		if (a[i] == '8') sum1 += 8;
		if (a[i] == '9') sum1 += 9;
		if (a[i] == '?') num1 += 1;
	}
	for (int i = n / 2; i < n; i++) {
		if (a[i] == '0') sum2 += 0;
		if (a[i] == '1') sum2 += 1;
		if (a[i] == '2') sum2 += 2;
		if (a[i] == '3') sum2 += 3;
		if (a[i] == '4') sum2 += 4;
		if (a[i] == '5') sum2 += 5;
		if (a[i] == '6') sum2 += 6;
		if (a[i] == '7') sum2 += 7;
		if (a[i] == '8') sum2 += 8;
		if (a[i] == '9') sum2 += 9;
		if (a[i] == '?') num2 += 1;
	}
	bool win1, win2;
	if (sum1 < sum2) swap();
	sum1 += 4.5 * num1;
	sum2 += 4.5 * num2;
	if (sum1 == sum2) cout << "Bicarp";
	else cout << "Monocarp";
	return 0;
}