#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if (a[n - 2] + a[n - 3] <= a[n - 1]) cout << "NO";
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n - 2; i++) cout << a[i] << " ";
		cout << a[n - 1] << " " << a[n - 2];
	}
	return 0;
}