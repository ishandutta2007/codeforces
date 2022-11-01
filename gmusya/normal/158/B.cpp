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
	vector <int> b(5);
	for (int i = 0; i < n; i++)
		b[a[i]]++;
	int cnt = 0;
	cnt += b[4];
	int x = min(b[3], b[1]);
	cnt += x;
	b[3] -= x;
	b[1] -= x;
	cnt += b[3];
	x = b[2] / 2;
	b[2] -= 2 * x;
	cnt += x;
	cnt += (b[1] + 2 * b[2] + 3) / 4;
	cout << cnt;
	return 0;
}