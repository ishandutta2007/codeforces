#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> p(10);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'L') {
			int j;
			for (j = 0; p[j] != 0; j++);
			p[j] = 1;
			continue;
		}
		if (c == 'R') {
			int j;
			for (j = 9; p[j] != 0; j--);
			p[j] = 1;
			continue;
		}
		p[c - '0'] = 0;
	}
	for (auto x : p)
		cout << x;
	return 0;
}