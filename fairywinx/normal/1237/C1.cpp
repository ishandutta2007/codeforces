#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <vector <long long>> a(n, vector<long long>(4));
	for (int i = 0; i < n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i][3] == 1) continue;
		long long mn = 1e18, mn_j = 0;
		for (int j = i + 1; j < n; ++j) {
			if (a[j][3] == 1) continue;
			long long z = (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (a[i][2] - a[j][2]);
			if (z < mn) {
				mn = z;
				mn_j = j;
			}
		}
		cout << i + 1 << ' ' << mn_j + 1 << '\n';
		a[i][3] = 1, a[mn_j][3] = 1;
	}
}