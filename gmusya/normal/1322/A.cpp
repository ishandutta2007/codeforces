#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int open = 0;
	for (int i = 0; i < n; i++)
		open += a[i] == '(';
	if (2 * open != n) {
		cout << -1;
		return 0;
	}
	int last = 0;
	int bal = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == ')' && bal == 0) {
			last = i;
			bal--;
			continue;
		}
		if (a[i] == '(' && bal == -1) {
			bal++;
			ans += i - last + 1;
			continue;
		}
		if (a[i] == '(')
			bal++;
		else
			bal--;
	}
	cout << ans;
	return 0;
}