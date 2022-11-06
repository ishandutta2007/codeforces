#include<bits/stdc++.h>
using namespace std;
using LL = long long;

random_device rds;
const int seed = rds();
mt19937 rd(seed);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	vector a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		cin >> a[i][i];
	}
	for (int d = 2; d < n; d++) {
		for (int j = 0; j + d < n; j++) {
			a[j][j + d] = ((a[j][j + d - 1] - a[j + 1][j + d - 1] + a[j + 1][j + d] - 1) % n + n) % n;
		}
	}
	for (int d = 1; d < n; d++) {
		for (int j = 0; j + d < n; j++) {
			a[j + d][j] = ((a[j + d - 1][j] - a[j + d - 1][j + 1] + a[j + d][j + 1] - 1) % n + n) % n;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%c", a[i][j], " \n"[j == n - 1]);
		}
	}
    return 0;
}