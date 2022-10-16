/*input
3
^ 1
^ 2
^ 3


*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	bool toone[10] = {};
	bool tozero[10] = {};
	bool flip[10] = {};

	for (int i = 0; i < n; i++) {
		char c;
		int x;
		cin >> c >> x;

		if (c == '|') {
			for (int i = 0; i < 10; i++) {
				if (((1 << i)&x) > 0) {
					toone[i] = true;
					tozero[i] = false;
					flip[i] = false;
				}
			}
		}
		else if (c == '&') {
			for (int i = 0; i < 10; i++) {
				if (((1 << i)&x) == 0) {
					tozero[i] = true;
					toone[i] = false;
					flip[i] = false;
				}
			}
		}
		else if (c == '^') {
			for (int i = 0; i < 10; i++) {
				if (((1 << i)&x) > 0) {
					if (toone[i]) {
						tozero[i] = true;
						toone[i] = false;
					}
					else if (tozero[i]) {
						toone[i] = true;
						tozero[i] = false;
					}
					else
						flip[i] = !flip[i];
				}
			}
		}
	}

	int orr = 0, andd = 1023, xorr = 0;

	for (int i = 0; i < 10; i++) {
		if (toone[i])
			orr += (1 << i);

		if (tozero[i])
			andd -= (1 << i);

		if (flip[i])
			xorr += (1 << i);
	}

	cout << "3\n";
	cout << "| " << orr << endl;
	cout << "& " << andd << endl;
	cout << "^ " << xorr << endl;

	return 0;
}