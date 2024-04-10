#include <bits/stdc++.h>
using namespace std;

int amountCellRow[55];
pair<int, int> pos[2550];
int mat[55][55];
pair<pair<int, int>, pair<int, int> > swaps[2550];

int main() {
	int t, n, total = 0, x = 1, y = 0, amountSwaps = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> amountCellRow[i];
		total += amountCellRow[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= amountCellRow[i]; j++) {
			cin >> mat[i][j];
			pos[mat[i][j]] = make_pair(i, j);
			//printf("DBG: %d %d %d\n", mat[i][j], i, j);
		}
	}
	for(int i = 1; i <= total; i++) {
		if(++y > amountCellRow[x]) {
			y = 1;
			x++;
		}
		if(pos[i].first == x && pos[i].second == y) {
			continue;
		}
		swaps[amountSwaps++] = make_pair(pos[i], make_pair(x, y));
		int temp = mat[x][y];
		swap(mat[x][y], mat[pos[i].first][pos[i].second]);
		swap(pos[i], pos[temp]);
		//printf("%d %d %d %d\n", pos[6].first, pos[6].second, x, y);
	}
	printf("%d\n", amountSwaps);
	for(int i = 0; i < amountSwaps; i++) {
		printf("%d %d %d %d\n", swaps[i].second.first, swaps[i].second.second, swaps[i].first.first, swaps[i].first.second);
	}
	return 0;
}