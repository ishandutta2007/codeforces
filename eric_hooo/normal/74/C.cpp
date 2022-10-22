#include <bits/stdc++.h>
using namespace std;

int fa[4000010];
int n, m;

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

void merge(int x, int y){
	fa[find(x)] = find(y);
}

int id(int x, int y){
	if (x == 0) return y;
	if (y == m - 1) return m + x - 1;
	if (x == n - 1) return m + n - 1 + (m - y - 2);
	if (y == 0) return m + n - 1 + m - 1 + (n - x - 2);
	return -23333;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= id(1, 0); i++){
		fa[i] = i;
	}
	vector <int> v;
	for (int i = 0; i < m; i++){
		int x, y, xx, yy;
		x = 0, y = i;
		xx = x + min(n - x - 1, m - y - 1), yy = y + min(n - x - 1, m - y - 1);
		merge(id(x, y), id(xx, yy));
		xx = x + min(n - x - 1, y), yy = y - min(n - x - 1, y);
		merge(id(x, y), id(xx, yy));
		x = n - 1, y = i;
		xx = x - min(x, m - y - 1), yy = y + min(x, m - y - 1);
		merge(id(x, y), id(xx, yy));
		xx = x - min(x, y), yy = y - min(x, y);
		merge(id(x, y), id(xx, yy));
	}
	for (int i = 0; i < n; i++){
		int x, y, xx, yy;
		x = i, y = 0;
		xx = x + min(n - x - 1, m - y - 1), yy = y + min(n - x - 1, m - y - 1);
		merge(id(x, y), id(xx, yy));
		xx = x - min(x, m - y - 1), yy = y + min(x, m - y - 1);
		merge(id(x, y), id(xx, yy));
		x = i, y = m - 1;
		xx = x + min(n - x - 1, y), yy = y - min(n - x - 1, y);
		merge(id(x, y), id(xx, yy));
		xx = x - min(x, y), yy = y - min(x, y);
	}
	int ans = 0;
	for (int i = 0; i <= id(1, 0); i++){
		if (find(i) == i) ans++;
	}
	printf("%d\n", ans);
	return 0;
}