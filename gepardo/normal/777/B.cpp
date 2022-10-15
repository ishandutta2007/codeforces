#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	string a, b; cin >> a >> b;
	sort(a.begin(), a.end());
	vector<int> cnt;
	cnt.assign(10, 0);
	for (int i = 0; i < n; i++) {
		cnt[b[i] - '0']++;
	}
	int minTake = 0;
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = a[i] - '0'; j < 10; j++) {
			if (cnt[j]) {
				cnt[j]--;
				ok = true;
				break;
			}
		}
		if (!ok) {
			minTake++;
		}
	}
	cnt.assign(10, 0);
	for (int i = 0; i < n; i++) {
		cnt[b[i] - '0']++;
	}
	int maxGive = 0;
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = a[i] - '0' + 1; j < 10; j++) {
			if (cnt[j]) {
				cnt[j]--;
				ok = true;
				break;
			}
		}
		if (ok) {
			maxGive++;
		}
	}
	cout << minTake << endl << maxGive << endl;
	return 0;
}