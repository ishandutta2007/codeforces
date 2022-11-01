#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i += 2) 
			a[i] = i + 1;
		for (int i = 1; i < n; i += 2)
			a[i] = i;
		for (auto &now : a)
			cout << now << ' ';
		cout << '\n';
	}
	return 0;
}