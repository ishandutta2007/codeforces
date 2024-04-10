#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, p;
	cin >> p >> n;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		if (p <= a[i].first) {
			cout << "NO";
			return 0;
		}
		p += a[i].second;
	}
	cout << "YES";
	return 0;
}