#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <char> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		vector <int> zeros, ones;
		vector <int> ans(n);
		for (int i = 0; i < n; i++) {
			if (a[i] == '0') {
				if (ones.empty()) {
					ans[i] = zeros.size();
					zeros.push_back(ans[i]);
					continue;
				}
				else {
					ans[i] = ones.back();
					ones.pop_back();
					zeros.push_back(ans[i]);
				}
				continue;
			}
			if (zeros.empty()) {
				ans[i] = ones.size();
				ones.push_back(ans[i]);
				continue;
			}
			ans[i] = zeros.back();
			zeros.pop_back();
			ones.push_back(ans[i]);
		}
		cout << zeros.size() + ones.size() << '\n';
		for (auto &now : ans)
			cout << now + 1 << ' ';
		cout << '\n';
	}
	return 0;
}