#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <bool> tf(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		tf[u - 1] = true;
		tf[v - 1] = true;
	}
	int i = 0;
	while (tf[i])
		i++;
	cout << n - 1 << endl;
	for (int j = 0; j < n; j++)
		if (j != i)
			cout << i + 1 << " " << j + 1 << endl;
	
	return 0;
}