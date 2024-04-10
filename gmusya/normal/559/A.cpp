#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> a(6);
	for (int i = 0; i < 6; i++) 
		cin >> a[i];
	vector <int> b(a[1] + a[2] + 1);
	b[0] = a[0];
	for (int i = 1; i < b.size(); i++) {
		int diff = 0;
		if (i > a[1]) diff--;
		else diff++;
		if (i > a[5]) diff--;
		else diff++;
		b[i] = b[i - 1] + (diff / 2);
	}
	int sum = 0;
	for (int i = 0; i < b.size() - 1; i++)
		sum += (b[i] + b[i + 1]);
	cout << sum;
	return 0;
}