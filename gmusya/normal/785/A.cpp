#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	vector <string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += 4 * (a[i][0] == 'T') + 6 * (a[i][0] == 'C') + 8 * (a[i][0] == 'O') + 12 * (a[i][0] == 'D') + 20 * (a[i][0] == 'I');
	}
	cout << cnt;
	return 0;
}