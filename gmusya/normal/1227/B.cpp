#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector <bool> used(n + 1);
	vector <int> pre(n);
	vector <int> answer;
	int uk = 1;
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	int cur_max = pre[0];
	used[pre[0]] = true;
	answer.push_back(pre[0]);
	for (int i = 1; i < n; i++) {
		if (pre[i] < pre[i - 1]) {
			cout << "-1" << endl;
			return;
		}
		if (pre[i] > pre[i - 1]) {
			answer.push_back(pre[i]);
			used[pre[i]] = true;
		}
		if (pre[i] == pre[i - 1]) {
			while (used[uk])
				uk++;
			if (uk > pre[i]) {
				cout << "-1" << endl;
				return;
			}
			answer.push_back(uk);
			used[uk] = true;
		}
	}
	for (auto now : answer)
		cout << now << " ";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}