#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <char> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		vector <bool> tf(n);
		for (int i = 0; i < n; i++)
			tf[i] = (a[i] == b[i]);
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += tf[i];
		if (n - sum == 0)
			cout << "Yes" << endl;
		else {
			if (n - sum != 2)
				cout << "No" << endl;
			else {
				int char1, char2;
				for (char1 = 0; tf[char1] == 1; char1++);
				for (char2 = n - 1; tf[char2] == 1; char2--);
				if (a[char1] == a[char2] && b[char1] == b[char2])
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		}
	}
	return 0;
}