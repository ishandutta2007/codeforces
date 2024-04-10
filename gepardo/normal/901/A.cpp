#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n+1);
	for (int i = 0; i <= n; i++) {
		cin >> v[i];
	}
	
	auto restore = [&](int bound, bool type) {
		vector<int> res;
		int soom = 1;
		res.push_back(0);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < v[i]; j++) {
				if (i == bound && j == 0 && type) {
					res.push_back(soom - 1);
				} else {
					res.push_back(soom);
				}
			}
			soom += v[i];
		}
		return res;
	};
	
	for (int i = 0; i < n; i++) {
		if (v[i] != 1 && v[i+1] != 1) {
			cout << "ambiguous" << endl;
			auto q1 = restore(i+1, true);
			auto q2 = restore(i+1, false);
			for (int i: q1) {
				cout << i << " ";
			}
			cout << endl;
			for (int i: q2) {
				cout << i << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << "perfect" << endl;
	return 0;
}