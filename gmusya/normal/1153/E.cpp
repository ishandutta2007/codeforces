#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a = -1, b = -1;
	for (int i = 1; i <= n; i++) {
		cout << "? 1 " << i << " " << n << " " << i << endl;
		cout.flush();
		int x;
		cin >> x;
		if (x % 2) {
			if (a == -1)
				a = i;
			else
				b = i;
		}
	}
	int c, d;
	if (a != -1) {
		int l = 1, r = n;
		while (l != r) {
			int m = (l + r) / 2;
			cout << "? " << 1 << " " << a << " " << m << " " << a << endl;
			cout.flush();
			int x;
			cin >> x;
			if (x % 2)
				r = m;
			else
				l = m + 1;
		}
		c = l;
		l = 1, r = n;
		while (l != r) {
			int m = (l + r) / 2;
			cout << "? " << 1 << " " << b << " " << m << " " << b << endl;
			cout.flush();
			int x;
			cin >> x;
			if (x % 2)
				r = m;
			else
				l = m + 1;
		}
		d = l;
		cout << "! " << c << " " << a << " " << d << " " << b;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << "? " << i << " 1 " << i << " " << n << endl;
		cout.flush();
		int x;
		cin >> x;
		if (x % 2) {
			if (a == -1)
				a = i;
			else
				b = i;
		}
	}
	int l = 1, r = n;
	while (l != r) {
		int m = (l + r) / 2;
		cout << "? " << a << " 1 " << a << " " << m << endl;
		cout.flush();
		int x;
		cin >> x;
		if (x % 2)
			r = m;
		else
			l = m + 1;
	}
	c = l;
	cout << "! " << a << " " << c << " " << b << " " << c << endl;
	return 0;
}