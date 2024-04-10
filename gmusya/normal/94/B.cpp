#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <vector <bool>> tf(5);
	for (int i = 0; i < 5; i++)
		tf[i].resize(5);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		tf[u][v] = true;
		tf[v][u] = true;
	}
	bool ans = false;
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 4; j++)
			for (int y = j + 1; y < 5; y++)
				if (tf[i][j] == tf[i][y] && tf[i][y] == tf[j][y])
					ans = true;
	if (ans)
		cout << "WIN";
	else
		cout << "FAIL";
	return 0;
}