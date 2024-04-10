#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];
	int bal = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] == ')')
			bal--;
		else
			bal++;
		if (bal < -1) {
			cout << "No";
			return 0;
		}
	}
	if (bal == 0)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}