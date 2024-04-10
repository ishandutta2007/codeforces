#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <pair <int, int>> ans;
	ans.push_back({ 0, 0 });
	ans.push_back({ 0, 1 });
	ans.push_back({ 1, 0 });
	ans.push_back({ 1, 1 });
	for (int i = 1; i <= n; i++) {
		ans.push_back({ 1 + i, 1 + i });
		ans.push_back({ i, 1 + i });
		ans.push_back({ 1 + i, i });
	}
	cout << ans.size() << '\n';
	for (auto &now : ans)
		cout << now.first << ' ' << now.second << '\n';
	return 0;
}