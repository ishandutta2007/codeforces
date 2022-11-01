#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (a[i] > m);
	cnt += n;
	cout << cnt;
	return 0;
}