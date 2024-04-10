#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += min(min(abs(a[i] - b[i]), abs(a[i] - b[i] - 10)), abs(a[i] - b[i] + 10));
	cout << cnt;
	return 0;
}