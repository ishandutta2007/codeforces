#include <iostream>
#include <vector>

using namespace std;

int main() {
	cout << "a" << endl;
	cout.flush();
	int x;
	cin >> x;
	if (x == 0) {
		cout.flush();
		return 0;
	}
	if (x == 300) {
		for (int i = 0; i <= x - 1; i++)
			cout << 'b';
		cout << endl;
		cout.flush();
		cin >> x;
		cout.flush();
		return 0;
	}
	vector <char> c(x + 1);
	for (int i = 0; i <= x; i++) {
		c[i] = 'a';
	}
	for (auto now : c)
		cout << now;
	cout << endl;
	cout.flush();
	int r;
	cin >> r;
	if (r > x) {
		for (int i = 0; i <= x - 1; i++)
			cout << 'b';
		cout << endl;
		cout.flush();
		cin >> x;
		cout.flush();
		return 0;
	}
	int oldr = r;
	int cnt = 0;
	while (r != 0) {
		c[cnt] = 'b';
		for (int i = 0; i <= x; i++)
			cout << c[i];
		cout << endl;
		cout.flush();
		cin >> r;
		if (r > oldr)
			c[cnt] = 'a';
		else
			oldr = r;
		cnt++;
	}
	cout.flush();
	return 0;
}