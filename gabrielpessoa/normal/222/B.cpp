#include <bits/stdc++.h>
using namespace std;

int matrix[1005][1005];
int row[1005];
int col[1005];

int main() {
	int n, m, k, x, y;
	char s[5];
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		row[i] = i -1;
	}
	for(int i = 1; i <= m; i++) {
		col[i] = i -1;
	}
	for(int i = 0; i < k; i++) {
		scanf("%s %d %d", s, &x, &y);
		if(s[0] == 'c') {
			swap(col[x], col[y]);
		} else if(s[0] == 'r') {
			swap(row[x], row[y]);
		} else {
			printf("%d\n", matrix[row[x]][col[y]]);
		}
	}
	
	
	return 0;
}