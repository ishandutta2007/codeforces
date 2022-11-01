#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ma = a[0];
	for (int i = 1; i < n; i++)
		ma = max(a[i], ma);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += ma - a[i];
	cout << cnt;
	return 0;
}