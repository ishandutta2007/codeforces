#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector <pair <int, int>> arr;
	arr.push_back({ x, y });
	for (int i = n; i >= x + 1; i--)
		arr.push_back({ i, y });
	for (int i = x - 1; i >= 1; i--)
		arr.push_back({ i, y });
	for (int i = 1; i <= n; i++) {
		if (i % 2) 
			for (int j = 1; j <= m; j++) {
				if (j == y) continue;
				arr.push_back({ i, j });
			}
		else
			for (int j = m; j >= 1; j--) {
				if (j == y) continue;
				arr.push_back({ i, j });
			}
	}
	for (auto &now : arr)
		cout << now.first << ' ' << now.second << '\n';
	return 0;
}