#include <iostream>
#include <vector>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, w;
	cin >> n >> w;
	vector <vector <char>> a(n);
	for (int i = 0; i < n; i++)
		a[i].resize(w);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < w; j++)
			cin >> a[i][j];

	vector <vector <int>> m(n - 1);
	if (n > 1) {
		for (int i = 0; i < n - 1; i++)
			m[i].resize(w);
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < w; j++)
				m[i][j] = (a[i][j] == '.' && a[i + 1][j] == '.');
	}
	vector <vector <int>> q(n);
	if (w > 1) {
		for (int i = 0; i < n; i++)
			q[i].resize(w - 1);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < w - 1; j++)
				q[i][j] = (a[i][j] == '.' && a[i][j + 1] == '.');
	}
	vector <vector <int>> summ(n - 1);
	if (n > 1) {
		for (int i = 0; i < n - 1; i++)
			summ[i].resize(w);
		summ[0][0] = m[0][0];
		for (int i = 1; i < n - 1; i++)
			summ[i][0] = summ[i - 1][0] + m[i][0];
		for (int i = 1; i < w; i++)
			summ[0][i] = summ[0][i - 1] + m[0][i];
		for (int i = 1; i < n - 1; i++)
			for (int j = 1; j < w; j++)
				summ[i][j] = summ[i - 1][j] + summ[i][j - 1] - summ[i - 1][j - 1] + m[i][j];
	}
	vector <vector <int>> sumq(n);
	if (w > 1) {
		for (int i = 0; i < n; i++)
			sumq[i].resize(w - 1);
		sumq[0][0] = q[0][0];
		for (int i = 1; i < n; i++)
			sumq[i][0] = sumq[i - 1][0] + q[i][0];
		for (int i = 1; i < w - 1; i++)
			sumq[0][i] = sumq[0][i - 1] + q[0][i];
		for (int i = 1; i < n; i++)
			for (int j = 1; j < w - 1; j++)
				sumq[i][j] = sumq[i - 1][j] + sumq[i][j - 1] - sumq[i - 1][j - 1] + q[i][j];
	}
	vector <int> answer;
	int t;
	cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		x2--;
		int ans = 0;
		if (n > 1) {
			if (x1 <= x2 && y1 <= y2) {
				if (y1 == 0 && x1 == 0)
					ans += summ[x2][y2];
				if (y1 == 0 && x1 != 0)
					ans += summ[x2][y2] - summ[x1 - 1][y2];
				if (y1 != 0 && x1 == 0)
					ans += summ[x2][y2] - summ[x2][y1 - 1];
				if (y1 != 0 && x1 != 0)
					ans += summ[x2][y2] - summ[x1 - 1][y2] - summ[x2][y1 - 1] + summ[x1 - 1][y1 - 1];
			}
		}
		x2++;
		y2--;
		if (w > 1) {
			if (x1 <= x2 && y1 <= y2) {
				if (y1 == 0 && x1 == 0)
					ans += sumq[x2][y2];
				if (y1 == 0 && x1 != 0)
					ans += sumq[x2][y2] - sumq[x1 - 1][y2];
				if (y1 != 0 && x1 == 0)
					ans += sumq[x2][y2] - sumq[x2][y1 - 1];
				if (y1 != 0 && x1 != 0)
					ans += sumq[x2][y2] - sumq[x1 - 1][y2] - sumq[x2][y1 - 1] + sumq[x1 - 1][y1 - 1];
			}
		}
		answer.push_back(ans);
	}
	for (auto now : answer)
		cout << now << '\n';
	return 0;
}