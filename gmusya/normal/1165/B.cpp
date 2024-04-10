#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, l;
	l = 0;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (l + 1 <= a[i]) l++;
	}
	cout << l;
	return 0;
}