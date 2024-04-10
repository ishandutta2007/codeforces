#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector <vector <int>> arr(n, vector <int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	vector <int> x(n), y(m);
	for (int i = 0; i < n; i++)
		x[i] = i;
	for (int i = 0; i < m; i++)
		y[i] = i;
	while (q--) {
		char c;
		int x1, y1;
		cin >> c >> x1 >> y1;
		x1--;
		y1--;
		if (c == 'g')
			cout << arr[x[x1]][y[y1]] << endl;
		if (c == 'c')
			swap(y[x1], y[y1]);
		if (c == 'r')
			swap(x[x1], x[y1]);
	}
	return 0;
}