#include <iostream>

using namespace std;

int n, v[1005], i, j, p, k;

int main() {
	cin >> n >> k;
	for (i = 1; i <= n; ++i)
		cin >> v[i];
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j)
			if (v[j] == 0)
				break;
		cout << j << " ";
		v[j] = -1;
		for (p = 1; p <= j - k; ++p)
			--v[p];
	}
}