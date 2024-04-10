#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	string a, b; cin >> a >> b;
	int minPos = -1;
	int minVal = INT_MAX;
	for (int beg = 0; beg + n <= m; beg++) {
		string bSub = b.substr(beg, n);
		int curVal = 0;
		for (int i = 0; i < n; i++) {
			if (bSub[i] != a[i]) {
				curVal++;
			}
		}
		if (curVal < minVal) {
			minVal = curVal;
			minPos = beg;
		}
	}
	string bestSub = b.substr(minPos, n);
	cout << minVal << endl;
	for (int i = 0; i < n; i++) {
		if (bestSub[i] != a[i]) {
			cout << i + 1 << " ";
		}
	}
	cout << endl;
	return 0;
}