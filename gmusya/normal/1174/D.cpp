#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector <bool> used(1 << n);
	vector <int> ans;
	ans.push_back(0);
	used[0] = true;
	for (int i = 1; i < (1 << n); i++) {
		if ((i^x) < (1 << n) && used[i^x]) continue;
		ans.push_back(i);
		used[i] = true;
	}
	cout << ans.size() - 1 << '\n';
	for (int i = 0; i < ans.size() - 1; i++)
		cout << (ans[i] ^ ans[i + 1]) << ' ';
	return 0;
}