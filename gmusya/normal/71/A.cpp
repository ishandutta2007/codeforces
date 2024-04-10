#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i].size() <= 10) cout << a[i] << endl;
		if (a[i].size() > 10) cout << a[i][0] << a[i].size() - 2 << a[i][a[i].size() - 1] << endl;
	}
	return 0;
}