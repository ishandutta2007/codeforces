#include <bits/stdc++.h>
using namespace std;

int fa[40000];
int ans;

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	if (x > y) swap(x, y);
	fa[x] = y, ans--;
}

char buf[5000];
int la[20000];
int a[20000];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int j = 0; j < m; j++) {
		fa[j + m] = j + m;
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < m / 4; j++) {
			int x = buf[j] >= '0' && buf[j] <= '9' ? buf[j] - '0' : buf[j] - 'A' + 10;
			for (int k = 0; k < 4; k++) {
				ans += (a[j << 2 | k] = x >> 3 - k & 1);
			}
		}
		for (int j = 0; j < m; j++) {
			fa[j] = fa[m + j] - m;
			fa[m + j] = m + j;
		}
		for (int j = 0; j < m; j++) {
			if (!a[j]) continue;
			int k = j; while (k < m && a[k]) merge(m + j, m + k), k++;
			j = k - 1;
		}
		for (int j = 0; j < m; j++) {
			if (a[j] && la[j]) merge(j, m + j);
		}
		for (int j = 0; j < m; j++) {
			la[j] = a[j];
		}
	}
	printf("%d\n", ans);
	return 0;
}