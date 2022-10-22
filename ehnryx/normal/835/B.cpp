#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> num;
	int sum = 0;
	int k;
	string n;
	cin >> k;
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		sum += n[i] - '0';
		num.push_back(n[i]-'0');
	}
	if (sum >= k) cout << 0 << endl;
	else {
		int diff = k-sum;
		sort(num.begin(), num.end());
		for (int i = 0; i < n.size(); i++) {
			diff = max(0, diff-(9-num[i]));
			if (!diff) {
				cout << i+1 << endl;
				break;
			}
		}
	}
	return 0;
}