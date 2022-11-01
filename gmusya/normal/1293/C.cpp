#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	int cnt = 0;
	vector <vector <bool>> tf(n, vector <bool>(2));
	while (q--) {
		int x, y;
		cin >> y >> x;
		x--;
		y--;
		if (tf[x][y]) {
			if (tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y]))
				cnt--;
			tf[x][y] = !tf[x][y];
			int glob_x = x;
			int glob_y = y;
			y = 1 - y;
			x = glob_x - 1;
			if (x >= 0 && tf[x][y] && !(tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y])))
				cnt--;
			x = glob_x;
			if (x >= 0 && tf[x][y] && !(tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y])))
				cnt--;
			x = glob_x + 1;
			if (x < n && tf[x][y] && !(tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y])))
				cnt--;
		}
		else {
			if (tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y]))
				cnt++;
			int glob_x = x;
			int glob_y = y;
			y = 1 - y;
			x = glob_x - 1;
			if (x >= 0 && tf[x][y] && !(tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y])))
				cnt++;
			x = glob_x;
			if (x >= 0 && tf[x][y] && !(tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y])))
				cnt++;
			x = glob_x + 1;
			if (x < n && tf[x][y] && !(tf[x][1 - y] || (x - 1 >= 0 && tf[x - 1][1 - y]) || (x + 1 < n && tf[x + 1][1 - y])))
				cnt++;
			tf[glob_x][glob_y] = !tf[glob_x][glob_y];
		}
		if (cnt == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}