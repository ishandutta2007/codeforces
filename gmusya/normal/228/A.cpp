#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <int> a(4);
	for (int i = 0; i < 4; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < 3; i++)
		cnt += a[i] == a[i + 1];
	cout << cnt;
	return 0;
}