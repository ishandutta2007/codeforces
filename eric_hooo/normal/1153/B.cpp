#include <bits/stdc++.h>
using namespace std;

int row[110], col[110];
int a[110][110];

int main(){
	int n, m, h;
	scanf("%d%d%d", &n, &m, &h);
	for (int i = 0; i < m; i++){
		scanf("%d", &col[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%d", &row[i]);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j]) printf("%d ", min(row[i], col[j]));
			else printf("0 ");
		}
		printf("\n");
	}
	return 0;
}