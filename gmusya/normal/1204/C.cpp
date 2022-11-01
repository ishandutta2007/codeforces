#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <vector <int>> a(n, vector <int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '0')
				a[i][j] = INF;
			else
				a[i][j] = 1;
			if (i == j)
				a[i][j] = 0;
		}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	int m;
	cin >> m;
	vector <int> p(m);
	for (int i = 0; i < m; i++)
		cin >> p[i];
	vector <int> path;
	path.push_back(p[0]);
	int pos = 0;
	for (int i = 1; i < m; i++)
		if (a[p[pos] - 1][p[i] - 1] < i - pos) {
			path.push_back(p[i - 1]);
			pos = i - 1;
		}
	path.push_back(p[m - 1]);
	cout << path.size() << endl;
	for (int u : path)
		cout << u << " ";
	return 0;
}