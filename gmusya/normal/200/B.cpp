#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	double sum = 0;
	vector <double> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		sum += a[i];
	sum /= n;
	cout << fixed << setprecision(10) << sum;
	return 0;
}