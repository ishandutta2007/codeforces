#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
	int bc = 14;
	int n, k; cin >> n >> k;
	vector<int> cnts(16384, 0);
	vector<int> masks;
	function<void(int, int, int)> gen = [&](int step, int k, int val) {
		if (step == bc) {
			if (k == 0) {
				masks.push_back(val);
			}
			return;
		}
		gen(step+1, k, val << 1);
		if (k) {
			gen(step+1, k-1, (val << 1) + 1);
		}
	}; 
	gen(0, k, 0);
	int64_t res = 0;
	for (int i = 0; i < n; i++) {
		int q; cin >> q;
		cnts[q]++;
	}
	for (int i = 0; i < (int)cnts.size(); i++) {
		for (int j = 0; j < (int)masks.size(); j++) {
			res += (int64_t)cnts[i] * cnts[i ^ masks[j]];
		}
	}
	if (k == 0) {
		res -= n;
	}
	cout << res / 2 << endl;
	return 0;
}