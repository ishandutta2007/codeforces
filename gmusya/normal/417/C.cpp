#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	if (n < 2 * k + 1) {
		cout << "-1";
		return 0;
	}
	vector <vector <int>> g(n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j <= i + k; j++) 
			g[i].push_back(j % n);
	cout << n * k << endl;
	for (int i = 0; i < n; i++)
		for (int j : g[i])
			cout << i + 1 << " " << j + 1 << endl;
	return 0;
}