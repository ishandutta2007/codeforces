#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(1000009), c(1000009);
	vector <int> ans;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum = 0;
	int cnt = 0;
	vector <int> prover;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			cnt++;
			sum++;
			b[a[i]]++;
			c[a[i]]++;
			prover.push_back(a[i]);
			if (b[a[i]] > 1 || c[a[i]] > 1) {
				cout << "-1";
				return 0;
			}
		}
		if (a[i] < 0) {
			cnt++;
			sum--;
			b[-a[i]]--;
			if (b[-a[i]] < 0) {
				cout << "-1";
				return 0;
			}
		}
		if (sum == 0) {
			ans.push_back(cnt);
			cnt = 0;
			for (int i = 0; i < prover.size(); i++) {
				if (c[prover[i]] > 1) {
					cout << "-1";
					return 0;
				}
				c[prover[i]] = 0;
			}
			prover.resize(0);
		}
	}
	for (int i = 0; i < 1000009; i++)
		if (b[i] != 0) {
			cout << "-1";
			return 0;
		}
	cout << ans.size() << endl;
	for (auto now : ans) cout << now << " ";
	return 0;
}