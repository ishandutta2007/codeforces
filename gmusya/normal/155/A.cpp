#include <iostream>
#include <vector> 

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
			cnt++;
		}
		if (a[i] > max) {
			max = a[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}