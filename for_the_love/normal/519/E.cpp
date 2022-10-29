#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, LL> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int f[N][20], sum[N], dep[N], n;
vector <int> e[N];
void Dfs(int x, int par){
	f[x][0] = par;
	sum[x] = 1;
	dep[x] = dep[par] + 1;
	for (int i = 0; i < e[x].size(); i++)
	if (e[x][i] != par){
		Dfs(e[x][i], x);
		sum[x] += sum[e[x][i]];
	}
}
void Pre_LCA(){
	for (int i = 1; i < 20; i++)
	for (int j = 1; j <= n; j++)
		f[j][i] = f[f[j][i - 1]][i - 1];
}
int LCA(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	int t = dep[x] - dep[y];
	for (int i = 0; i < 20; i++)
	if (t >> i & 1) x = f[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
	if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
int Get(int x, int t){
	for (int i = 0; i < 20; i++)
	if (t >> i & 1) x = f[x][i];
	return x;
}
int main(){
	int m, x, y;
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		scanf("%d%d", &x, &y);
		e[x].PB(y);
		e[y].PB(x);
	}
	Dfs(1, 0);
	Pre_LCA();
	scanf("%d", &m);
	while (m--){
		scanf("%d%d", &x, &y);
		if (x == y){
			printf("%d\n", n);
			continue;
		}
		if (dep[x] < dep[y]) swap(x, y);
		int t = LCA(x, y);
		int dis = (dep[x] - dep[t] + dep[y] - dep[t]);
		if (dis & 1){
			puts("0");
			continue;
		}
		if (t == y){
			t = Get(x, dis / 2);
			printf("%d\n", sum[t] - sum[Get(x, dis / 2 - 1)]);
		}else{
			if (dep[x] == dep[y]){
				t = Get(x, dis / 2);
				printf("%d\n", sum[t] - sum[Get(x, dis / 2 - 1)] - sum[Get(y, dis / 2 - 1)] + n - sum[t]);
				continue;
			}
			t = Get(x, dis / 2);
			printf("%d\n", sum[t] - sum[Get(x, dis / 2 - 1)]);
		}
	}
}