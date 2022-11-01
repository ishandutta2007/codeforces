#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(n), l(n), r(n);
	vector <bool> tf(n);
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		l[a[i] - 1] = i;
	for (int i = 0; i < n; i++)
		r[i] = l[b[i] - 1];
	int uk1 = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		for (uk1; tf[uk1]; uk1++);
		if (uk1 != r[i])
			cnt++;
		tf[r[i]] = true;
	}
	cout << cnt;
	return 0;
}