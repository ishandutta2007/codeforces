#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<string> v(4, string(n, '.'));
	if (k % 2 == 0) {
		for (int i = 0; i < k/2; i++) {
			v[1][i+1] = v[2][i+1] = '#';
		}
	} else {
		v[1][n/2] = '#';
		for (int i = 0; i < k/2; i++) {
			for (int j = 0; j < k/2; j++) {
				int x = 1 + j%2, y = j/2 + 1;
				v[x][y] = v[x][n-y-1] = '#';
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < 4; i++) {
		cout << v[i] << endl;
	}
	return 0;
}