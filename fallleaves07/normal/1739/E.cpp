#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int inf = 0x3f3f3f3f;

void upd(int &v, int val) {
	v = max(v, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<array<int, 2>> dir(n + 2);
	for (int i = 0; i < n; i++) {
		dir[i][0] = s[i] - '0';
		dir[i][1] = t[i] - '0';
	}
	dir[n][0] = dir[n][1] = 0;
	dir[n + 1][0] = dir[n + 1][1] = 0;
	vector f(n + 2, array<array<int, 2>, 2>{0});
	for (auto &i : f) {
		for (auto &j : i) {
			j.fill(-inf);
		}
	}
	f[0][dir[0][1]][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				if (f[i - 1][j][k] >= 0) {
					if (j && dir[i][k]) {
						upd(f[i][dir[i][k ^ 1]][k], f[i - 1][j][k] + 1);
						upd(f[i][0][k ^ 1], f[i - 1][j][k] + 1 + dir[i][k ^ 1]);
					} else {
						if (j) {
							upd(f[i][dir[i][k]][k ^ 1], f[i - 1][j][k] + 1 + dir[i][k ^ 1]);
							upd(f[i][dir[i][k ^ 1]][k], f[i - 1][j][k] + dir[i][k]);
						} else {
							upd(f[i][dir[i][k ^ 1]][k], f[i - 1][j][k] + dir[i][k]);
						}
					}
				}
			}
		}
	}
	int ans = max(f[n][0][0], f[n][0][1]);
	printf("%d\n", ans);
    return 0;
}