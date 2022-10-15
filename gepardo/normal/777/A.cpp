#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	const int table[6][3] = {
		{0, 1, 2},
		{1, 0, 2},
		{1, 2, 0},
		{2, 1, 0},
		{2, 0, 1},
		{0, 2, 1}
	};
	int n, x; cin >> n >> x;
	cout << table[n % 6][x] << endl;
	return 0;
}