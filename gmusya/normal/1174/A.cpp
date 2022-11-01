#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(2 * n);
	for (int i = 0; i < 2 * n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	if (a[0] == a[2 * n - 1]) cout << -1;
	else for (int i = 0; i < 2 * n; i++) cout << a[i] << " ";
	return 0;
}