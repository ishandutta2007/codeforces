#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cnt += (a[i].first == a[j].second && i != j);
	cout << cnt;
	return 0;
}