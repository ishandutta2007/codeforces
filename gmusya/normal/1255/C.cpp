#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> a, b;
vector <bool> used;
int n;

int main() {
	cin >> n;
	n -= 2;
	a.resize(n);
	for (int i = 0; i < n; i++)
		a[i].resize(3);
	b.resize(n + 3);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			b[a[i][j]].push_back(i);

	used.resize(n + 3);


	int num, x, y, z;
	for (int i = 1; i <= n + 2; i++) {
		if (b[i].size() == 1) {
			num = b[i][0];
			break;
		}
	}

	for (int i = 0; i < 3; i++) {
		if (b[a[num][i]].size() == 1)
			x = a[num][i];
		if (b[a[num][i]].size() == 2)
			y = a[num][i];
		if (b[a[num][i]].size() == 3)
			z = a[num][i];
	}

	cout << x << " " << y << " " << z << " ";

	used[x] = true;
	used[y] = true;
	used[z] = true;

	int m = 1;
	while (m < n) {
		x = y;
		y = z;
		for (int i = 0; i < b[x].size(); i++)
			for (int j = 0; j < b[y].size(); j++)
				if (b[y][j] == b[x][i]) {
					int r = b[y][j];
					for (int u = 0; u < a[r].size(); u++)
						if (!used[a[r][u]]) {
							z = a[r][u];
							break;
						}
				}
		used[z] = true;
		cout << z << " ";
		m++;
	}

	return 0;
}