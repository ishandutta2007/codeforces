/*input
3
2 1 4

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int mas[n];
	int f = 0;

	for (int i = 0; i < n; i++) {
		cin >> mas[i];
		f += mas[i];
	}

	sort(mas, mas + n, [](const auto & i, const auto & j) -> bool {
		return i > j;
	});

	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += mas[i];
		f -= mas[i];

		if (sum > f) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}