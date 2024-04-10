#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	t--;
	vector <int> a(n);
	for (int i = 0; i < n - 1; i++)
		cin >> a[i];
	bool tf = false;
	int i = 0;
	while (i < n - 1) {
		if (i == t)
			tf = true;
		i += a[i];
	}
	if (i == t)
		tf = true;
	if (tf)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}