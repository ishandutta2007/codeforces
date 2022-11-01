#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	vector <char> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < t; j++) 
		for (int i = 0; i < n - 1; i++)
			if (a[i] == 'B' && a[i + 1] == 'G') {
				swap(a[i], a[i + 1]);
				i++;
			}
	for (int i = 0; i < n; i++)
		cout << a[i];
	return 0;
}