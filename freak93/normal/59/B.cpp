#include <iostream>
#include <algorithm>

using namespace std;

int n, i, a[150], s, mini = 150;

int main() {
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> a[i];
		s += a[i];
		if (a[i] % 2 == 1)
			mini = min(mini, a[i]);
	}

	if (s % 2 == 1)
		cout << s;
	else
		if (mini != 150)
			cout << s - mini;
		else
			 cout << 0 << "\n";
}