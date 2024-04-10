#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int i;
	for (i = n - 2; i >= 0; i--)
		if (a[i] > a[i + 1])
			break;
	cout << i + 1;
	return 0;
}