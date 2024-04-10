#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set <int> kek;
		for (int i = 0; i < ceil(sqrt(n)); i++) {
			kek.insert(i);
		}
		for (int i = 1; i <= ceil(sqrt(n)); i++)
			kek.insert(n / i);
		cout << kek.size() << endl;
		for (auto now : kek)
			cout << now << " ";
		cout << endl;
	}
	return 0;
}