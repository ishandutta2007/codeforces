#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 50;
vector <vector <char>> ans(n, vector<char>(n, '.'));

int main() {
	vector <pair <int, char>> arr(4);
	for (int i = 0; i < 4; i++) {
		cin >> arr[i].first;
		arr[i].second = 'A' + i;
	}
	sort(arr.begin(), arr.end());
	int a = arr[0].first, b = arr[1].first, c = arr[2].first, d = arr[3].first;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a == 1)
				break;
			if ((i + j) % 2 == 0) {
				a--;
				ans[i][j] = 'A';
			}
			if ((i + j) % 2 == 1) {
				b--;
				ans[i][j] = 'B';
			}
		}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n; j++)
			if (ans[i][j] == '.')
				ans[i][j] = 'C';
	}
	for (int j = 0; j < n; j++)
		ans[5][j] = 'D';
	for (int j = 0; j < n; j++)
		ans[6][j] = 'A';
	c--;
	d--;
	a--;
	for (int i = 7; i < n; i += 2) {
		for (int j = 0; j < n; j += 2) {
			if (b > 0) {
				ans[i][j] = 'B';
				b--;
				continue;
			}
			if (c > 0) {
				ans[i][j] = 'C';
				c--;
				continue;
			}
			if (d > 0) {
				ans[i][j] = 'D';
				d--;
				continue;
			}
			break;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ans[i][j] == '.')
				ans[i][j] = 'A';
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans[i][j] = arr[ans[i][j] - 'A'].second;
	cout << "50 50" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << ans[i][j];
		cout << endl;
	}
	return 0;
}