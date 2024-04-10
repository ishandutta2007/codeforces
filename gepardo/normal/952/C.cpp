#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	while (!v.empty()) {
		n = v.size();
		for (int j = 1; j < n; j++) {
			if (abs(v[j-1] - v[j]) >= 2) {
				cout << "NO" << endl;
				return 0;
			}
		}
		int mVal = 0;
		for (int j = 1; j < n; j++) {
			if (v[mVal] > v[j]) {
				mVal = j;
			}
		}
		for (int j = mVal+1; j < n; j++) {
			v[j-1] = v[j];
		}
		v.pop_back();
	}
	cout << "YES" << endl;
	return 0;
}