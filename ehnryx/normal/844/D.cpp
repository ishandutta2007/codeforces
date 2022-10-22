#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand(time(NULL));

	int n, start, x;
	cin >> n >> start >> x;
	
	int curr, value, next;
	if (n < 2000) {
		curr = start;
	}
	else {
		vector<int> index;
		for (int i = 1; i <= n; i++) {
			index.push_back(i);
		} random_shuffle(index.begin(), index.end());

		int lval, lnext;
		lnext = start; 
		lval = -1;
		for (int i = 0; i < 600; i++) {
			cout << "? " << index[i] << endl;
			cin >> value >> next;
			if (lval < value && value < x) {
				lnext = next;
				lval = value;
			}
		}
		curr = lnext;
	}
	while (curr != -1) {
		cout << "? " << curr << endl;
		cin >> value >> next;
		if (value >= x) {
			cout << "! " << value << endl;
			return 0;
		}
		curr = next;
	}
	cout << "! " << -1 << endl;

	return 0;
}