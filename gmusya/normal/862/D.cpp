#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	cout << "? ";
	for (int i = 0; i < n; i++)
		cout << '0';
	cout << endl;
	cout.flush();
	int x;
	cin >> x;
	cout << "? ";
	for (int i = 0; i < n - 1; i++)
		cout << '0';
	cout << '1';
	cout << endl;
	cout.flush();
	int y;
	cin >> y;
	if (x > y) {
		x = n - x;
		int pos0, pos1;
		pos1 = n - 1;
		int l = 0;
		int r = n - 1;
		while (l != r) {
			int m = (l + r + 1) / 2;
			cout << "? ";
			for (int i = 0; i < m; i++)
				cout << '1';
			for (int i = m; i < n; i++)
				cout << '0';
			int units = n - m;
			cout << endl;
			cout.flush();
			int s;
			cin >> s;
			if (x + units == s) r = m - 1;
			else l = m;
		}
		pos0 = l;
		cout << "! " << pos0 + 1 << " " << pos1 + 1;
		return 0;
	}
	int pos0, pos1;
	pos0 = n - 1;
	int l = 0;
	int r = n - 1;
	while (l != r) {
		int m = (l + r + 1) / 2;
		cout << "? ";
		for (int i = 0; i < m; i++)
			cout << '0';
		for (int i = m; i < n; i++)
			cout << '1';
		int units = n - m;
		cout << endl;
		cout.flush();
		int s;
		cin >> s;
		if (x + units == s) r = m - 1;
		else l = m;
	}
	pos1 = l;
	cout << "! " << pos0 + 1 << " " << pos1 + 1 << endl;
	return 0;
}