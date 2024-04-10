#include <cstdio>
#include <cstring>
#include <algorithm>

int n, m;
char matrix[1005][1005];

int check(int i, int j) {
	if (i<=0||j<=0||i>n-2||j>m-2) return 0;
	for (int x=i;x<=i+2;++x) {
		for (int y=j;y<=j+2;++y) {
			if (x==i+1&&y==j+1) continue;
			if (matrix[x][y]!='#') return 0;
		}
	}return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i=1;i<=n;++i) {
		scanf("%s", &matrix[i]);
		for (int j=m;j>=1;j--) matrix[i][j]=matrix[i][j-1];
	} for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			if (matrix[i][j]=='#') {
				int flag=0;
				for (int x=i-2;x<=i;++x) {
					for (int y=j-2;y<=j;++y) {
						if (x==i-1&&y==j-1) continue;
						if (check(x, y)) {
							//printf("%d %d->%d %d\n", i, j, x, y);
							flag=1; break;
						}
					}
				}if (flag==0) {
					printf("NO");
					return 0;
				}
			}
		}
	}printf("YES");
}