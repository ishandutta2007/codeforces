#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
int fa[2010], in[2010], vis[2010], dp[2010];
vector <int> from[2010];
queue <int> q;

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n + m; i++){
		fa[i] = i;
	}
	for (int i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] == '=') fa[find(i)] = find(j + n);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (a[i][j] == '<') from[find(i)].push_back(find(j + n)), in[find(j + n)]++;
			if (a[i][j] == '>') from[find(j + n)].push_back(find(i)), in[find(i)]++;
		}
	}
	for (int i = 0; i < n + m; i++){
		if (in[find(i)] == 0) q.push(i), dp[i] = 1;
	}
	while (!q.empty()){
		int x = q.front(); q.pop();
		for (int i = 0; i < from[x].size(); i++){
			int v = from[x][i];
			in[v]--, dp[v] = max(dp[v], dp[x] + 1);
			if (in[v] == 0) q.push(v);
		}
	}
	for (int i = 0; i < n + m; i++){
		if (in[find(i)]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 0; i < n + m; i++){
		if (i == n) printf("\n");
		printf("%d ", dp[find(i)]);
	}
	printf("\n");
	return 0;
}