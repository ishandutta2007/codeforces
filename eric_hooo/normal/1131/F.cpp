#include <bits/stdc++.h>
using namespace std;

vector <int> from[300010];
int tot, n;
int fa[300010];

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void print(int x){
	if (x <= n){
		printf("%d ", x);
		return ;
	}
	for (int i = 0; i < from[x].size(); i++){
		print(from[x][i]);
	}
	return ;
}

int main(){
	scanf("%d", &n);
	tot = n + 1;
	for (int i = 1; i <= 2 * n; i++){
		fa[i] = i;
	}
	for (int i = 1; i < n; i++){
		int x, y; scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		int now = tot++;
		from[now].push_back(x), from[now].push_back(y);
		fa[x] = now, fa[y] = now;
	}
	print(tot - 1), printf("\n");
	return 0;
}