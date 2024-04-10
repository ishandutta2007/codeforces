#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, q; cin >> n >> m >> q;
	vector< vector<int> > mat(n, vector<int>(m));
	vector<int> lineVal(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	
	auto recalcLine = [&](int ln) {
		lineVal[ln] = 0;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (mat[ln][j]) {
				cnt++;
			} else {
				cnt = 0;
			}
			lineVal[ln] = max(lineVal[ln], cnt);
		}
	};
	
	for (int i = 0; i < n; i++) {
		recalcLine(i);
	}
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y; x--; y--;
		mat[x][y] ^= 1;
		recalcLine(x);
		int ans = 0;
		for (int j = 0; j < n; j++){
			ans = max(ans, lineVal[j]);
		}
		cout << ans << "\n";
	}
	return 0;
}