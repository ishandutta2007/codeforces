#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> group(256, -1);
	for (int i = 0; i < n; i++) {
		int kolor; cin >> kolor;
		if (group[kolor] < 0) {
			int ptr = kolor;
			while (ptr >= 0 && kolor < ptr + k && group[ptr] < 0) {
				ptr--;
			}
			if (ptr >= 0 && kolor < group[ptr] + k) {
				ptr = group[ptr];
			} else {
				ptr++;
			}
			for (int j = ptr; j <= kolor; j++) {
				group[j] = ptr;
			}
		}
		cout << group[kolor] << " ";
	}
	cout << endl;
	return 0;
}