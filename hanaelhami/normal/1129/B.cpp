#include <bits/stdc++.h>

using namespace std;

int k;

int main(){
	cin >> k;
	for (int i = 1; i <= 1e6; ++i) {
		int val = k + 3 * i;
		if (val % 5 || val / 5 >= i)
			continue;
		cout << 3 << '\n';
		cout << val / 5 << ' ' << -i << ' ' << val / 5 << '\n';
		return 0;
	}
	int val;
	for (int i = 1e6; ; --i)
		if (!((i + k) % 1500)) {
			val = i;
			break;
		}
	int x = val - (k + val) / 1500;
	cout << 1500 << '\n';
	for (int i = 0; i < 1498; ++i)
		cout << "-1 ";
	cout << 1498 - x << ' ' << val << '\n';
	return 0;
}