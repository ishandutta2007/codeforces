#include <iostream>

using namespace std;

const int maxn = 500;

int n, k, i, rez, c, v[maxn], last;

int main() {
	cin >> n >> k;
	cin >> c;
	while (c--)
		cin >> i, v[i] = 1;
	last = 0;
	for (i = 1; i <= n; ++i)
		if (i - last == k || v[i] == 1)
			++rez, last = i;

	cout << rez << "\n";
}