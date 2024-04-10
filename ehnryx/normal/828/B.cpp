#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, n;
	int left, right, up, down, side, black;
	string s;
	cin >> m >> n;
	black = 0;
	up = m;
	left = n;
	down = right = -1;
	for (int i = 0; i < m; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'B') {
				black++;
				down = max(down, i);
				up = min(up, i);
				left = min(left, j);
				right = max(right, j);
			}
		}
	}
	side = max(down-up+1, right-left+1);
	if (down < up && right < left)
		cout << 1 << endl;
	else if (side > m || side > n)
		cout << -1 << endl;
	else
		cout << side*side - black << endl;
	return 0;
}