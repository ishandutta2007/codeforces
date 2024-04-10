#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
	string a, b; cin >> a >> b;
	b = " " + b + " ";
	int n = a.size(), m = b.size();
	vector<int> bL(m, INT_MAX), bR(m, INT_MIN);
	bL[0] = INT_MIN;
	int last = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[last]) {
			bL[last] = i;
			last++;
		}
	}
	bR[m-1] = INT_MAX;
	last = m-2;
	for (int i = n-1; i >= 0; i--) {
		if (a[i] == b[last]) {
			bR[last] = i;
			last--;
		}
	}
	int bestVal = INT_MAX, bestL = -1, bestR = -1;
	if (bR[1] != INT_MIN) {
		bestVal = bestL = bestR = 0;
	} else {
		for (int i = 1; i < m-1; i++) {
			int l = i, r = m-2;
			while (l < r) {
				int m = (l + r) / 2;
				if (bL[i-1] < bR[m+1]) {
					r = m;
				} else {
					l = m+1;
				}
			}
			if (bL[i-1] < bR[l+1] && l - i + 1 <= bestVal) {
				bestVal = l - i + 1;
				bestL = i;
				bestR = l;
			}
		}
	}
	if (bestL != 0) {
		b.erase(bestL, bestR - bestL + 1);
		b.pop_back();
		b.erase(0, 1);
	}
	if (b.empty()) {
		b = "-";
	}
	cout << b << endl;
	return 0;
}