#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int minVal = 1234567890, maxVal = -1234567890;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		minVal = min(minVal, v);
		maxVal = max(maxVal, v);
	}
	cout << (minVal + maxVal) / 2 << endl;
	return 0;
}