#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	int s12, s13, s23;
	cout << "? 1 2" << endl;
	cout.flush();
	cin >> s12;
	cout << "? 1 3" << endl;
	cout.flush();
	cin >> s13;
	cout << "? 2 3" << endl;
	cout.flush();
	cin >> s23;
	a[0] = (s12 + s13 - s23) / 2;
	a[1] = (s12 + s23 - s13) / 2;
	a[2] = (s13 + s23 - s12) / 2;
	for (int i = 3; i < n; i++) {
		cout << "? 1 " << i + 1 << endl;
		int x;
		cin >> x;
		a[i] = x - a[0];
	}
	cout << "! ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}