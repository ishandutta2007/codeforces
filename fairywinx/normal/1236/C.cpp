#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			for (int j = 0; j < n; ++j) {
				a[j][i] = i * n + j + 1;
			}
		}
		else {
			for (int j = n - 1; j >= 0; --j) {
				a[n - 1 - j][i] = i * n + j + 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}